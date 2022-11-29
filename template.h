#ifndef TEMPLATE_H
#define TEMPLATE_H

//exception marks
#define MEMBER_NOTFOUND (int)1
#include <string>
using namespace std;


//Double linked list template implementation
template <class U>
class Node
{
private:
    U data;
    Node *next;
    Node *prev;

    //---------------
public:
    Node(const U&);
    Node *tonext();
    Node *toprev();
    U &getdata();
    void setnext(Node *);
    void setprev(Node *);
    ~Node();
};

class Sach;
class User;

template <class T>
class DSLK 
{
private:
    int size;
    T *head;
    T *tail;

public:
    // CRUD
    int getsize();
    T* gethead();
    T* gettail();
    DSLK(); //constructor
    ~DSLK();//destructor
    template <class U>
    bool insert(U &);//insert a member to the bottom
    template <class U>
    bool remove(U &);//find and remove a member
    template <class U> 
    T& update(U &);//update a member
    template <class U>
    T *find(U &);
    T& last();
    void display();//display the list
};  

#endif