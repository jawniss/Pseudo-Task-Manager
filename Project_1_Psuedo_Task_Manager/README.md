# Attempting to make psuedo task manager

Psuedo_Task_Manager:

1. Enter the directory of the project
2. Make sure make is installed
3. To clean the project folder, enter "make clean"
4. To compile, enter "make all"
5. To start the program, enter ".\test.exe"
6. Possible commands: 
        "List all"
          - Lists all open programs on the device, including their PID, file name, and current program/application"
        "<program_name>"
          - if the program exists, it will display its details and select it ass the current window
          - works for substrings, for example "Administrator: Command" will select and show the "Administrator: Command Prompt" program
          - I was working on getting the program to bring the selected window in focus, as in bringing the application to the front of the screen
            - was not working

 * Current functions:
 *   - Take user input for desired window to be selected
 *   - Display all currently opened applications
 *
 * Desired functions:
 *   - Focus on a selected window (in progress, doesn't actually show to front)
 *   - Minimize a selected window
 *   - Fullscreen/maximize a selected window
 *   - Kill selected window
 * 
 * Long term wanted functions:
 *   - Find a program on the device and open it if it's not currently opened

---

Johnas Wong
