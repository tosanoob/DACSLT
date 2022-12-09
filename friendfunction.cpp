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

void read_borrowlist(ifstream &inp, DSLK<Node<User>>& userlist, DSLK<Node<Sach>>& sachlist) {
    string userid;
    string sachid;
    while (!inp.eof())
    {
        getline(inp,userid,'|');
        getline(inp,sachid);
        if (userid == "" || sachid == "") return; //false read file
        try {
            User* borrower_ptr = &userlist.find_id<User>(userid);
            Sach* target_ptr = &sachlist.find_id<Sach>(sachid);
            borrower_ptr->getlist().insert(target_ptr);
            target_ptr->getlist().insert(borrower_ptr);
        }
        catch (int& returnid) { //if not found id;
            if (returnid == MEMBER_NOTFOUND) cout<<"error id not found";
            else throw;
        }
    }
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
    for (int i=0;i<len;i++) {
        DSLK<Node<Sach*>>& booklist = temp->getdata().getlist();
        int size = booklist.getsize();
        if (size>0) {
            Node<Sach*>* tempptr = booklist.gethead();
            string userid = temp->getdata().getid();
            for (int j =0;j<size;j++) {
                string bookid = tempptr->getdata()->getid();
                out<<userid<<'|'<<bookid<<'\n';
                tempptr=tempptr->tonext();
            }
        }
        temp=temp->tonext();
    }
}

//------------Find & Borrow & Return------------

bool borrowbook(User& borrower, Sach& target) {
    if (target.soban==0) return 0; 
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getlist().insert(target_ptr);
    target.getlist().insert(borrower_ptr);
    target.soban--;
    return 1;
}

bool returnbook(User& borrower, Sach& target) {
    User* borrower_ptr = &borrower;
    Sach* target_ptr = &target;
    borrower.getlist().remove(target_ptr);
    target.getlist().remove(borrower_ptr);
    target.soban++;
    return 1;
}

//call this returnall before delete a <sach>
void returnall (Sach& target) {
    DSLK<Node<User*>> &userlist = target.getlist();
    Node<User*>* temp;
    User* borrower_ptr;
    int size = userlist.getsize();  
    for (int i =0;i<size;i++) {
        temp = userlist.gethead();
        borrower_ptr = temp->getdata();
        returnbook(*borrower_ptr,target);
        //force-return a book
        //don't need to move temp->tonext(), the head will be modified itself
    }
}

//call this returnall before delete a <user>
void returnall (User& target) {
    DSLK<Node<Sach*>> &sachlist = target.getlist();
    Node<Sach*>* temp;
    Sach* sach_ptr;
    int size = sachlist.getsize();  
    for (int i =0;i<size;i++) {
        temp = sachlist.gethead();
        sach_ptr = temp->getdata();
        returnbook(target,*sach_ptr);
        //force-return a book
        //don't need to move temp->tonext(), the head will be modified itself
    }
}
#endif