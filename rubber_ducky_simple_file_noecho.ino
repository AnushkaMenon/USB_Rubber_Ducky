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
    DigiKeyboard.delay(500);
    DigiKeyboard.print("terminal");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // stop echoing commands to terminal to hide what
    //  we're typing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("clear");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // change to Desktop
    DigiKeyboard.print("cd ~/Desktop");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // echo a message to 'hello.txt'
    DigiKeyboard.print("echo ");
    // can't type a " inside print statement, so use code instead
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print("hello! ! ! ");

    // closing quotation mark
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print(" > hello.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    //DigiKeyboard.print("hello!!! ");
    // re-enable echoing
    DigiKeyboard.print("stty echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // keyboard shortcut to close terminal window (cmd + w)
    DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);
    // keyboard shortcut to quit terminal (cmd + q)
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);

    finished = true;
  }
}
