#include "mbed.h"
#include "ble/BLE.h"
#include "ble/services/UARTService.h"
#include "matrix_display.h"
#include "matrix_control_service.h"


Ticker hSyncTicker;
Ticker tickerRoll;
Ticker tickerRollStrings;

DigitalOut OCA(P0_9);
DigitalOut OCB(P0_16);
DigitalOut OCC(P0_17);
DigitalOut OCD(P0_18);
DigitalOut OCE(P0_19);

DigitalOut ST(P0_21);   //RCK
DigitalOut SH(P0_22);   //SCK
DigitalOut DS(P0_23);   //SEG

MatrixDisplay display(hSyncTicker, tickerRoll, tickerRollStrings, OCA, OCB, OCC, OCD, OCE, ST, SH, DS);


BLEDevice  ble;
UARTService *uartServicePtr;

MatrixControlService * controlSvcPtr;

#define NUM     50
char    g_string[NUM];
uint8_t temp;

// debug led
DigitalOut LED(P0_7);


/////////////////////////////////////
///// use (for reciever data) ///////
/////////////////////////////////////
void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
{
    ble.startAdvertising();
}

void onDataWritten(const GattWriteCallbackParams *params)
{
	if (uartServicePtr == NULL)
		return;
	
	// uart read
    if (params->handle == uartServicePtr->getTXCharacteristicHandle()) 
    {
		unsigned char l;
        uint16_t bytesRead = params->len;
        
        //Process
        for(l=0; l<bytesRead; l++) {
            g_string[l] = params->data[l];
        }
        
        display.clearDisplay();
        display.setVietnameseString(0, g_string);
        
        memset(g_string, 0, NUM);
    }
    
    // clear string
    if (params->handle == controlSvcPtr->getClearStringHandle()) 
    {
		display.clearDisplay();
		memset(g_string, 0, NUM);
		
		ble.updateCharacteristicValue(controlSvcPtr->getClearStringHandle(), params->data, params->len);
    }
    
    // set json mode
    if (params->handle == controlSvcPtr->getJsonModeHandle()) 
    {
		ble.updateCharacteristicValue(controlSvcPtr->getJsonModeHandle(), params->data, params->len);
    }
    
    // set scrolldelay
    if (params->handle == controlSvcPtr->getScrollDelayHandle()) 
    {
		display.setDisplayRollingTime((float) *(uint16_t*) params->data/1000);
		ble.updateCharacteristicValue(controlSvcPtr->getScrollDelayHandle(), params->data, params->len);
    }
    
    // set refresh mode
    if (params->handle == controlSvcPtr->getRefreshModeHandle()) 
    {
		display.setHSync(*(uint16_t*) params->data);
		ble.updateCharacteristicValue(controlSvcPtr->getRefreshModeHandle(), params->data, params->len);
    }
    
    
}

int main(void)
{
    wait(0.1);
    

    ble.init();
    ble.onDisconnection(disconnectionCallback);
    ble.onDataWritten(onDataWritten);

    /* setup advertising */
    ble.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED);
    ble.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
    ble.accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME,
                                     (const uint8_t *)"MATRIX_1", sizeof("MATRIX_1") - 1);
    ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS,
                                     (const uint8_t *)UARTServiceUUID_reversed, sizeof(UARTServiceUUID_reversed));

    ble.setAdvertisingInterval(200); /* 1000ms; in multiples of 0.625ms. */
    ble.startAdvertising();

    UARTService uartService(ble);
    uartServicePtr = &uartService;
    
    MatrixControlService controlSvc(ble, true, false, 200, 85);
    controlSvcPtr = &controlSvc;

    display.clearDisplay();
    memset(g_string, 0, NUM);
    strcpy(g_string, " Chu1c la1i xe an toa2n ! ");
    display.setVietnameseString(0, g_string);
    display.startDisplay();
    
    while (1)
    {
		ble.waitForEvent();
    }
}
