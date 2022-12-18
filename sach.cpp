#ifndef SACH_CPP
#define SACH_CPP

#include "../DACSLT3/Header/sach.h"
#include "input_output.cpp"
#include <iostream>
using namespace std;

Sach::Sach(string ten="default", string tga="default", int cpy=0) : tenSach(ten), tenTacGia(tga), soBan(cpy), ma("000000") {}
void Sach::update()
{
    // cap nhat thong tin cua mot sach:
    cout << "Nhap moi thong tin cua cuon sach nay\n";
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, tenSach, '\n');
    cout << "Ten tac gia: ";
    cin.ignore();
    getline(cin, tenTacGia, '\n');
    cout << "So ban in: ";
    cin >> soBan;
    cout << "Cap nhat hoan tat";
    return;
}

DSLK<Node<User*>>& Sach:: getList() {return list;}

void Sach:: setID(const string& a) {ma = a;}

string Sach:: getID() {return ma;}

void Sach::borrowList() {
    int len = list.getSize();
    Node<User*>* temp = list.getHead();
    User* ptr;
    for (int i=0;i<len;i++) {
        ptr = temp->getData();
        cout<<*ptr<<'\n';
        temp=temp->toNext();
    }
}

void Sach:: append(const Sach& copy) {
    if (tenSach == copy.tenSach && tenTacGia == copy.tenTacGia)
    soBan += copy.soBan;
}

bool Sach::operator==(const Sach &comp)
{
    if (tenSach != comp.tenSach)
        return 0;
    if (tenTacGia != comp.tenTacGia)
        return 0;
    return 1;
}
Sach::~Sach() {}

#endif