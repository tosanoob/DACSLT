#ifndef OPERATION_CPP
#define OPERATION_CPP

#include "operation.h"
#include "template.cpp"
#include "friendfunction.cpp"
#include "sach.cpp"
#include "user.cpp"
#include <iostream>
#include <fstream>

DSLK<Node<Sach>> sachlist;
DSLK<Node<User>> userlist;

// LibraryHandler

LibraryHandler::LibraryHandler()
{
    file_destination = "sachbase.txt";
}

bool LibraryHandler::readFromFile()
{
    ifstream inp(file_destination);
    readFile(inp, sachlist);
    inp.close();
}

bool LibraryHandler::writeToFile()
{
    ofstream out(file_destination);
    writeFile(out, sachlist);
    out.close();
}

bool LibraryHandler::inputNew()
{
    // Ham nhap them sach moi tu ban phim;
    Sach newbook;
    cin >> newbook;
    string last_id = sachlist.getTail()->getData().getID();
    newbook.setID(increment(last_id));
    return sachlist.insert(newbook);
    // neu them thanh cong tra ve 1, them that bai tra ve 0
}

bool LibraryHandler::updateExisted()
{
    string target_id;
    cout << "Nhap id sach muon chinh sua: ";
    cin >> target_id;
    try
    {
        Sach &target = sachlist.find_id<Sach>(target_id);
        cout << "Tim thay sach:\n"
             << target << '\n';
        cout << "Nhap thong tin chinh sua\n";
        cin >> target;
        return 1;
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay sach co ID da nhap\n";
        return 0;
    }
}

bool LibraryHandler::removeExisted()
{
    string target_id;
    cin >> target_id;
    try
    {
        Sach &target = sachlist.find_id<Sach>(target_id);
        cout << "Ban chac chan muon xoa sach sau?\n"
             << target << '\n';
        cout << "Nhap Y/N: ";
        char inp;
        switch (inp)
        {
        case 'Y':
        {
            sachlist.remove(target);
            return 1;
        }
        case 'N':
        {
            cout << "Quay lai menu\n";
            return 0;
        }
        default:
            break;
        }
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay sach co ID da nhap\n";
        return 0;
    }
}

// UserbaseHandler;
UserbaseHandler::UserbaseHandler()
{
    file_destination = "userbase.txt";
}
bool UserbaseHandler::inputNew()
{
    User newbook;
    cin >> newbook;
    string last_id = userlist.getTail()->getData().getID();
    newbook.setID(increment(last_id));
    return userlist.insert(newbook);
}
bool UserbaseHandler::updateExisted()
{
    cout<<"Nhap thong tin nguoi dung muon chinh sua:\n";
    string target_id;
    cin >> target_id;
    try
    {
        User &target = userlist.find_id<User>(target_id);
        cout << "Tim thay nguoi dung:\n"
             << target << '\n';
        cout << "Nhap thong tin chinh sua\n";
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
bool UserbaseHandler::removeExisted()
{
    string target_id;
    cin >> target_id;
    try
    {
        User &target = userlist.find_id<User>(target_id);
        cout << "Ban chac chan muon xoa nguoi dung sau:\n"
             << target << '\n';
        cout << "Nhap Y/N: ";
        char inp;
        switch (inp)
        {
        case 'Y':
        {
            userlist.remove(target);
            return 1;
        }
        case 'N':
        {
            cout << "Quay lai menu\n";
            return 0;
        }
        default:
            break;
        }
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            cout << "Khong tim thay nguoi dung co ID da nhap\n";
        return 0;
    }
}
bool UserbaseHandler::readFromFile()
{
    ifstream inp(file_destination);
    readFile(inp, userlist);
    inp.close();
}
bool UserbaseHandler::writeToFile()
{
    ofstream out(file_destination);
    writeFile(out, userlist);
    out.close();
}

// BorrowingHandler:
BorrowingHandler::BorrowingHandler()
{
    file_destination = "borrowing.txt";
}
bool BorrowingHandler::inputNew()
{
    string userid, sachid;
    int step = 0;
    try
    {
        cout << "Nhap id nguoi muon: ";
        cin >> userid;
        User &borrower = userlist.find_id<User>(userid);
        step = 1;
        cout << "Nhap id sach muon muon: ";
        cin >> sachid;
        Sach &target = sachlist.find_id<Sach>(sachid);
        return borrowBook(borrower, target);
        // muon thanh cong tra ve 1, that bai tra ve 0
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            if (step == 0)
                cout << "Khong tim thay nguoi dung\n";
            else
                cout << "Khong tim thay sach\n";
        return 0;
    }
}
bool BorrowingHandler::updateExisted()
{
    // instead show borrowing information of a book:

    return 1;
}
bool BorrowingHandler::removeExisted()
{
    string userid, sachid;
    int step = 0;
    try
    {
        cout << "Nhap id nguoi muon sach: ";
        cin >> userid;
        User &borrower = userlist.find_id<User>(userid);
        step = 1;
        cout << "Nhap id sach muon tra: ";
        cin >> sachid;
        Sach &target = sachlist.find_id<Sach>(sachid);
        return returnBook(borrower, target);
        // tra thanh cong tra ve 1, that bai tra ve 0
    }
    catch (int &exc)
    {
        if (exc == MEMBER_NOTFOUND)
            if (step == 0)
                cout << "Khong tim thay nguoi dung\n";
            else
                cout << "Khong tim thay sach\n";
        return 0;
    }
}
bool BorrowingHandler::readFromFile()
{
    ifstream inp(file_destination);
    readBorrowlist(inp, userlist, sachlist);
    inp.close();
}
bool BorrowingHandler::writeToFile()
{
    ofstream out(file_destination);
    saveBorrowlist(out, userlist);
    out.close();
}

OperationHandler *switcher(const int &i)
{
    switch (i)
    {
    case 0:
        return &LH;
    case 1:
        return &UH;
    case 2:
        return &BH;
    }
}

#endif