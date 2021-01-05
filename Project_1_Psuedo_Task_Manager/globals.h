#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>

using namespace std;

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.
extern string windowName;
extern string windowToFind;

#endif