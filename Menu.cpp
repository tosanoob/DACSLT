#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int column, int line){
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int move(){
    char c = getch();
    if ((int)c == -32)
        c = getch();
    switch ((int) c){
        case 80:
            return 1; //nhan phim xuong
        case 72:
            return 2; //nhan phim len
        case 77:
            return 3; //nhan phim phai
        case 75:
            return 4; //nhan phim trai
        case 27:
            return 8; //nut esc
        case 13:
            return 5; //nut enter
        default:
            return 0; //Sai
    }
}

Menu::Menu(){
    item = new string [100];
    number = 4;
    item[0] = "Them, sua sach trong thu vien";
    item[1] = "Them, sua, xoa nguoi dung";
    item[2] = "muon, tra sach";
    item[3] = "Ket thuc";
}

Menu::Menu(int strnum, string a[]): number(strnum){
    item = new string [strnum];
    for (int i = 0; i < strnum; i++)
        item[i] = a[i];
}

Menu::Menu(string a, string b, string c, string d){
    number = 4;
    item = new string [100];
    item[0] = a;
    item[1] = b;
    item[2] = c;
    item[3] = d;
}

void Menu::printMenu(){
    for (int i = 0; i < number; i++){
        gotoxy(3, i);
        cout << item[i];
        //Sleep(1000);
    }
}

void Menu::deleteMenu(){
    for (int i = 0; i < number; i++){
        gotoxy(0, i);
        for (int j = 0; j < item[i].size() + 3; j++)
            cout << " ";
    }
}

int Menu:: CtrlMenu() {
    int x;
    int line = 0;
    printMenu();
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
                if (line >= number)
                        line = 0;
			}
            else if (x == 2 || x == 4){
                line --;
                if (line < 0)
                    line = number - 1;
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

string* Menu::getItem(){
    return item;
}

int Menu::numberOfItem(){
    return number;
}

Menu::~Menu(){
    delete[] item;
}
