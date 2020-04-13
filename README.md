# USB_Rubber_Ducky

This repo contains all of the scripts I've written for my COMP6841 Something Awesome project.

## Files:
### rubber_ducky_basic_terminal
  * a simple file just to open up the terminal

### open_links
  * **open_links_mac.ino**: opens a video in twenty different windows on a Mac
  * **open_links_windows.ino**: same as above, but for Windows
  * **quicktime_record_opening_links_mac**: a script to start a Quicktime screen recording, open links as in open_links_mac.ino, then stop the screen recording

### creating_files
  * **create_file_mac.ino**: creates a simple file with a message inside and saves it to the user's Desktop (on a Mac)
  * **create_file_windows.ino**: same as above, but for Windows
  * **simple_file_no_echo_mac.ino**: same as create_file_mac.ino, but includes disabling terminal echoing
  * **name_to_file_mac.ino**: creates a file with the user's name in it, stating that they've been hacked, then opens the file, increases the font size multiple times and enters fullscreen (on a Mac)
  * **name_to_file_windows.ino**: same as above, but for Windows
  * **fancy_file_no_echo_mac.ino**: same as name_to_file_mac.ino, but includes disabling terminal echoing

### lock_screen
  * **lock_screen_mac.ino**: locks the user's computer screen every two minutes (on a Mac)
  * **lock_screen_windows.ino**: same as above, but for Windows

### take_photo
  * **take_photo_mac.ino**: takes a photo using Photo Booth on a Mac
  * **take_photo_windows.ino**: takes a photo using the Camera application on Windows

### rubber_ducky_email_screenshot.ino
  * takes a screenshot, then uses the mail service from the terminal to email the screenshot to myself

### transfer_files
  * **send_one_file_ubuntu.ino**: sends a single file from the user's computer to the attacker's using netcat
  * **send_directory_ubuntu.ino**: sends a whole directory to the attacker using netcat
  * **send_and_delete_password_files_ubuntu.ino**: searches through the user's Documents folder and sends any files whose contents contain the word 'password' to the attacker, before deleting these files from the computer
  * **send_and_delete_password_files_mac.ino**: same as above, but works on a Mac

### keylogging
  * an experiment in trying to make a simple keylogger
  * unfortunately, the method used (for a Mac) requires sudo to be used, so it needs a password to be entered, which is not ideal
  * this doesn't focus on the actual keylogging, but rather the method to deliver the keylogging programs and send the keystrokes back to the attacker
  * **keylogger.ino**: runs a python keylogger which sends all keystrokes to a file and runs a shell script which sends this file to the attacker using netcat every 30 seconds
  * **keylog.sh**: code for the shell script that repeatedly sends the keystroke file to the attacker
  * **logger.py**: code for the python keylogger
  * **start_netcat.sh**: shell script for the attacker to run to repeatedly start a listener on their computer
