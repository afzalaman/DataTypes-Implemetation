// #ifndef MENU_H_INCLUDED
// #define MENU_H_INCLUDED
#pragma once
#include "heap.hpp"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void putIn();
        void takeOut();
        void max();
        void isEmpty();
        void print();
        void loadTest();
        heap Q;

};

// #endif // MENU_H_INCLUDED
