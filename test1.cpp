#include <iostream>
#include <fstream>
#include "sach.cpp"
#include "user.cpp"
#include "template.cpp"
#include "friendfunction.cpp"
using namespace std;

int main()
{
    ifstream inp_user("userbase.txt");
    ifstream inp_sach("sachbase.txt");
    ifstream inp_borrowing("borrowing.txt");

    DSLK<Node<Sach>> sachlist;
    DSLK<Node<User>> userlist;
    readFile(inp_user, userlist);
    readFile(inp_sach, sachlist);
    readBorrowlist(inp_borrowing,userlist,sachlist);
    cout<<"read success\n";

    //writenew
    inp_borrowing.close();
    inp_user.close();
    inp_sach.close();

    cout<<userlist.find_id<User>("00004");
    /*
    ofstream out_borrowing("borrowing.txt");
    save_borrowlist(out_borrowing, userlist);
    cout<< "save borrowList success\n";

    ofstream out_user("userbase.txt");
    ofstream out_sach("sachbase.txt");
    write_file(out_sach, sachlist);
    write_file(out_user, userlist);
    */
    cout << "test success\n";
    return 1;
}