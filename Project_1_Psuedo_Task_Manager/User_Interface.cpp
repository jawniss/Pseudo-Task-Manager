#include <iostream>
#include "Find_Windows.h"
#include "globals.h"
#include "Focus_Window.h"
#include "User_Interface.h"
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;


void selectWindow()
{
    try
    {
        EnumWindows( findSpecificWindow, NULL );
    } catch( ... ) {
        cout << "Window was not found - sorry!" << endl;
        // i dont' think this ever gets triggered
        // i think it's for actual error catches
    }
}


void getInput()
{
    string userCommand;

    cout << "Enter command (List all open windows or specific window [ex Chrome]): " ;
    // cin >> windowToFind;
    getline( cin, userCommand );

    // https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
    // Stefan Mai
    transform(userCommand.begin(), userCommand.end(), userCommand.begin(),
        [](unsigned char c){ return tolower(c); });

    // to_string( userCommand );

    cout << "Entered command: " << userCommand << endl;

    if( userCommand.find("list") != string::npos )
    {
        cout << "List all windows" << endl;
        EnumWindows(enumWindowCallback, NULL);
    } else {
        setGlobalWindowName( userCommand, "" );
        cout << "User window: " << userWindowName << endl;
        cout << "Found window: " << foundWindowName << endl;
        selectWindow();
    }
}