#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

boolean finished = false;

void loop() {
  // put your main code here, to run repeatedly:
  if (!finished) {
    DigiKeyboard.sendKeyStroke(0);
  
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  
    DigiKeyboard.delay(1000);
  
    DigiKeyboard.print("terminal");
  
    DigiKeyboard.delay(1000);
  
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    finished = true;
  }
}
