#pragma once
#include "Map.hpp"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void putIn();
        void takeOut();
        void isIn();
        void count();
        void print();
        void loadTest();
        Map M;

};