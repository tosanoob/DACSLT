#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

class Menu{
    private:
        string* item; //ten cac menu
        int number; //so luong menu
    public:
        Menu();
        Menu(int strnum, string a[]);
        Menu(string a, string b, string c, string d);
        ~Menu();
        int CtrlMenu();
        void printMenu();
        void deleteMenu();
        int numberOfItem();
        string* getItem();
};

#endif