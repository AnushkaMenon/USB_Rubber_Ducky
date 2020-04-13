#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  // put your main code here, to run repeatedly:
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("Photo Booth");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_GUI_LEFT);
    DigiKeyboard.delay(6000);
    DigiKeyboard.sendKeyStroke(30, MOD_GUI_LEFT);
    finished = true;
  }
}
