#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  // put your main code here, to run repeatedly:
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(2500);
    DigiKeyboard.print("microsoft.windows.camera:");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(6000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(4000);

    for (int i = 0; i < 8; i++) {
      DigiKeyboard.sendKeyStroke(43);
      DigiKeyboard.delay(200);
    }

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    finished = true;
  }
}
