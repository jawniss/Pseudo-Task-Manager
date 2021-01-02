    auto hwnd = FindWindow(L"Chrome_WidgetWin_1", L"");    
    auto phwnd = GetParent(hwnd);
    EnumChildWindows(phwnd == NULL ? hwnd : phwnd, MyEnumProc, (LPARAM)"");

    BOOL CALLBACK MyEnumProc(HWND hWnd, LPARAM lParam)
    {
        char class_name[80];
        char title[80];
        GetClassNameA(hWnd, class_name, sizeof(class_name));
        GetWindowTextA(hWnd, title, sizeof(title));
        std::cout << "Window title: " << title << std::endl;
        std::cout << "Class name: " << class_name << std::endl << std::endl;
        RECT rect;
        GetWindowRect(hWnd, &rect);
        SendMessage(hWnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(10, 10));
        SendMessage(hWnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(10, 10));
        std::cout << "Done 1\n";
        Sleep(1000);
        return TRUE;
    }