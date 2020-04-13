#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:
  DigiKeyboard.sendKeyStroke(0);

  // increase volume
  for (int i = 0; i < 3; i++) {
    DigiKeyboard.sendKeyStroke(128);
  }

  // open spotlight and open terminal
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // open the link in Chrome
  DigiKeyboard.print("open -a ");
  DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
  DigiKeyboard.print("Google Chrome");
  DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
  DigiKeyboard.print(" http://youtu.be/dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

int count = 0;

void loop() {
  // put your main code here, to run repeatedly:

  // open 20 more windows with this link!
  if (count < 20) {
    // allow for a delay so that the video can start playing
    DigiKeyboard.delay(3000);
    
    // open a new window and go to the same link
    DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
    DigiKeyboard.print("http://youtu.be/dQw4w9WgXcQ");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  
  count++;
}
