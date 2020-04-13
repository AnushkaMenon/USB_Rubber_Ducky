#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.sendKeyStroke(0);

  // lock screen every two minutes
  DigiKeyboard.delay(10000);

  // keyboard shortcut to lock screen: Windows Key + L
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
}
