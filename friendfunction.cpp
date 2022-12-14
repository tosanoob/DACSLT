#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "friendfunction.h"
#include "sach.cpp"
#include "user.cpp"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

//-------------Readfile & Writefile---------
void readFile(ifstream &inp, DSLK<Node<Sach>> &list)
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

void readFile(ifstream &inp, DSLK<Node<User>> &list)
{
    User temp;
    while (!inp.eof())
    {
        inp >> temp;
        list.insert(temp);
    }
    return;
}

void readBorrowlist(ifstream &inp, DSLK<Node<User>>& userList, DSLK<Node<Sach>>& bookList) {
    string userid;
    string sachid;
    while (!inp.eof())
    {
        getline(inp,userid,'|');
        getline(inp,sachid);
        if (userid == "" || sachid == "") return; //false read file
        try {
            User* borrower_ptr = &userList.find_id<User>(userid);
            Sach* target_ptr = &bookList.find_id<Sach>(sachid);
            borrower_ptr->getList().insert(target_ptr);
            target_ptr->getList().insert(borrower_ptr);
        }
        catch (int& returnid) { //if not found id;
            if (returnid == MEMBER_NOTFOUND) cout<<"error id not found";
            else throw;
        }
    }
}

void writeFile(ofstream &out, DSLK<Node<User>> &list)
{
    Node<User>* temp = list.getHead();
    for (int i =0;i<list.getSize();i++) {
        out<<temp->getData();
        temp=temp->toNext();
    }
}

void writeFile(ofstream &out, DSLK<Node<Sach>> &list)
{
    Node<Sach>* temp = list.getHead();
    for (int i =0;i<list.getSize();i++) {
        out<<temp->getData();
        temp=temp->toNext();
    }
}

void saveBorrowlist(ofstream &out, DSLK<Node<User>> &list) {
    Node<User>* temp = list.getHead();
    int len = list.getSize();
    for (int i=0;i<len;i++) {
        DSLK<Node<Sach*>>& booklist = temp->getData().getList();
        int size = booklist.getSize();
        if (size>0) {
            Node<Sach*>* tempptr = booklist.getHead();
            string userid = temp->getData().getID();
            for (int j =0;j<size;j++) {
                string bookid = tempptr->getData()->getID();
                out<<userid<<'|'<<bookid<<'\n';
                tempptr=tempptr->toNext();
            }
        }
        temp=temp->toNext();
    }
}

//------------Find & Borrow & Return------------

bool borrowBook(User& borrower, Sach& target) {
    if (target.soBan==0) return 0; 
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getList().insert(target_ptr);
    target.getList().insert(borrower_ptr);
    target.soBan--;
    return 1;
}

bool returnBook(User& borrower, Sach& target) {
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getList().remove(target_ptr);
    target.getList().remove(borrower_ptr);
    target.soBan++;
    return 1;
}

//call this returnAll before delete a <sach>
void returnAll (Sach& target) {
    DSLK<Node<User*>> &userList = target.getList();
    Node<User*>* temp;
    User* borrower_ptr;
    int size = userList.getSize();  
    for (int i =0;i<size;i++) {
        temp = userList.getHead();
        borrower_ptr = temp->getData();
        returnBook(*borrower_ptr,target);
        //force-return a book
        //don't need to move temp->tonext(), the head will be modified itself
    }
}

//call this returnAll before delete a <user>
void returnAll (User& target) {
    DSLK<Node<Sach*>> &bookList = target.getList();
    Node<Sach*>* temp;
    Sach* sach_ptr;
    int size = bookList.getSize();  
    for (int i =0;i<size;i++) {
        temp = bookList.getHead();
        sach_ptr = temp->getData();
        returnBook(target,*sach_ptr);
        //force-return a book
        //don't need to move temp->tonext(), the head will be modified itself
    }
}
#endif