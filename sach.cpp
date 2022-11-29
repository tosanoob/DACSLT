#ifndef SACH_CPP
#define SACH_CPP

#include "sach.h"
#include "input_output.cpp"
#include <iostream>
using namespace std;

Sach::Sach(string ten="default", string tga="default", int cpy=0) : tsach(ten), ttgia(tga), soban(cpy), ma("000000") {}
void Sach::update()
{
    // cap nhat thong tin cua mot sach:
    cout << "Nhap moi thong tin cua cuon sach nay\n";
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, tsach, '\n');
    cout << "Ten tac gia: ";
    cin.ignore();
    getline(cin, ttgia, '\n');
    cout << "So ban in: ";
    cin >> soban;
    cout << "Cap nhat hoan tat";
    return;
}

DSLK<Node<User*>>& Sach:: getlist() {return list;}

void Sach:: setid(const string& a) {ma = a;}

string Sach:: getid() {return ma;}

void Sach::borrowlist() {
    int len = list.getsize();
    Node<User*>* temp = list.gethead();
    User* ptr;
    for (int i=0;i<len;i++) {
        ptr = temp->getdata();
        cout<<*ptr<<'\n';
        temp=temp->tonext();
    }
}

bool Sach::operator==(const Sach &comp)
{
    if (tsach != comp.tsach)
        return 0;
    if (ttgia != comp.ttgia)
        return 0;
    return 1;
}
Sach::~Sach() {}

#endif