#ifndef FUNCTION_H
#define FUNCTION_H

#include "template.h"
#include "sach.h"
#include "user.h"

//--------------Essential functions---------------
string increment(string&);
bool checkCmd(string&);

//---------Readfile & Writefile--------------
void readFile(ifstream&, DSLK<Node<Sach>>&);
void readFile(ifstream&, DSLK<Node<User>>&);
void readBorrowlist(ifstream&, DSLK<Node<User>>&, DSLK<Node<Sach>>&);
void writeFile(ofstream&, DSLK<Node<User>>&);
void writeFile(ofstream&, DSLK<Node<Sach>>&);
void saveBorrowlist(ofstream&, DSLK<Node<User>>&);

//-----Find & Borrow & Return----------------
bool borrowBook(User&,Sach&);
bool returnBook(User&,Sach&);
#endif