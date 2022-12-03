#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.cpp"
using namespace std;

void CtrlMenu(Menu menu, int& line){
    int x;
    line = 0;
    menu.printMenu();
    gotoxy(0, line);
    cout << (char) 1;
    int esc = 0;
    while (!esc){
        if (kbhit()){
            x = move();
            gotoxy(0, line);
            cout << " ";
            if (x == 1 || x == 3){
				line++;
                if (line >= menu.numberOfItem())
                        line = 0;
			}
            else if (x == 2 || x == 4){
                line --;
                if (line < 0)
                    line = menu.numberOfItem() - 1;
			}
            else if (x == 5){
                break;
            }
            else if (x == 8)
                exit(0);
            gotoxy(0, line);
            cout << (char) 1;
        }
    }
}

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
    int line;
    CtrlMenu (menu, line);
    menu.deleteMenu();
    if (line == 0){
        CtrlMenu(menu1, line);
    }
    else if (line == 1)
        CtrlMenu(menu2, line);
    else if (line == 2)
        CtrlMenu(menu3, line);
    else if (line == 3)
        CtrlMenu(menu4, line);
}
