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
    void setid(const string &);
    string getid();
    void borrowlist();
    DSLK<Node<Sach*>>& getlist(); 
    ~User();

    friend istream &operator>>(istream &, User &);
    friend ostream &operator<<(ostream &, const User &);

    friend ifstream& operator >> (ifstream&, User&);
    friend ofstream& operator << (ofstream&, User&);

    friend User& find_id(const string &, DSLK<Node<User>>&);
    friend void write_file(ofstream&, DSLK<Node<User>>&);
    friend void read_file(ifstream&, DSLK<Node<User>>&);
    /*
    friend functions:
    print list of books borrowing by a user;
    */
};

#endif
