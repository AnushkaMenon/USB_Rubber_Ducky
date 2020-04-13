#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  // lock screen every two minutes
  DigiKeyboard.delay(120000);

  // keyboard shortcut to lock screen: Windows Key + L
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
}
