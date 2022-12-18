#ifndef SACH_H
#define SACH_H

#include <string>
#include "template.h"
using namespace std;

class User;

class Sach {
    private:
    string tenSach, tenTacGia, ma;
    int soBan;

    DSLK<Node<User*>> list;

    public:
    Sach(string,string,int);
    void update();
    bool operator == (const Sach&);
    void setID(const string&);
    string getID();
    void append(const Sach&);
    void borrowList();
    DSLK<Node<User*>>& getList();
    ~Sach();

    friend istream& operator >> (istream&, Sach&);
    friend ostream& operator << (ostream&, const Sach&);
    
    friend ifstream& operator >> (ifstream&, Sach&);
    friend ofstream& operator << (ofstream&, Sach&);
    
    friend bool borrowBook(User& borrower, Sach& target);
    friend bool returnBook(User& borrower, Sach& target);
};

#endif