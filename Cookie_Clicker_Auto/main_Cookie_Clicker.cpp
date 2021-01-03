#include <iostream>
#include "Find_Windows.h"
#include "globals.h"

using namespace std;

int main()
{
    std::cout << "Enmumerating windows..." << std::endl;
    EnumWindows(enumWindowCallback, NULL);
    // std::cin.ignore();
    cout << "Globe: " << windowName << endl;

    return 0;
}