/**
 * https://www.google.com/search?q=c%2B%2B+setforegroundwindow+not+working&rlz=1C1CHBD_enCA855CA856&oq=c%2B%2B+setfor&aqs=chrome.0.69i59j69i57j0i457j0i22i30l2j69i60l3.3967j0j4&sourceid=chrome&ie=UTF-8
 * https://social.msdn.microsoft.com/Forums/windows/en-US/dfcc6ac6-a406-427e-8857-0860064b0c38/setforegroundwindow-not-always-working?forum=vbgeneral
 * https://www.google.com/search?q=c%2B%2B+allowsetforgroundwindow&rlz=1C1CHBD_enCA855CA856&oq=c%2B%2B+allowsetforgroundwindow&aqs=chrome..69i57.609j0j1&sourceid=chrome&ie=UTF-8
 * https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-allowsetforegroundwindow
 * 
 * It seems that sometimes the window will not be focused. it succcessfully finds
 * the window, but sometimes won't bring it to the front. discord seems to often
 * not focus
 */

#include <iostream>
#include "Focus_Window.h"
#include "globals.h"

using namespace std;

void focusWindow() 
{
    //Getting the HWND of Chrome
    HWND chromeWindow = FindWindow( NULL, foundWindowName.c_str() );
    // HWND chromeWindow = FindWindow( windowName.c_str(), NULL );
    // HWND chromeWindow = FindWindow( "Steam", NULL );

    cout << "windowfoundWindowNamename.cstr" << foundWindowName.c_str() << endl;
    
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