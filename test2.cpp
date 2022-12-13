#include <iostream>
// #include <conio.h>
#include <windows.h>
#include "Menu.cpp"
#include "operation.cpp"

int main()
{
    system("cls");
    ShowConsoleCursor(false);
    LH.readFromFile();
    UH.readFromFile();
    BH.readFromFile();
    operation_Handler *handler;

    do
    {
        int line = mainMenu.CtrlMenu();
        handler = switcher(line);
        mainMenu.deleteMenu();
        if (line == 0)
        {
            do
            {
                CLEARLINE;
                line = sachMenu.CtrlMenu();
                sachMenu.deleteMenu();
                HOME;
                // thuc hien lenh theo lua chon
                switch (line)
                {
                case 0:
                {
                    std::cout<<"In danh sach sach cho phep bam trai phai\n";
                    std::cout<<"Dang phat trien";
                    break;
                }
                case 1:
                {
                    std::cout << "Them sach\n";
                    if (handler->inputNew())
                        std::cout << "Them thanh cong\n";
                    else
                        std::cout << "Da co sach voi thong tin tuong tu\n";
                    break;
                }
                case 2:
                {
                    std::cout << "Xem/Sua thong tin sach\n";
                    if (handler->updateExisted())
                        std::cout << "Chinh sua hoan tat\n";
                    break;
                }
                case 3:
                {
                    std::cout << "Xoa sach\n";
                    if (handler->removeExisted())
                        std::cout << "Xoa thanh cong\n";
                    else
                        std::cout << "Xoa that bai\n";
                    break;
                }
                case 4:
                {
                    std::cout << "Quay lai mainmenu";
                    break;
                }
                }
                // cho phan hoi sau khi thuc hien lenh
                getch();
            } while (line != 4);
        }
        else if (line == 1)
            do
            {
                CLEARLINE;
                line = userMenu.CtrlMenu();
                userMenu.deleteMenu();
                HOME;
                // thuc hien lenh theo lua chon
                switch (line)
                {
                case 0:
                {
                    std::cout << "Them nguoi dung\n";
                    if (handler->inputNew())
                        std::cout << "Them thanh cong\n";
                    else
                        std::cout << "Da co nguoi dung voi thong tin tuong tu\n";
                    break;
                }
                case 1:
                {
                    std::cout << "Xem/Sua thong tin nguoi dung\n";
                    if (handler->updateExisted())
                        std::cout << "Chinh sua hoan tat\n";
                    break;
                }
                case 2:
                {
                    std::cout << "Xoa nguoi dung\n";
                    if (handler->removeExisted())
                        std::cout << "Xoa thanh cong\n";
                    else
                        std::cout << "Xoa that bai\n";
                    break;
                }
                case 3:
                {
                    std::cout << "Quay lai mainmenu";
                    break;
                }
                }
                // cho phan hoi sau khi thuc hien lenh
                getch();
            } while (line != 3);
        else if (line == 2)
            do
            {
                CLEARLINE;
                line = borrowMenu.CtrlMenu();
                borrowMenu.deleteMenu();
                HOME;
                // thuc hien lenh theo lua chon
                switch (line)
                {
                case 0:
                {
                    std::cout << "Muon sach\n";
                    if (handler->inputNew())
                        std::cout << "Muon thanh cong\n";
                    else
                        std::cout << "Muon that bai\n";
                    break;
                }
                case 1:
                {
                    std::cout << "Tra sach\n";
                    if (handler->removeExisted())
                        std::cout << "Tra sach hoan tat\n";
                    else
                        std::cout << "Tra sach that bai\n";
                    break;
                }
                case 2:
                {
                    std::cout << "Quay lai mainmenu";
                    break;
                }
                }
                // cho phan hoi sau khi thuc hien lenh
                getch();
            } while (line != 2);
        else
            break;
    } while (true);
    HOME;
    std::cout << "Ket thuc chuong trinh";
    getch();
    LH.writeToFile();
    UH.writeToFile();
    BH.writeToFile();
    return 0;
}
