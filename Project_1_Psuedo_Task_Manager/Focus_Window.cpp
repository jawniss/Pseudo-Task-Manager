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
    // cout << "setforgorundwindow: " << SetForegroundWindow( chromeWindow ) << endl;
    // cout << "bringwintotop: " << BringWindowToTop( chromeWindow ) << endl;
    // cout << "setfocus: " << SetFocus( chromeWindow ) << endl;


    // from https://stackoverflow.com/questions/916259/win32-bring-a-window-to-top bronze man
    SendMessage(chromeWindow, WM_SYSCOMMAND, SC_RESTORE, 0); // restore the minimize window
    cout << "SetForegroundWindow: " << SetForegroundWindow(chromeWindow) << endl;
    cout << "SetActiveWindow: " << SetActiveWindow(chromeWindow) << endl; 
    cout << "SetWindowPos: " << SetWindowPos(chromeWindow, HWND_TOP, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE  | SWP_NOSIZE) << endl;
    //redraw to prevent the window blank.
    RedrawWindow(chromeWindow, NULL, 0, RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN );
}