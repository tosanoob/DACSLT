#ifndef USER_CPP
#define USER_CPP

#include "user.h"
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

DSLK<Node<Sach*>>& User:: getlist() {return list;}

void User:: setid(const string& a) {uid=a;}

string User:: getid() {return uid;}

void User::borrowlist() {
    int len = list.getsize();
    Node<Sach*>* temp = list.gethead();
    Sach* ptr;
    for (int i=0;i<len;i++) {
        ptr = temp->getdata();
        cout<<*ptr<<'\n';
        temp=temp->tonext();
    }
}

bool User:: operator== (const User& comp) {
    return (cmd==comp.cmd);
}

User:: ~User(){}

#endif