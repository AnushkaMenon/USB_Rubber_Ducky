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
    // keyboard shortcut for spotlight is cmd + space
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    // add a delay to ensure that spotlight has opened before
    //  we type more
    DigiKeyboard.delay(1000);
    DigiKeyboard.print("terminal");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // making a file!
    DigiKeyboard.print("cd Desktop");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("vim hello.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    // enter insert mode
    DigiKeyboard.print("i");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("hello!!!");
    // no defined key for the escape key, so we have to use its ID
    DigiKeyboard.sendKeyStroke(41);
    DigiKeyboard.delay(500);
    // exit vi
    DigiKeyboard.print(":wq");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    // keyboard shortcut to close terminal window (cmd + w)
    DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);
    // keyboard shortcut to quit terminal (cmd + q)
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);

    finished = true;
  }
}
