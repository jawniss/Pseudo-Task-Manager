#include <iostream>
#include "Focus_Window.h"
#include "globals.h"

using namespace std;

void focusWindow() 
{
    //Getting the HWND of Chrome
    HWND chromeWindow = FindWindow( windowName.c_str(), NULL );

    //Setting the window to the foreground (implies focus and activating)
    SetForegroundWindow( chromeWindow );
}