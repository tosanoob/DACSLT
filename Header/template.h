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
    Node *toNext();
    Node *toPrev();
    U &getData();
    void setNext(Node *);
    void setPrev(Node *);
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
    int getSize();
    T* getHead();
    T* getTail();
    DSLK(); //constructor
    ~DSLK();//destructor
    template <class U>
    bool insert(U &);//insert a member to the bottom
    template <class U>
    bool remove(U &);//find and remove a member
    template <class U>
    T *find(U &);
    template <class U>
    U& find_id(const string&);
    void display(const int&,const int&);//display the list
};  

#endif