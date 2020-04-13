#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

boolean finished = false;

void loop() {
  // put your main code here, to run repeatedly:
  if (!finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(500);

    // opening the terminal
    // keyboard shortcut for opening the run window is Windows Key + R
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    // add a delay to ensure that the window has opened before
    //  we type more
    DigiKeyboard.delay(2000);
    DigiKeyboard.print("cmd");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // change to Desktop
    DigiKeyboard.print("cd Desktop");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // echo a message to 'hi.txt'
    DigiKeyboard.print("echo hello %username% - you have been hacked!!! > hi.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // open hi.txt
    DigiKeyboard.print("hi.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);

    for (int i = 0; i < 20; i++) {
      DigiKeyboard.sendKeyStroke(46, MOD_CONTROL_LEFT);
      DigiKeyboard.delay(250);
    }

    finished = true;
  }
}
