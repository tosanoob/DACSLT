#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "user.h"
#include "sach.h"
#include "friendfunction.h"

// necessary functions:
string increment(string &);
bool check_cmd(string &);

//-------------Operator << >> for User------------
istream &operator>>(istream &, User &);
ostream &operator<<(ostream &, const User &);
ifstream &operator>>(ifstream &, User &);
ofstream &operator<<(ofstream &, const User &);

//------------Operator << >> for Sach------------
istream &operator>>(istream &, Sach &);
ostream &operator<<(ostream &, const Sach &);
ifstream &operator>>(ifstream &, Sach &);
ofstream &operator<<(ofstream &, const Sach &);

#endif