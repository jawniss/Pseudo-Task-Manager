#include <iostream>
#include "Focus_Window.h"
#include "globals.h"

using namespace std;

void focusWindow() 
{
    //Getting the HWND of Chrome
    HWND chromeWindow = FindWindow( NULL, windowName.c_str() );
    // HWND chromeWindow = FindWindow( windowName.c_str(), NULL );
    // HWND chromeWindow = FindWindow( "Steam", NULL );

    cout << "windowname.cstr" << windowName.c_str() << endl;
    //Setting the window to the foreground (implies focus and activating)
    cout << "setforgorundwindow: " << SetForegroundWindow( chromeWindow ) << endl;
    cout << "bringwintotop: " << BringWindowToTop( chromeWindow ) << endl;
    cout << "setfocus: " << SetFocus( chromeWindow ) << endl;
}