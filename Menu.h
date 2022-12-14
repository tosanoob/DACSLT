#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

class Menu{
    private:
        string* item; //ten cac menu
        int number; //so luong menu
    public:
        Menu(int strnum, string a[]);
        ~Menu();
        int ctrlMenu();
        void printMenu();
        void deleteMenu();
        int numberOfItem();
        string* getItem();
};

#endif