#ifndef SACH_H
#define SACH_H

#include <string>
#include "template.h"
using namespace std;

class User;

class Sach {
    private:
    string tsach, ttgia, ma;
    int soban;

    DSLK<Node<User*>> list;

    public:
    Sach(string,string,int);
    void update();
    bool operator == (const Sach&);
    void setid(const string&);
    string getid();
    void borrowlist();
    DSLK<Node<User*>>& getlist();
    ~Sach();

    friend istream& operator >> (istream&, Sach&);
    friend ostream& operator << (ostream&, const Sach&);
    
    friend ifstream& operator >> (ifstream&, Sach&);
    friend ofstream& operator << (ofstream&, Sach&);

    friend void write_file(ofstream&, DSLK<Node<Sach>>&);
    friend void read_file(ifstream&, DSLK<Node<Sach>>&);
    
    friend bool borrowbook(User& borrower, Sach& target);
    friend bool returnbook(User& borrower, Sach& target);
};

#endif