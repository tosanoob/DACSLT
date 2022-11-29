/* list of additional functions

borrow book
return book
operator >> for user & books
operator << for user & books
file input & output for user & book & record

print list of user borrowing the same book
print list of books borrowing by a user

*/

#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "friendfunction.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

//-------------Readfile & Writefile---------
void read_file(ifstream &inp, DSLK<Node<Sach>> &list)
{
    Sach temp;
    while (!inp.eof())
    {
        try {inp >> temp;}
        catch (invalid_argument) {
            return;
        }
        list.insert(temp);
    }
    return;
}

void read_file(ifstream &inp, DSLK<Node<User>> &list)
{
    User temp;
    while (!inp.eof())
    {
        inp >> temp;
        list.insert(temp);
    }
    return;
}


void write_file(ofstream &out, DSLK<Node<User>> &list)
{
    Node<User>* temp = list.gethead();
    for (int i =0;i<list.getsize();i++) {
        out<<temp->getdata();
        temp=temp->tonext();
    }
}

void write_file(ofstream &out, DSLK<Node<Sach>> &list)
{
    Node<Sach>* temp = list.gethead();
    for (int i =0;i<list.getsize();i++) {
        out<<temp->getdata();
        temp=temp->tonext();
    }
}

void save_borrowlist(ofstream &out, DSLK<Node<User>> &list) {
    Node<User>* temp = list.gethead();
    int len = list.getsize();
    cout<<"debug trap 1\n";
    for (int i=0;i<len;i++) {
        DSLK<Node<Sach*>>& booklist = temp->getdata().getlist();
        int size = booklist.getsize();
        cout<<"debug trap 2\n";
        if (size>0) {
            Node<Sach*>* tempptr = booklist.gethead();
            string userid = temp->getdata().getid();
            cout<<"debug trap 3\n";
            for (int j =0;j<len;j++) {
                string bookid = tempptr->getdata()->getid();
                out<<userid<<'|'<<bookid<<'\n';
                tempptr=tempptr->tonext();
            }
        }
        temp=temp->tonext();
    }
}

//------------Find & Borrow & Return------------

Sach& find_id (const string & lookid, DSLK<Node<Sach>>& list) {
    Node<Sach>* temp = list.gethead();
    for (int i =0;i<list.getsize();i++) {
        if (temp->getdata().getid()==lookid) return temp->getdata();
        temp = temp->tonext();
    }
    if (temp==NULL) throw MEMBER_NOTFOUND;
}

User& find_id (const string & lookid, DSLK<Node<User>>& list) {
    Node<User>* temp = list.gethead();
    for (int i =0;i<list.getsize();i++) {
        if (temp->getdata().getid()==lookid) return temp->getdata();
        temp = temp->tonext();
    }
    if (temp==NULL) throw MEMBER_NOTFOUND;
}

bool borrowbook(User& borrower, Sach& target) {
    if (target.soban==0) return 0; 
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getlist().insert(target_ptr);
    target.getlist().insert(borrower_ptr);
    target.soban--;
    cout<<"function borrow succeed\n";
    return 1;
}

bool returnbook(User& borrower, Sach& target) {
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getlist().remove(target_ptr);
    target.getlist().remove(borrower_ptr);
    target.soban++;
    cout<<"function return succeed\n";
    return 1;
}

#endif