#pragma once
#include "Stack.hpp"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void pushIn();
        void popOut();
        void getTopElem();
        void isEmpty();
        void sizeOf();
        void print();
        void loadTest();
        
        Stack St;
};