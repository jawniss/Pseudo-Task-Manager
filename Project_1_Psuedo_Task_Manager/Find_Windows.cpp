#include "Find_Windows.h"
#include "globals.h"
#include <algorithm>
#include <cctype>

using namespace std;

void setGlobalWindowName( string nameUser, string nameFound )
{
    // cout << "windowname " << name << endl;
    cout << "nameUser empty: " << nameUser.empty() << endl;
    cout << "nameFound empty: " << nameFound.empty() << endl;
    if( !nameUser.empty() )
    {
        userWindowName = nameUser;
    }
    if( !nameFound.empty() )
    {
        foundWindowName = nameFound;
    }
    cout << "userWindowName: " << userWindowName << ". foundWindowName: " << foundWindowName << endl;
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
    // cout << "Specific window" << userWindowName << endl;
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowText(hWnd, buffer, length + 1);
    std::string windowTitle(buffer);

    // List visible windows with a non-empty title
    if ( IsWindowVisible(hWnd) && length != 0 ) 
    {
        std::cout << hWnd << ":  " << windowTitle << std::endl;
        string tempWindowTitleLowercase = windowTitle;
        transform(tempWindowTitleLowercase.begin(), tempWindowTitleLowercase.end(), tempWindowTitleLowercase.begin(),
            [](unsigned char c){ return tolower(c); });

        if( tempWindowTitleLowercase.find( userWindowName ) != string::npos )
        {
            std::cout << userWindowName << " found!" << std::endl;
            setGlobalWindowName( "", windowTitle );
            return FALSE;
        }
    } else {
        // Here means the window was not found cus if it's found return FALSE
        cout << "Window not found!" << endl;
    }

    return TRUE;
}