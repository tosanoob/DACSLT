#include <iostream>
#include <windows.h>
#include "Menu.cpp"
#include "operation.cpp"
using namespace std;

int main()
{
    LH.readFromFile();
    UH.readFromFile();
    BH.readFromFile();
    libraryDisplay();
    cout<<"successful\n";
    getch();
    return 0;
}