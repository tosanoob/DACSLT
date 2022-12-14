#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <random>

std::string increment(std::string &input)
{
    int len = input.length() - 1;
    for (int i = len; i >= 0; i--)
    {
        if (input[i] == '9')
        {
            input[i] = '0';
            continue;
        }
        input[i] += 1;
        break;
    }
    return input;
}

void userGenerator(const int &amount)
{
    std::string des = "userbase.txt";
    std::ofstream out(des);
    std::string baseID = "00001";
    for (int i = 1; i <= amount; i++)
    {
        out << baseID << '|' << "User No." << i << '|';
        std::string cmd = std::to_string(i);
        for (int j = 0; j < 9 - cmd.length(); j++)
            out << '0';
        baseID = increment(baseID);
        out << i << '\n';
    }
    out.close();
}

void bookGenerator(const int &amount)
{
    std::string des = "sachbase.txt";
    std::ofstream out(des);
    std::string baseID = "000001";
    for (int i = 1; i <= amount; i++)
    {
        out << baseID << '|' << "Book No." << i << '|' << "Author No." << i << '|' << rand() % 3 + 1 << '\n';
        baseID = increment(baseID);
    }
    out.close();
}

void borrowlistGenerator(const int &bookAmount, const int &userAmount, const int &number)
{
    std::string des = "borrowing.txt";
    std::ofstream out(des);
    bool save[bookAmount + 2][userAmount + 2] = {0};
    for (int i = 0; i < number; i++)
    {
        int user = 1;
        int book = 1;
        srand(i);
        do
        {
            user = rand() % userAmount + 1;
            book = rand() % bookAmount + 1;
            if (save[book][user]==0)
                break;
        } while (1);

        std::string userID = std::to_string(user);
        for (int j = 0; j < 5 - userID.length(); j++)
            out << '0';
        out << userID << '|';
        std::string bookID = std::to_string(book);
        for (int j = 0; j < 6 - bookID.length(); j++)
            out << '0';
        out << bookID << '\n';
        save[book][user]=1;
        std::cout<<book<<'|'<<user<<'\n';
    }
    out.close();
}

int main()
{
    int userAmount,bookAmount,borrowAmount;
    system("cls");
    /*
    std::cout<<"Tu tao test\n";
    std::cout<<"So user: ";
    std::cin>>userAmount;
    std::cout<<"So sach: ";
    std::cin>>bookAmount;
    std::cout<<"So sach dang duoc muon: ";
    std::cin>>borrowAmount;
    
    userGenerator(userAmount);
    bookGenerator(bookAmount);
    */
    borrowlistGenerator(50,30,60);
    std::cout<<"succeed";
    system("pause");
    return 0;
}