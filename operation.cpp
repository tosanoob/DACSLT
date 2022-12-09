#ifndef OPERATION_CPP
#define OPERATION_CPP

#include "operation.h"
#include "template.h"
#include "sach.cpp"
#include "user.cpp"
#include <iostream>
#include <fstream>

DSLK<Node<Sach>> sachlist;
DSLK<Node<User>> userlist;

// library_Handler

library_Handler::library_Handler()
{
    file_destination = "sachbase.txt";
}

bool library_Handler::readFromFile()
{
    ifstream inp(file_destination);
    read_file(inp, sachlist);
    inp.close();
}

bool library_Handler::writeToFile()
{
    ofstream out(file_destination);
    write_file(out, sachlist);
    out.close();
}

bool library_Handler::inputNew()
{
    // Ham nhap them sach moi tu ban phim;
    Sach newbook;
    cin >> newbook;
    string last_id = sachlist.gettail()->getdata().getid();
    newbook.setid(increment(last_id));
    return sachlist.insert(newbook);
    // neu them thanh cong tra ve 1, them that bai tra ve 0
}

bool library_Handler::updateExisted()
{
    string target_id;
    cin >> target_id;
    try
    {
        Sach &target = sachlist.find_id<Sach>(target_id);
        cout << "Tim thay sach:\n"
             << target << '\n';
        cout << "Nhap thong tin chinh sua: ";
        cin >> target;
        cout << "Chinh sua thanh cong";
        return 1;
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay sach co ID da nhap\n";
        return 0;
    }
}

bool library_Handler::removeExisted()
{
    string target_id;
    cin >> target_id;
    try
    {
        Sach &target = sachlist.find_id<Sach>(target_id);
        cout << "Ban chac chan muon xoa sach sau:\n"
             << target << '\n';
        cout << "Nhap Y/N: ";
        //currently leftover
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay sach co ID da nhap\n";
        return 0;
    }
}

// userbase_Handler;
userbase_Handler::userbase_Handler()
{
    file_destination = "userbase.txt";
}
bool userbase_Handler::inputNew()
{
    User newbook;
    cin >> newbook;
    string last_id = userlist.gettail()->getdata().getid();
    newbook.setid(increment(last_id));
    return userlist.insert(newbook);
}
bool userbase_Handler::updateExisted()
{
    string target_id;
    cin >> target_id;
    try
    {
        User &target = userlist.find_id<User>(target_id);
        cout << "Tim thay nguoi dung:\n"
             << target << '\n';
        cout << "Nhap thong tin chinh sua: ";
        cin >> target;
        cout << "Chinh sua thanh cong";
        return 1;
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay nguoi dung co ID da nhap\n";
        return 0;
    }
}
bool userbase_Handler::removeExisted()
{
    string target_id;
    cin >> target_id;
    try
    {
        User &target = userlist.find_id<User>(target_id);
        cout << "Ban chac chan muon xoa nguoi dung sau:\n"
             << target << '\n';
        cout << "Nhap Y/N: ";
        //currently leftover
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay nguoi dung co ID da nhap\n";
        return 0;
    }
}
bool userbase_Handler::readFromFile()
{
    ifstream inp(file_destination);
    read_file(inp, userlist);
    inp.close();
}
bool userbase_Handler::writeToFile()
{
    ofstream out(file_destination);
    write_file(out, userlist);
    out.close();
}

// borrowing_Handler:
borrowing_Handler::borrowing_Handler()
{
    file_destination = "borrowing.txt";
}
bool borrowing_Handler:: inputNew() {
    string userid,sachid;
    int step = 0;
    try 
    {
        cout<<"Nhap id nguoi muon: ";cin>>userid;
        User& borrower = userlist.find_id<User>(userid);
        step=1;
        cout<<"Nhap id sach muon muon: ";cin>>sachid;
        Sach& target = sachlist.find_id<Sach>(sachid);
        return borrowbook(borrower,target);
        //muon thanh cong tra ve 1, that bai tra ve 0
    } 
    catch (int& exc) {
        if (exc == MEMBER_NOTFOUND) 
            if (step==0) cout<<"Khong tim thay nguoi dung\n";
            else cout<<"Khong tim thay sach\n";
        return 0;
    }
}
bool borrowing_Handler:: updateExisted() {
    //do nothing
    return 1;
}
bool borrowing_Handler:: removeExisted() {
    string userid,sachid;
    int step = 0;
    try 
    {
        cout<<"Nhap id nguoi muon sach: ";cin>>userid;
        User& borrower = userlist.find_id<User>(userid);
        step=1;
        cout<<"Nhap id sach muon tra: ";cin>>sachid;
        Sach& target = sachlist.find_id<Sach>(sachid);
        return returnbook(borrower,target);
        //tra thanh cong tra ve 1, that bai tra ve 0
    } 
    catch (int& exc) {
        if (exc == MEMBER_NOTFOUND) 
            if (step==0) cout<<"Khong tim thay nguoi dung\n";
            else cout<<"Khong tim thay sach\n";
        return 0;
    }
}
bool borrowing_Handler:: readFromFile() {
    ifstream inp(file_destination);
    read_borrowlist(inp,userlist,sachlist);
    inp.close();
}
bool borrowing_Handler:: writeToFile() {
    ofstream out(file_destination);
    save_borrowlist(out,userlist);
    out.close();
}

#endif