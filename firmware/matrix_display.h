#ifndef _MATRIX_DISPLAY_H_
#define _MATRIX_DISPLAY_H_

#include <mbed.h>
#include "matrix_text.h"

#define MODULE  4   //module 16x16
#define ROW     16  //fix
#define DISPLAY 5
#define NUM     50	// MAX string length

class MatrixDisplay {
public:
	MatrixDisplay(Ticker& tickerSync, Ticker& tickerRoll, Ticker& tickerRollStrings, DigitalOut& _OCA, DigitalOut& _OCB, DigitalOut& _OCC, DigitalOut& _OCD, DigitalOut& _OCE, DigitalOut& _ST, DigitalOut& _SH, DigitalOut& _DS);
	~MatrixDisplay();
	
	void setHSync(unsigned char  hSync = 85);	
	void setDisplayRollingTime(float_t rolltime = 0.1);
	
	void setPixel( int x, int y );
	void clearPixel( int x, int y );
	void clearDisplay();
	unsigned int setVietnameseString(unsigned char x, char *str);
	
	void refreshDisplay();
	void refreshDisplayRow(void);
	
	void setRollString(bool on) 
	{
		_isRoll = on;
	}
	
	void rollString();
	void rollStrings();
	void rollDisplay();
	
	bool isEndRollDisplay() {
		return _isEndRoll;
	}
	
	void startDisplay();
	
private:	
	unsigned int matrix_puts_vni(unsigned char x, char *str);
	int matrix_putchar(int x, char k);
	void matrix_puts(int x, char *str);
	
	int matrix_write_char(int x, int xo, int lent);
	int matrix_write_char_(int x, int xo, int lent);
	
	void write(int a, int b, int row);
	void write_row(int row);
	void display_matrix_long( unsigned int l );
	static inline void _nop_( void );
	
	
private:
	DigitalOut& OCA;
	DigitalOut& OCB;
	DigitalOut& OCC;
	DigitalOut& OCD;
	DigitalOut& OCE;

	DigitalOut& ST;   //RCK
	DigitalOut& SH;   //SCK
	DigitalOut& DS;   //SEG
	
	Ticker& hSyncTicker;
	Ticker& tickerRoll;
	Ticker& tickerRollStrings; // roll default strings
	
	unsigned char fill_matrix[(MODULE*ROW*DISPLAY)][2];
	unsigned char fill_matrix_swap[(MODULE*ROW)][2];
	unsigned int g_len_text, g_l= 0;
	unsigned char g_display_row = 0;
	char*    		g_string  = 0;
	bool 		_isRoll = false;
	bool 		_isRollDisplay = false;
	bool 		_isEndRoll = false;
	bool 		_isDisplayStarted = false;
	bool		_isDefaultDisplay = true;
	unsigned char _hSync = 120;
	float_t		_rollTimer = 0.2;
	
};

#endif // _MATRIX_DISPLAY_H_
