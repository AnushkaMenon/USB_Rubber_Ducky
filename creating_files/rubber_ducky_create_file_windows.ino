#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

boolean finished = false;

void loop() {
  // put your main code here, to run repeatedly:
  if (!finished) {
    DigiKeyboard.sendKeyStroke(0);

    // opening the terminal
    // keyboard shortcut for opening the run window is Windows Key + R
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    // add a delay to ensure that the window has opened before
    //  we type more
    DigiKeyboard.delay(1500);
    DigiKeyboard.print("cmd");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // change to Desktop
    DigiKeyboard.print("cd Desktop");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // echo a message to 'hi.txt'
    DigiKeyboard.print("echo hello!!! > hi.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    
    // keyboard shortcut to close the cmd window (ALT + F4)
    DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);

    finished = true;
  }
}
