#include <iostream>
#include "Menu.hpp"
#include <sstream>
#define menuCount 6 ///number of menu items

//const int menuCount = 6;
using namespace std;

///Check if the given menuitem number exists
bool check(int a)
{
    return a>=0 && a<=menuCount;
}

void Menu::Run(){

    int val;
    do{
        val = MenuPrint();
        switch(val)
        {
            case 1:
                putIn();
                print();
                break;
            case 2:
                takeOut();
                print();
                break;
            case 3:
                max();
                print();
                break;
            case 4:
                isEmpty();
                print();
                break;
            case 5:
                print();
                break;
            case 6:
                loadTest();
                break;
            default:
                cout<<"\nGoodbye!\n";
                break;

        }
    }while(val != 0);
}

int Menu::MenuPrint(){

    int choice;
    
    cout<<"\n****************************************\n";
    cout<<"0. Exit\n";
    cout<<"1. Add Items\n";
    cout<<"2. Delete Items\n";
    cout<<"3. Query the maximum\n";
    cout<<"4. Is empty\n";
    cout<<"5. Print\n";
    cout<<"6. Load test (how many items we can put in)\n";
    cout<<"****************************************\n";
    ///felxible error msg
    // ostringstream s;
    // s << "choose a number between 0 and " << menuCount << "!";
    // string errmsg = s.str();
    // cout << errmsg << endl;
    ///read with read.hpp
    cout << "choose a number between 0 and " << menuCount << "!"<< endl;
    cin >> choice;

    return choice;
}

void Menu::putIn(){

    Item e;
    cout<<"Item:\n";
    cin >> e;
    Q.insert(e);
}

void Menu::takeOut(){
 int num ;
    cout << "Enter a num: ";
    cin >> num;
    try{
        Q.erase(num);
        cout<<"Success!\n"<<endl;
    }
    catch(heap::CustomExceptions err)
    {
        cerr<<"Take out is unsuccessful, the item does not exist!\n";
    }
}

void Menu::max() 
{

    Item e;
    bool error = false;
    try
    {
        e = Q.maxItem();
    }
    catch(heap::CustomExceptions err) 
    {
        error = true;
            cerr<<"Maximum cannot be checked as the heap is empty.\n";
    }
    if (!error) cout<<"Maximal element is:\n"<<e<<endl;
}

void Menu::isEmpty() {
    if(Q.isEmpty())
        cout<<"The heap is empty.\n";
    else
        cout<<"The heap is not empty.\n";
}

void Menu::print() 
{ 
    cout << Q; 
}

void Menu::loadTest()
{
    const int size=1000000000;
    heap Q;
    cout<<"Follow the current size of the queue:\n";
    try
    {
        for(int i=1; i<size; ++i)
        {
            if( i % 1000000 ==0 ) cout<<i<<endl;
            Q.insert(Item(i,"a"));
        }
    }
    catch(...)
    {
        cerr<<"Run out of memory!\n";
       // cerr<<"The size of the vector: "<<Q.size()<<endl;
    }
}