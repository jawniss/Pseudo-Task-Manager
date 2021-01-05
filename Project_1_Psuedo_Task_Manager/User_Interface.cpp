#include <iostream>
#include "Find_Windows.h"
#include "globals.h"
#include "Focus_Window.h"
#include "User_Interface.h"
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

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

    cout << "command: " << userCommand << endl;

    if( userCommand.find("list") != string::npos )
    {
        cout << "List all windows" << endl;
        EnumWindows(enumWindowCallback, NULL);
    } else {
        setGlobalWindowName( userCommand );
        cout << "Chosen window: " << windowName;
        // try: except:
    }
}