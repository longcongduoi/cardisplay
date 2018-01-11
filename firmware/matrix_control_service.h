#ifndef __BLE_MATRIXCONTROL_SERVICE_H__
#define __BLE_MATRIXCONTROL_SERVICE_H__

class MatrixControlService {
public:
    const static uint16_t MATRIXCONTROL_SERVICE_UUID                 		= 0xA000;
    const static uint16_t MATRIXCONTROL_CLEARSTRING_CHARACTERISTIC_UUID    	= 0xA001;
    const static uint16_t MATRIXCONTROL_JSONMODE_CHARACTERISTIC_UUID   		= 0xA002;
    const static uint16_t MATRIXCONTROL_SCROLLDELAY_CHARACTERISTIC_UUID     = 0xA003;
    const static uint16_t MATRIXCONTROL_REFRESHRATE_CHARACTERISTIC_UUID     = 0xA004;
    

    MatrixControlService(BLEDevice &_ble, bool clearString, bool jsonMode, uint16_t scrollDelay, uint16_t refreshRate) :
        ble(_ble), 
        mtxClearString(MATRIXCONTROL_CLEARSTRING_CHARACTERISTIC_UUID, &clearString),
        mtxJsonMode(MATRIXCONTROL_JSONMODE_CHARACTERISTIC_UUID, &jsonMode, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY),
        mtxScrollDelay(MATRIXCONTROL_SCROLLDELAY_CHARACTERISTIC_UUID, &scrollDelay, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY),
        mtxRefreshRate(MATRIXCONTROL_REFRESHRATE_CHARACTERISTIC_UUID, &refreshRate, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY)
    {
        GattCharacteristic *charTable[] = {&mtxClearString, &mtxJsonMode, &mtxScrollDelay, &mtxRefreshRate};
        GattService         matrixControlService(MATRIXCONTROL_SERVICE_UUID, charTable, sizeof(charTable) / sizeof(GattCharacteristic *));
        ble.addService(matrixControlService);
    }

	// get handle
    uint16_t getClearStringHandle() const {
        return mtxClearString.getValueAttribute().getHandle();
    }
    
    uint16_t getJsonModeHandle() const {
        return mtxJsonMode.getValueAttribute().getHandle();
    }
    
    uint16_t getScrollDelayHandle() const {
        return mtxScrollDelay.getValueAttribute().getHandle();
    }
    
    uint16_t getRefreshModeHandle() const {
        return mtxRefreshRate.getValueAttribute().getHandle();
    }

private:
    BLEDevice                         		&ble;
    WriteOnlyGattCharacteristic<bool>  		mtxClearString;
    ReadWriteGattCharacteristic<bool>  		mtxJsonMode;	// switch to json mode
    ReadWriteGattCharacteristic<uint16_t>  	mtxScrollDelay; // ms
    ReadWriteGattCharacteristic<uint16_t>  	mtxRefreshRate; // count
};

#endif /* #ifndef __BLE_MATRIXCONTROL_SERVICE_H__ */
