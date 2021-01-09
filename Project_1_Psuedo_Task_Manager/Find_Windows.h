#ifndef FIND_WINDOWS_H
#define FIND_WINDOWS_H

#include <string>
#include <iostream>
#include <Windows.h>

BOOL CALLBACK enumWindowCallback(HWND hWnd, LPARAM lparam);
BOOL CALLBACK findSpecificWindow( HWND hWnd, LPARAM lparam );
void setGlobalWindowName( std::string nameUser, std::string nameFound );

#endif