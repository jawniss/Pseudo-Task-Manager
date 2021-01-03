#include "Focus_Window.h"
#include <iostream>

using namespace std;

void focusWindow( string windowName ) 
{
    //Getting the HWND of Chrome
    HWND chromeWindow = FindWindow( windowName, NULL );

    //Setting the window to the foreground (implies focus and activating)
    SetForegroundWindow( chromeWindow );
}