#ifndef TEMPLATE_CPP
#define TEMPLATE_CPP

#include "template.h"
#include <iostream>
using namespace std;

//methods of Node<U>
//U is a random data structure
template <class U>
Node<U> :: Node(const U &d) : data(d),next(NULL),prev(NULL) {}
template <class U>
Node<U>* Node<U> :: tonext() {return next;}
template <class U>
Node<U>* Node<U> :: toprev() {return prev;}
template <class U>
void Node<U> ::setnext(Node<U> *a) {next=a;}
template <class U>
void Node<U> ::setprev(Node<U> *a) {prev=a;}
template <class U>
Node<U>:: ~Node() {next=NULL;prev=NULL;}
template <class U>
U& Node<U>:: getdata() {return data;}

//------------------------------------------------------

//methods of DSLK<T>
//T is an instantiation of Node<U>

template <class T>
int DSLK<T>:: getsize() {return size;}

template <class T>
T* DSLK<T>:: gethead() {return head;}

template <class T>
T* DSLK<T>:: gettail() {return tail;}

template <class T>
DSLK<T>:: DSLK() : head(NULL), tail(NULL), size(0) {}

template <class T> 
template <class U>
// this method finds a member with value "f",
// return the pointer to member if found, else return NULL
T *DSLK<T>::find(U &findvalue)
{
    T *temp = head;
    for (int i = 0; i < size; i++)
    {
        if (temp->getdata() == findvalue)
        {
            return temp;
        }
        temp = temp->tonext();
    }
    return NULL;
}

template <class T>
template <class U>
// this methods always insert to bottom.
bool DSLK<T>::insert(U &add)
{
    T *temp;
    if (size == 0)
    {
        temp = new T(add);
        head = temp;
        tail = temp;
        size++;
        // first member
        return 1;
    }
    else
    {
        if (find(add) != NULL)
            return 0;
        temp = new T(add);
        tail->setnext(temp);
        temp->setprev(tail);
        tail = temp;
        size++;
        // insert success
        return 1;
    }
}

template <class T>
template <class U>
// this method remove member with value rev from any position
bool DSLK<T>::remove(U &rev)
{
    T *temp = find(rev);
    if (temp == NULL)
    {
        // remove value not available, exit
        return 0;
    }
    else if (temp == head)
    {
        if (size == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            size = 0;
            // delete the only member
            return 1;
        }
        head = head->tonext();
        head->setprev(NULL);
        delete temp;
        size--;
        // delete the head
        return 1;
    }
    else if (temp == tail)
    {
        tail = tail->toprev();
        tail->setnext(NULL);
        delete temp;
        size--;
        // delete the tail
        return 1;
    }
    else
    {
        T *tempprev = temp->toprev();
        T *tempnext = temp->tonext();
        tempprev->setnext(tempnext);
        tempnext->setprev(tempprev);
        delete temp;
        size--;
        // delete at any other position
        return 1;
    }
}


template <class T>
template <class U>
// this method find the member with value "upd"
// then call .update() method of class T, to update the found member;
// if no member is found with value "upd", exit without updating.
T& DSLK<T>::update(U &upd)
{
    T *temp = find(upd);
    if (temp == NULL)
    {
        // no member found
        throw MEMBER_NOTFOUND;
    }
    else return *temp;
}



template <class T>
void DSLK<T>::display()
{
    T *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << temp->getdata() << '\n';
        temp = temp->tonext();
    }
}

template <class T>
T& DSLK<T>:: last() {
    return *tail;
}

/*
class T requirements for this method:
already have suitable destructor method;
*/
template <class T>
DSLK<T>::~DSLK()
{
    T *temp = head, *tempsave = head;
    for (int i = 0; i < size; i++)
    {
        tempsave = temp;
        temp = temp->tonext();
        delete tempsave;
    }
}

#endif