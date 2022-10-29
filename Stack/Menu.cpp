#include <iostream>
#include "Menu.hpp"
#include <sstream>
#define menuCount 6

using namespace std;

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
                pushIn();
                print();
                break;
            case 2:
                popOut();
                print();
                break;
            case 3:
                getTopElem();
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
                sizeOf();
                print();
                break;
            case 7:
                loadTest();
                break;

            default:
                cout<<"\nGoodbye buddy!\n";
                break;
        }
    }while(val != 0);
}

int Menu::MenuPrint(){

    int choice;
    
    cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout<<"0. Exit\n";
    cout<<"1. Push in\n";
    cout<<"2. Pop out\n";
    cout<<"3. Get Top Element\n";
    cout<<"4. Is empty\n";
    cout<<"5. Print\n";
    cout<<"6. Size\n";
    cout<<"7. Load test (how many items we can put in)\n";
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    
    // ostringstream s;
    // s << "choose a number between 0 and " << menuCount << "!";
    // string errmsg = s.str();
    // cout << errmsg << endl;
    
    cout << "choose a number between 0 and " << menuCount << "!"<< endl;

    cin >> choice;

    return choice;
}

void Menu::pushIn()
{
    int e;
    cout<<"Element:\n";
    cin >> e;
    St.push(e);
}

void Menu::popOut()
{
    bool error = false;
    try
    {
        St.pop();
    }
    catch(Stack::StackError err)
    {
        error = true;
        if(err == Stack::EMPTY_Stack)
        {
            cerr<<"Pop out is unsuccessful, the stack is empty!\n";
        }
        else
        {
            cerr<<"Unknown error.\n";
        }
    }
    if(!error)
    {
         cout<<"Succesfull\n"<<endl;
    }
}

void Menu::getTopElem()
{
    int e;
    bool error = false;
    try
    {
        e = St.getTopElement();
    }
    catch(Stack::StackError err) 
    {
        error = true;
        if(err == Stack::EMPTY_Stack)
        {
            cerr<<"Top element cannot be extracted as the stack is empty.\n";
        }
        else
        {
            cerr<<"Unknown error.\n";
        }
    }
    if (!error) cout<<"Top element is:\n"<<e<<endl;
}

void Menu::isEmpty() 
{
    if(St.isEmpty())
    {
        cout<<"The Stack is empty.\n";
    }
    else
    {
        cout<<"The Stack is not empty.\n";
    }
}
void Menu::sizeOf()
{
    cout << "The size of the Stack is " << St.getSize() << endl;
}
void Menu::print() 
{ 
    cout << St; 
}
void Menu::loadTest()
{
    const int size=1000000000;
    cout<<"Follow the current size of the Stack:\n";
    try
    {
        for(int i=1; i<size; ++i)
        {
            if( i % 1000000 ==0 ) cout<<i<<endl;
            St.push(i);
        }
    }
    catch(...)
    {
        cerr<<"Run out of memory!\n";
        cerr<<"The size of the vector: "<<St.getSize()<<endl;
    }
}