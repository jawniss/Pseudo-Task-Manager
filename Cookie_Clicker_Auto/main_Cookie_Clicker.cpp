#include <iostream>
#include "Find_Windows.h"

using namespace std;

int main()
{
    std::cout << "Enmumerating windows..." << std::endl;
    EnumWindows(enumWindowCallback, NULL);
    // std::cin.ignore();

    return 0;
}