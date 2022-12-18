#ifndef USER_CPP
#define USER_CPP

#include "../DACSLT3/Header/user.h"
#include "input_output.cpp"
#include <iostream>
using namespace std;


User:: User (string name="default",string c = "0000000000"): ten(name),cmd(c),uid("00000") {}
void User:: update() {
    cout << "Nhap moi thong tin cua nguoi dung nay\n";
    cout << "Ten nguoi dung: ";
    cin.ignore();
    getline(cin, ten, '\n');
    cout << "So CMND: ";
    cin.ignore();
    getline(cin, cmd, '\n');
    cout << "Cap nhat hoan tat";
    return;
}

DSLK<Node<Sach*>>& User:: getList() {return list;}

void User:: setID(const string& a) {uid=a;}

string User:: getID() {return uid;}

void User::borrowList() {
    int len = list.getSize();
    Node<Sach*>* temp = list.getHead();
    Sach* ptr;
    for (int i=0;i<len;i++) {
        ptr = temp->getData();
        cout<<*ptr<<'\n';
        temp=temp->toNext();
    }
}

bool User:: operator== (const User& comp) {
    return (cmd==comp.cmd);
}

User:: ~User(){}

#endif