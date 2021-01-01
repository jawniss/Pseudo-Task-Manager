#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    // Successfully moves the cursor on running of the program
    // SetCursorPos(200, 500);

    /**
     * Really cool function from Brandon at 
     * https://stackoverflow.com/questions/22259936/c-move-mouse-in-windows-using-setcursorpos
     * that focusses the task manager window and moves cursor. VSCode ran in admin mode.
     */
    HWND window = FindWindow("TaskManagerWindow", "Task Manager");
    if (window)
    {
        RECT rect = {0};
        GetWindowRect(window, &rect);

        SetForegroundWindow(window);
        SetActiveWindow(window);
        SetFocus(window);
        
        cout << "Rect right n bottom: " << rect.right << " " << rect.bottom << endl;
        SetCursorPos(rect.right - 200, rect.bottom - 200);

        // cout << "Found taskmanager" << endl;
    }
    return 0;
}