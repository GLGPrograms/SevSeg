/* Seven Segment Driver Library v1.0
 * 
 * Adapted by
 * Giulio Fieramosca
 * Luca Mattii
 *    http://www.glgprograms.it
 * 
 * Originally written by
 * Alexander Brevig
 *    http://alexanderbrevig.github.io/
 * 
*/

#ifndef SevSeg_h
#define SevSeg_h

#define COMMON_CATHODE false
#define COMMON_ANODE true

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define _CLOCK_PIN 0
#define _LATCH_PIN 1
#define _DATA_PIN  2

// Array of bits corresponding to digits 0-9
// from left to right => dot point, segment g to segment a
const byte dataArray[] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b01110111, // A (10)
    0b01111100, // b (11)
    0b01011000, // c (12)
    0b01011110, // d (13)
    0b01111011, // e (14)
    0b01110001  // f (15)
};

class SevSeg {

public:
  // Direct-wiring constructor
  SevSeg (byte a, byte b, byte c, byte d, byte e, byte f, byte g, boolean _commonAnode);
  SevSeg (byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte dp, boolean _commonAnode);
  // ShiftRegister-wiring constructor
  SevSeg (byte clock, byte latch, byte data, boolean _commonAnode, byte _numDisplays);
  
  ~SevSeg();
  
  void print(byte number, boolean dotpoint_on = false);
  void clear();
    
private:
  
  // Pointer to the pins' array
  byte *pinArray;
  // Display buffer: display[0] è il più a destra
  byte *displayBuffer;
  
  boolean shiftRegister;
  boolean commonAnode;
  boolean dotpoint;
  byte numDisplays;
  
  void writeBuffer();
};

#endif
