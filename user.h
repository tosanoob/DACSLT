#ifndef USER_H
#define USER_H

#include <string>
#include "template.h"
#include "sach.h"
using namespace std;

class User
{
    string ten, cmd, uid;

    DSLK<Node<Sach*>> list;

public:
    User(string, string);
    void update();
    bool operator==(const User &);
    void setID(const string &);
    string getID();
    void borrowList();
    DSLK<Node<Sach*>>& getList(); 
    ~User();

    friend istream &operator>>(istream &, User &);
    friend ostream &operator<<(ostream &, const User &);

    friend ifstream& operator >> (ifstream&, User&);
    friend ofstream& operator << (ofstream&, User&);
};

#endif
