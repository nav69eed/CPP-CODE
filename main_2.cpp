#include <iostream>
#include <fstream>
//#include <conio.h>
#include <string>
#include "head.h"
using namespace std;
int main()
{
    int choice;
    cout << "Welcome to bank\n";
    pincheck();
choose:
    cout << "\n\n**********************************\n\n";
    cout << "Enter Choice\n";
    cout << "1.Check Balance\n";
    cout << "2.Withdraw Cash\n";
    cout << "3.Deposit Money\n";
    cout << "4.Change Pin\n";
    cin >> choice;
    if (choice == 1)
    {
        balanceCheck();

        goto choose;
    }
    else if (choice == 2)
    {
        withDraw();
        goto choose;
    }
    else if (choice == 3)
    {
        deposit();
        goto choose;
    }
    else if (choice == 4)
    {
        pinChange();
        goto choose;
    }
    else
    {
        cout << "Invalid Input\n";
        goto choose;
    }
    cin.ignore();
    cin.get();

    return 0;
}