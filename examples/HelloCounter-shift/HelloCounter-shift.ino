/*
  Hello Counter
  Shows numbers from 0 to 9 on a seven segment display.

  Materials:
  * a seven segment display (both common anode and common cathode are ok)
  * a shift register IC (like 74HC595)
  * 7 resistors (220 Ohm to 470 Ohm are ok)
  Connect the segment pins to shift register output, then
  clock, latch and data signals respectively to Digital 8, 9 and 10 on
  Arduino. These pins can be changed.
  More info about connections are shown in README at
  https://github.com/GLGPrograms/SevSeg

  This example code is published with CC-BY-SA license.

  modified 2 Jun 2016
  by GLG Programs - www.glgprograms.it
 */


#include <SevSeg.h>

// Make a new seven segment display object, specifying clock, latch and
// data pins and if the display is common anode or common cathode

// SevSeg display(8,9,10, COMMON_CATHODE);
SevSeg display(8,9,10, COMMON_ANODE);

void setup(){
   // nothing to do here...
}

void loop()
{
  for (byte i = 0; i <= 9; i++){
    display.print(i); // shows digits between 0 and 9
    delay(1000);
  }
}
