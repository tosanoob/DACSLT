#ifndef TEMPLATE_CPP
#define TEMPLATE_CPP

#include "../DACSLT3/Header/template.h"
#include <iostream>
using namespace std;

//methods of Node<U>
//U is a random data structure
template <class U>
Node<U> :: Node(const U &d) : data(d),next(NULL),prev(NULL) {}
template <class U>
Node<U>* Node<U> :: toNext() {return next;}
template <class U>
Node<U>* Node<U> :: toPrev() {return prev;}
template <class U>
void Node<U> ::setNext(Node<U> *a) {next=a;}
template <class U>
void Node<U> ::setPrev(Node<U> *a) {prev=a;}
template <class U>
Node<U>:: ~Node() {next=NULL;prev=NULL;}
template <class U>
U& Node<U>:: getData() {return data;}

//------------------------------------------------------

//methods of DSLK<T>
//T is an instantiation of Node<U>

template <class T>
int DSLK<T>:: getSize() {return size;}

template <class T>
T* DSLK<T>:: getHead() {return head;}

template <class T>
T* DSLK<T>:: getTail() {return tail;}

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
        if (temp->getData() == findvalue)
        {
            return temp;
        }
        temp = temp->toNext();
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
        tail->setNext(temp);
        temp->setPrev(tail);
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
        head = head->toNext();
        head->setPrev(NULL);
        delete temp;
        size--;
        // delete the head
        return 1;
    }
    else if (temp == tail)
    {
        tail = tail->toPrev();
        tail->setNext(NULL);
        delete temp;
        size--;
        // delete the tail
        return 1;
    }
    else
    {
        T *tempprev = temp->toPrev();
        T *tempnext = temp->toNext();
        tempprev->setNext(tempnext);
        tempnext->setPrev(tempprev);
        delete temp;
        size--;
        // delete at any other position
        return 1;
    }
}

template <class T>
template <class U>
U& DSLK<T> :: find_id (const string& lookid) {
    T* temp = head;
    for (int i =0;i<size;i++) {
        if (temp->getData().getID()==lookid) return temp->getData();
        temp = temp->toNext();
    }
    if (temp==NULL) throw MEMBER_NOTFOUND;
}

template <class T>
void DSLK<T>::display(const int& from, const int& to)
{
    T *temp = head;
    for (int i = 0;i<from;i++) 
    temp=temp->toNext(); 

    for (int i = from; i <= to; i++)
    {
        cout << temp->getData() << '\n';
        temp = temp->toNext();
    }
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
        temp = temp->toNext();
        delete tempsave;
    }
}

#endif