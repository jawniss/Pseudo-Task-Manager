#include "Find_Windows.h"

BOOL CALLBACK enumWindowCallback(HWND hWnd, LPARAM lparam) {
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowText(hWnd, buffer, length + 1);
    std::string windowTitle(buffer);

    // List visible windows with a non-empty title
    if (IsWindowVisible(hWnd) && length != 0) {
        std::cout << hWnd << ":  " << windowTitle << std::endl;
        if( windowTitle == "Steam" )
        {
            std::cout << "Steam found" << std::endl;
        }
    }
    return TRUE;
}