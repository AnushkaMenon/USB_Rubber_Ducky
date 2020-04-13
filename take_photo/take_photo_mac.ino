#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    
    // open Spotlight
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    
    // open Photo Booth and allow a 2-second delay for the application to open
    DigiKeyboard.print("Photo Booth");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    
    // shortcut to take a photo: Command + Enter
    DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_GUI_LEFT);
    
    // taking a photo has a 3 second countdown, so allow a delay for this
    //  plus extra time to allow the photo to appear in the library
    DigiKeyboard.delay(6000);
    
    // open the photo we just took
    // shortcut: Command + 1
    DigiKeyboard.sendKeyStroke(30, MOD_GUI_LEFT);
    finished = true;
  }
}
