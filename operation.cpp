#ifndef OPERATION_CPP
#define OPERATION_CPP

#include "../DACSLT3/Header/operation.h"
#include "template.cpp"
#include "Menu.cpp"
#include "friendfunction.cpp"
#include "sach.cpp"
#include "user.cpp"
#include <iostream>
#include <fstream>

DSLK<Node<Sach>> bookList;
DSLK<Node<User>> userList;

bool OperationHandler::setDestination(const string &dest)
{
    fileDestination = dest;
}

// LibraryHandler

LibraryHandler::LibraryHandler()
{
    fileDestination = "./File_txt/sachbase.txt";
}

bool LibraryHandler::readFromFile()
{
    ifstream inp(fileDestination);
    readFile(inp, bookList);
    inp.close();
}

bool LibraryHandler::writeToFile()
{
    ofstream out(fileDestination);
    writeFile(out, bookList);
    out.close();
}

bool LibraryHandler::inputNew()
{
    // Ham nhap them sach moi tu ban phim;
    Sach newBook;
    cin >> newBook;
    string last_id = bookList.getTail()->getData().getID();
    newBook.setID(increment(last_id));
    switch (bookList.insert(newBook)) {
        case 0: {
            try {
                Node<Sach>* temp = bookList.find(newBook);
                temp->getData().append(newBook);
                return 0;
            } 
            catch (int& exc) {
                if (exc == MEMBER_NOTFOUND) cout<<"Khong tim thay sach??\n";
                else cout<<"Loi khac?\n";
                return 0;
            }
            catch (...) {
                cout<<"Pointer to NULL\n";
                return 0;
            }
        }
        case 1: return 1;
    }
    // neu them thanh cong tra ve 1, them that bai tra ve 0
}

