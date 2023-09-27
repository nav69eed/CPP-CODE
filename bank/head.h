#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void pincheck()
{
    int count = 3;
    string pin, pin1;
manue:
    cout << "Enter Pin\n";
    getline(cin, pin);
    count--;
    ifstream myfile("pin.txt");

    if (myfile.is_open())
    {
        getline(myfile, pin1);
        if (pin1 == pin)
        {
            cout << "Welcome";
        }
        else
        {
            cout << "You Entered wrong pin\n";
            cout << count << " Tries Left\n";
            if (count == 0)
            {
                cout << "Programm End\n";
                exit(0);
            }
            else
                goto manue;
        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
        return;
    }
}

// Balance Check

void balanceCheck()
{
    int b; // for balance
    ifstream balnce("balance.txt");
    if (balnce.is_open())
    {
        balnce >> b;
        cout << "**************\n\n";
        cout << b << " RS " << endl;
        balnce.close();
    }
    else
    {
        cout << "File Opening Error\n";
    }
}

//  for withdraw cash

void withDraw()
{
    int b, c; // b for existing balance c for withdraw

    ifstream balnce("balance.txt");
    if (balnce.is_open())
    {
        balnce >> b;
    bl:
        cout << "**************************\n\nEnter Cash to Withdraw\n";
        cin >> c;
        if ((c <= b) && (c % 500 == 0) && c > 0)
        {
            b = b - c;
            cout << "Please Collect Cash\n";
            balnce.close();
            ofstream outfile("balance.txt");
            if (outfile.is_open())
            {
                outfile << b;
                outfile.close();
            }
            else
            {
                cout << "Outfile opening error\n";
            }
        }

        else
        {
            cout << "balnce opening error";
            goto bl;
        }
    }
}

// for deposit cash

void deposit()
{
    int b, c;
    ifstream infile("balance.txt");

    if (infile.is_open())
    {
        infile >> c;
        infile.close();
    }
    else
    {
        cout << "Infile open Error\n";
    }
    ofstream outfile("balance.txt");

    if (outfile.is_open())
    {
    neg:
        cout << "*******************\n\nEnter Cash to Deposit\n";
        cin >> b;
        if (b > 0)
        {

            b = b + c;
            outfile << b;
            cout << "Deposited Successfully\n";
            outfile.close();
        }
        else
        {
            cout << "Cash Can't be Negetive\n\n\n";
            goto neg;
        }
    }
    else
    {
        cout << "Outfile open error\n";
    }
}

// change pin

void pinChange()
{
    string pin1, pin2, npin1, npin2;
    int op = 3, np = 3;
    ifstream infile("pin.txt");
    if (infile.is_open())
    {
        getline(infile, pin1);
        infile.close();
    }
oldpin:
    cout << "Enter Old Pin\n";
    cin.ignore();
    getline(cin, pin2);
    op--;
    if (pin1 == pin2)
    {
    newpin:
        cout << "Enter New Pin\n";
        //  cin.ignore();
        getline(cin, npin1);
        cout << "Enter New Pin again\n";
        // cin.ignore();
        getline(cin, npin2);
        np--;

        if (npin1 == npin2)
        {
            ofstream outfile("pin.txt");
            if (outfile.is_open())
            {
                outfile << npin1;
                cout << "Pin changed Succesfully\n";
                outfile.close();
            }
            else
            {
                cout << "Outfile open error\n";
            }
        }
        else
        {
            cout << "New Entered pin are not same\nTry again\n";
            cout << np << " tries left\n";
            if (np == 0)
            {
                cout << "Program is Exiting\n";
                exit(0);
            }
            goto newpin;
        }
    }
    else
    {
        cout << "Wrong Pin\nTry again\n";
        cout << op << " tries left\n";
        if (op == 0)
        {
            cout << "Program Exiting\n";
            exit(0);
        }
        goto oldpin;
    }
}