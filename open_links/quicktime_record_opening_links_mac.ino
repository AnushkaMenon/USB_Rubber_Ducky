#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:
  DigiKeyboard.sendKeyStroke(0);

  // hide all other windows (shortcut: Command + Alt + H)
  DigiKeyboard.sendKeyStroke(KEY_H, MOD_ALT_LEFT | MOD_GUI_LEFT);
  // hide current window (shortcut: Command + H)
  DigiKeyboard.sendKeyStroke(KEY_H, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // open up quicktime
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("quicktime player");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  // shortcut to start a new recording is Command + Ctrl + N
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT | MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Press space to start a new recording
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  
  // We have to manually click to actually start the recording, so allow a time delay for this
  DigiKeyboard.delay(3000);

  // increase volume
  for (int i = 0; i < 3; i++) {
    DigiKeyboard.sendKeyStroke(128)
  }

  // open spotlight and type in the link
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("http://youtu.be/dQw4w9WgXcQ");
  DigiKeyboard.delay(500);
  
  // copy the link so that we can quickly use it again later
  DigiKeyboard.sendKeyStroke(KEY_A, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_C, MOD_GUI_LEFT);

  // press enter to open the link
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

int count = 0;
bool finished = false;

void loop() {
  if (not finished) {
    // open 30 more windows!
    if (count < 5) {
      // allow for a delay so that the video can start playing
      DigiKeyboard.delay(4000);
      
      // open a new window and paste the link in
      //  Command + N opens up a new window
      //  Command + V pastes the link into the search bar
      DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
      DigiKeyboard.sendKeyStroke(KEY_V, MOD_GUI_LEFT);

      // press enter to open up the webpage
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      
    } else {
      // we've opened up 31 windows playing the same video, now stop the recording
      // allow for a delay so that we can see the result of the script
      DigiKeyboard.delay(10000);
      // shortcut to stop the recording is Command + Control + Escape
      //  (usage ID of the Escape key is 41)
      DigiKeyboard.sendKeyStroke(41, MOD_CONTROL_LEFT | MOD_GUI_LEFT);
      
      finished = true;
    }
    count++;
  }
}
