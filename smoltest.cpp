#include <iostream>
using namespace std;


int main() {
    int a,b,c;
    b = 5;
    a = 3;
    c=(a++)+++b;
    cout<<c<<'\n';
    cout<<a<<'\n';
    cout<<b<<'\n';
}