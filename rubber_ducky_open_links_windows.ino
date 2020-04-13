#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

  DigiKeyboard.sendKeyStroke(0);
  
  // increase volume
  for (int i = 0; i < 3; i++) {
    DigiKeyboard.sendKeyStroke(128);
    DigiKeyboard.delay(200);
  }

  // open cmd
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  
  DigiKeyboard.print("http://youtu.be/dQw4w9WgXcQ");
  DigiKeyboard.delay(200);
  // copy link so that we can quickly use it again later
  DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // open link
  DigiKeyboard.print("start http://youtu.be/dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
}

int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  
  if (count < 20) {
    // open 20 more windows with this link!
    
    // allow for a delay so that the video can start playing
    DigiKeyboard.delay(3000);
    
    // open a new window and paste the link in
    DigiKeyboard.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  
  count++;
}