bool LibraryHandler::updateExisted()
{
    string target_id;
    cout << "Nhap ID sach muon chinh sua: ";
    cin >> target_id;
    try
    {
        Sach &target = bookList.find_id<Sach>(target_id);
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
    try
    {   
        cout<<"Nhap ID sach muon xoa: ";
        cin >> target_id;
        Sach &target = bookList.find_id<Sach>(target_id);
        cout << "Ban chac chan muon xoa sach sau?\n"
             << target << '\n';
        cout << "Nhap Y/N: ";
        char inp;
        cin >> inp;
        switch (inp)
        {
        case 'Y':
        {
            bookList.remove(target);
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

bool libraryDisplay()
{
    int size = bookList.getSize();
    int bookPerPage = 15;
    int anchor = 0;
    while (true)
    {
        system("cls");
        HOME;
        cout << "Nhan nut mui ten trai/phai de chuyen danh sach\n";
        cout << "Nhan ESC de quay lai\n";
        if (anchor + bookPerPage > size)
        {
            bookList.display(anchor, size - 1);
            cout << "\nCuoi danh sach\n";
        }
        else
            bookList.display(anchor, anchor + bookPerPage - 1);
        int keyGet = move();
        switch (keyGet)
        {
        case RIGHT:
        {
            if (anchor + bookPerPage <= size)
                anchor += bookPerPage;
            break;
        }
        case LEFT:
        {
            if (anchor - bookPerPage >= 0)
                anchor -= bookPerPage;
            break;
        }
        case ESCAPE:
        {
            clearScreen();
            return 1;
        }
        default:
            break;
        }
    }
}

bool userDisplay()
{
    int size = userList.getSize();
    int userPerPage = 15;
    int anchor = 0;
    while (true)
    {
        system("cls");
        HOME;
        cout << "Nhan nut mui ten trai/phai de chuyen danh sach\n";
        cout << "Nhan ESC de quay lai\n";
        if (anchor + userPerPage > size)
        {
            userList.display(anchor, size - 1);
            cout << "\nCuoi danh sach\n";
        }
        else
            userList.display(anchor, anchor + userPerPage - 1);
        int keyGet = move();
        switch (keyGet)
        {
        case RIGHT:
        {
            if (anchor + userPerPage <= size)
                anchor += userPerPage;
            break;
        }
        case LEFT:
        {
            if (anchor - userPerPage >= 0)
                anchor -= userPerPage;
            break;
        }
        case ESCAPE:
        {
            clearScreen();
            return 1;
        }
        default:
            break;
        }
    }
}

// UserbaseHandler;
UserbaseHandler::UserbaseHandler()
{
    fileDestination = "./File_txt/userbase.txt";
}
bool UserbaseHandler::inputNew()
{
    User newUser;
    cin >> newUser;
    string last_id = userList.getTail()->getData().getID();
    newUser.setID(increment(last_id));
    return userList.insert(newUser);
}
bool UserbaseHandler::updateExisted()
{
    cout << "Nhap ID nguoi dung muon chinh sua:";
    string target_id;
    cin >> target_id;
    try
    {
        User &target = userList.find_id<User>(target_id);
        cout << "Tim thay nguoi dung:\n"
             << target << '\n';
        cout << "Nhap thong tin chinh sua\n";
        cin >> target;
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
    try
    {   cout<<"Nhap ID nguoi dung muon xoa: ";
        cin >> target_id;
        User &target = userList.find_id<User>(target_id);
        cout << "Ban chac chan muon xoa nguoi dung sau:\n"
             << target << '\n';
        cout << "Nhap Y/N: ";
        char inp;
        cin >> inp;
        switch (inp)
        {
        case 'Y':
        {
            userList.remove(target);
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
    ifstream inp(fileDestination);
    readFile(inp, userList);
    inp.close();
}
bool UserbaseHandler::writeToFile()
{
    ofstream out(fileDestination);
    writeFile(out, userList);
    out.close();
}

// BorrowingHandler:
BorrowingHandler::BorrowingHandler()
{
    fileDestination = "./File_txt/borrowing.txt";
}
bool BorrowingHandler::inputNew()
{
    string userid, sachid;
    int step = 0;
    try
    {
        cout << "Nhap id nguoi muon: ";
        cin >> userid;
        User &borrower = userList.find_id<User>(userid);
        step = 1;
        cout << "Nhap id sach muon muon: ";
        cin >> sachid;
        Sach &target = bookList.find_id<Sach>(sachid);
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
    string target_id;
    // instead show borrowing information of a book/user:
        system("cls");
        int line = borrowInfoMenu.ctrlMenu();
        borrowInfoMenu.deleteMenu();
        HOME;
        switch (line)
        {
        case 0:
        {
            try
            {
                cout << "Nhap ID sach: ";
                cin >> target_id;
                Sach &target = bookList.find_id<Sach>(target_id);
                cout << "Tim thay sach\n";
                cout << target << '\n';
                cout << "Danh sach nguoi dung dang muon sach:\n";
                target.borrowList();
                getch();
                break;
            }
            catch (int &exc)
            {
                cout << "Khong tim thay sach co ID " << target_id << '\n';
                return 0;
            }
        }
        case 1:
        {
            try
            {
                cout << "Nhap ID nguoi dung: ";
                cin >> target_id;
                User &target = userList.find_id<User>(target_id);
                cout << "Tim thay nguoi dung\n";
                cout << target << '\n';
                cout << "Danh sach sach nguoi dung nay dang muon:\n";
                target.borrowList();
                getch();
                break;
            }
            catch (int &exc)
            {
                cout << "Khong tim thay nguoi dung co ID " << target_id << '\n';
                return 0;
            }
        }
        case 2:
            return 1;
        }
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
        User &borrower = userList.find_id<User>(userid);
        step = 1;
        cout << "Nhap id sach muon tra: ";
        cin >> sachid;
        Sach &target = bookList.find_id<Sach>(sachid);
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
    ifstream inp(fileDestination);
    readBorrowlist(inp, userList, bookList);
    inp.close();
}
bool BorrowingHandler::writeToFile()
{
    ofstream out(fileDestination);
    saveBorrowlist(out, userList);
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