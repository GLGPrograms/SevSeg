#include "SevSeg.h"

// Constructors
SevSeg::SevSeg( byte a, byte b, byte c, byte d, byte e, byte f, byte g, boolean _commonAnode ) {
    commonAnode = _commonAnode;
    dotpoint = false;
    shiftRegister = false;

    pinArray = new byte[7];
    pinArray[0] = a;
    pinArray[1] = b;
    pinArray[2] = c;
    pinArray[3] = d;
    pinArray[4] = e;
    pinArray[5] = f;
    pinArray[6] = g;
    
    for (byte set=0; set<7; set++){
        pinMode(pinArray[set], OUTPUT);
    }
}

SevSeg::SevSeg( byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte dp, boolean _commonAnode ) {
    commonAnode = _commonAnode;
    dotpoint = true;
    shiftRegister = false;

    pinArray = new byte[8];
    pinArray[0] = a;
    pinArray[1] = b;
    pinArray[2] = c;
    pinArray[3] = d;
    pinArray[4] = e;
    pinArray[5] = f;
    pinArray[6] = g;
    pinArray[7] = dp;
    
    for (byte set=0; set<8; set++){
        pinMode(pinArray[set], OUTPUT);
    }
}

SevSeg::SevSeg( byte clock, byte latch, byte data, boolean _commonAnode, byte _numDisplays) {
    commonAnode = _commonAnode;
    shiftRegister = true;
    // When you use shift register, DP is true
    if( _numDisplays > TOT )
		numDisplays = 1;
	else
		numDisplays = _numDisplays;
	// Create display buffer
	displayBuffer = new byte[numDisplays];
	for( i = 0; i < numDisplays; i++ )
		displayBuffer[i] = 0;
    
    pinArray = new byte[3];
    pinArray[_CLOCK_PIN] = clock;
    pinArray[_LATCH_PIN] = latch;
    pinArray[_DATA_PIN] = data;
    
    for (byte set=0; set<3; set++)
        pinMode(pinArray[set], OUTPUT);

}


// Prints the number
void SevSeg::print(byte number, byte base) {
	for( byte a = 0; a < numDisplays; a++ ) {
		// con questa stampiamo a diritto allineando a destra magari
		// mentre con la write permettiamo di scegliere su quale display
		// scrivere. sennò non possiamo passare entrambi i parametri:
		// sia byte qualeDisplay sia byte base.
	}
    
    writeBuffer();
}

/**
// Prints a float number with fixed decimal places
void SevSeg::print(float number, byte decimals = 1) {

}
**/

// Clear the display
void SevSeg::clear() {
	for( byte i = 0; i < numDisplays; i++ )
		displayBuffer[i] = 0;
	
	writeBuffer();
}

// Deallocates the dynamic data
SevSeg::~SevSeg() {
    delete[] pinArray;
    delete[] displayBuffer;
}


// LOW level write buffer
void SevSeg::writeBuffer() {
	for( a = 0; a < numDisplays; a++ ) {	// Sweeps the displayBuffer
		byte dataTmp = displayBuffer[a];			// Pick the a-th display data
		if( ! shiftRegister ) {
			// Print the number...
			for (byte c = 0; c < 7; c++, dataTmp >>= 1) {
				digitalWrite(pinArray[c], commonAnode ? !(dataTmp & 0x01) : dataTmp & 0x01);
			}
			// ...and the dot point if enabled
			if (dotpoint == true)
				digitalWrite(pinArray[7], !commonAnode ^ (dataTmp >> 7) );	// dotpoint is the 8th bit of the byte
		}
		else {
			digitalWrite(pinArray[_LATCH_PIN], LOW);
			shiftOut(pinArray[_DATA_PIN], pinArray[_CLOCK_PIN], MSBFIRST, commonAnode ? ~dataTmp : dataTmp;
			digitalWrite(pinArray[_LATCH_PIN], HIGH);
		}
	}
}
