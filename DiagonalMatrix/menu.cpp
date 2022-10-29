#include <iostream>
#include "menu.hpp"
#include <sstream>
#define menuCount 6

using namespace std;

bool check(int a)
{
    return a>=0 && a<=menuCount;
}

void Menu::Run(){

    int val;
    do
    {
        val = menuPrint();
        switch(val)
        {
        case 1:
            get();
            break;
        case 2:
            set();
            break;
        case 3:
            read();
            break;
        case 4:
            write();
            break;
        case 5:
            sum();
            break;
        case 6:
            mul();
            break;
        case 0:
            cout<<"\nGood Bye!\n";
            break;
        default:
            cout<<"\nINVALID Choice!\n";
        }
    }
    while(val!=0);
}

int Menu::menuPrint()
{

    int choice;

    cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout<<"0. Exit\n";
    cout<<"1. Get an element of the matrix\n";
    cout<<"2. Overwrite an element of the matrix\n";
    cout<<"3. Read matrix\n";
    cout<<"4. Print matrix\n";
    cout<<"5. Add matrices\n";
    cout<<"6. Multiply matrices\n";
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    
    // ostringstream s;
    // s << "choose a number between 0 and " << menuCount << "!";
    // string errmsg = s.str();
    // cout << errmsg << endl;
    
    cout << "choose a number between 0 and " << menuCount << "!"<< endl;

    cin >> choice;

    return choice;
}


void Menu::get() const
{
    int i,j;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the column: ";
    cin >> j;
    try
    {
        cout << "a[" << i << "," << j << "]= " << a.getElement(i-1,j-1) << endl;
    }
    catch(Dmatrix::Exceptions ex)
    {
        if(ex == Dmatrix::OVERINDEXED)
            cout << "Overindexing!" << endl;
        else
            cout << "Unhandled exception!" << endl;
    }
}

void Menu::set()
{
    int i,j,e;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the column: ";
    cin >> j;
    cout << "Give the value: ";
    cin >> e;
    try
    {
        a.setElement(i-1,j-1,e);
    }
    catch(Dmatrix::Exceptions ex)
    {
        if(ex == Dmatrix::OVERINDEXED)
            cout << "Overindexing!" << endl;
        if (ex == Dmatrix::NULLPART)
            cout << "These indexes do not point to the Diagonal blocks!" << endl;
    }
}

void Menu::read()
{
    try
    {
        cout << "Give the size of block 1 and block 2 of the matrix and then give elements at the below indexes : \n";
        cin >> a;
    }
    catch(Dmatrix::Exceptions ex)
    {
        if(ex == Dmatrix::INVALID)
            cout << "Invalid size!" << endl;
        else
            cout << "Unhandled exception!" << endl;
    }
}

void Menu::write()
{
    cout << a << endl;
}

void Menu::sum()
{
    try
    {
        Dmatrix b;

        cout << "Give the size and the items of the second matrix: " << endl;
        cin >> b;
        cout << "Sum of the matrices: " << endl;
        cout << a + b << endl;
    }
    catch(Dmatrix::Exceptions ex)
    {
        if(ex == Dmatrix::INVALID)
            cout << "Invalid size!" << endl;
        if(ex == Dmatrix::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}

void Menu::mul()
{
    try
    {
        Dmatrix b;

        cout << "Give the size and the items of the second matrix: " << endl;
        cin >> b;
        cout << "Product of the matrices: " << endl;
        cout << a * b << endl;
    }
    catch(Dmatrix::Exceptions ex)
    {
        if(ex == Dmatrix::INVALID)
            cout << "Invalid size!" << endl;
        if(ex == Dmatrix::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}