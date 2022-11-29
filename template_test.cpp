#include "template.cpp"
#include <iostream>
using namespace std;

class Num {
    int num;

    public:
    Num(int n) : num(n) {}
    Num(const Num& a) : num(a.num) {}
    bool operator == (const Num& comp) {
        return (num==comp.num);
    }
    void update() {
        cin>>num;
        cout<<"updated\n";
    }
    void setnum(int n) {
        num=n;
    }
    friend ostream& operator << (ostream& out, const Num& o);
    ~Num(){}
};

ostream& operator << (ostream& out, const Num& o) {
    cout<<o.num;
}

int main() {
    Num a(5);
    Num* ptr = &a;
    DSLK<Node<Num>> handle;
    DSLK<Node<Num*>> ptrlist;
    handle.insert(a);
    ptrlist.insert(ptr);

    a.setnum(10);
    handle.insert(a);
    ptrlist.insert(ptr);

    a.setnum(11);
    handle.insert(a);
    ptrlist.insert(ptr);

    a.setnum(16);
    handle.insert(a);
    ptrlist.insert(ptr);

    cout<<"handle\n";
    handle.display();
    ptrlist.display();
    return 0;
}