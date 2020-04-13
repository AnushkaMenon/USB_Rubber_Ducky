#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(500);
    
    // open the Run window
    // shortcut: Windows Key + R
    // allow a delay for the window to open
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(2500);
    
    // open the Camera application
    // allow a 6 second delay for the application to oepn
    DigiKeyboard.print("microsoft.windows.camera:");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(6000);
    
    // take a picture
    // shorcut: Enter
    // allow a delay for the picture to load in the library
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(4000);

    // shortcut to open the library to see the picture we just took: press the Tab key 8 times
    for (int i = 0; i < 8; i++) {
      DigiKeyboard.sendKeyStroke(43);
      DigiKeyboard.delay(200);
    }

    // Open the library to view the picture
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    finished = true;
  }
}
