#include "Find_Windows.h"
#include "globals.h"

using namespace std;

void setGlobalWindowName( string name )
{
    // cout << "windowname " << name << endl;
    windowName = name;
    return;
}


//https://stackoverflow.com/questions/10246444/how-can-i-get-enumwindows-to-list-all-windows
// Stevoisiak
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
    }
    return TRUE;
}


// this isn't working cus the wanted user window gets converted to lower case
// so i need to convert the windowTitle to lower case then check
// but i need to make a temp variable windowTitleLowercase cus i need to keep the og
// windowTitle to setFlobalWindowName
BOOL CALLBACK findSpecificWindow( HWND hWnd, LPARAM lparam ) 
{
    cout << "Specific window" << windowName << endl;
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowText(hWnd, buffer, length + 1);
    std::string windowTitle(buffer);

    // List visible windows with a non-empty title
    if ( IsWindowVisible(hWnd) && length != 0 ) 
    {
        std::cout << hWnd << ":  " << windowTitle << std::endl;
        if( windowTitle.find( windowName ) != string::npos )
        {
            std::cout << windowName << " found!" << std::endl;
            setGlobalWindowName( windowTitle );
            return FALSE;
        }
    }
    // Here means the window was not found cus if it's found return FALSE
    cout << "Window not found!" << endl;

    return TRUE;
}