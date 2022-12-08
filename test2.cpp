#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.cpp"
using namespace std;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
string a[4] = {"them sach", "sua thong tin", "xoa sach", "quay lai"};
int main(){
    system("cls");
    ShowConsoleCursor(false);
    Menu menu, menu1(4, a);
    Menu menu2("them nguoi dung", "sua thong tin nguoi dung", "xoa nguoi dung", "quay lai");
    Menu menu3, menu4;
    int line = menu.CtrlMenu();
    menu.deleteMenu();
    if (line == 0){
        line = menu1.CtrlMenu();
    }
    else if (line == 1)
        line = menu2.CtrlMenu();
    else if (line == 2)
        line = menu3.CtrlMenu();
    else if (line == 3)
        line = menu4.CtrlMenu();
}
