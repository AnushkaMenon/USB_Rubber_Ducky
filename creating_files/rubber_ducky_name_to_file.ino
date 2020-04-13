#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

boolean finished = false;

void loop() {
  // put your main code here, to run repeatedly:
  if (!finished) {
    DigiKeyboard.sendKeyStroke(0);

    // open terminal
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);
    DigiKeyboard.print("terminal");
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // change to Desktop
    DigiKeyboard.print("cd Desktop");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // echo a message to 'hello.txt'
    DigiKeyboard.print("echo ");
    // can't type a " inside print statement, so use code instead
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    // "id -F" gets the user's name
    DigiKeyboard.print("Hello $(id -F) - you have been hacked! ");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print(" > hello.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    // clear terminal
    DigiKeyboard.print("clear");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    // open the file in TextEdit
    DigiKeyboard.print("open -a TextEdit hello.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // hide all other windows!
    DigiKeyboard.sendKeyStroke(KEY_H, MOD_ALT_LEFT | MOD_GUI_LEFT);

    // increase font size 30 times
    for (int i = 0; i < 30; i++) {
      DigiKeyboard.sendKeyStroke(46, MOD_GUI_LEFT);   
    }

    // enter full screen
    DigiKeyboard.sendKeyStroke(KEY_F, MOD_CONTROL_LEFT | MOD_GUI_LEFT);

    //DigiKeyboard.sendKeyStroke(KEY_A, MOD_GUI_LEFT);
    //DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);
    //DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    
    finished = true;
  }
}
