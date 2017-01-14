/*
  Hello Counter
  Shows numbers from 0 to 9 on a seven segment display.

  Materials:
  * a seven segment display (both common anode and common cathode are ok)
  * 7 resistors (220 Ohm to 470 Ohm are ok)
  Connect the segment pins to Arduino ones, from Digital2 to Digital8.
  More info about connections are shown in README at
  https://github.com/GLGPrograms/SevSeg

  This example code is published with CC-BY-SA license.

  modified 2 Jun 2016
  by GLG Programs - www.glgprograms.it
 */


#include <SevSeg.h>

// Make a new seven segment display object, specifying segment pins and
// if is common anode or common cathode

// SevSeg display(2,3,4,5,6,7,8, COMMON_CATHODE);
SevSeg display(2,3,4,5,6,7,8, COMMON_ANODE);

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
