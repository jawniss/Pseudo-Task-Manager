#include "Find_Windows.h"
#include "globals.h"

using namespace std;

void setGlobalWindowName( string name )
{
    // cout << "windowname " << name << endl;
    windowName = name;
    return;
}

BOOL CALLBACK enumWindowCallback( HWND hWnd, LPARAM lparam ) 
{
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowText(hWnd, buffer, length + 1);
    std::string windowTitle(buffer);

    // List visible windows with a non-empty title
    if ( IsWindowVisible(hWnd) && length != 0 ) 
    {
        std::cout << hWnd << ":  " << windowTitle << std::endl;
        // if( windowTitle == "Steam" )
        if( windowTitle.find( windowToFind ) != string::npos )
        {
            std::cout << windowToFind << " found!" << std::endl;
            setGlobalWindowName( windowTitle );
            return FALSE;
        }
    }
    return TRUE;
}