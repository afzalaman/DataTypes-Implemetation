#pragma once
#include "Dmatrix.hpp"

class Menu
{
    public:
       Menu() : a(0,0){};
        void Run();
    private:
        int menuPrint();
        void get() const;
        void set();
        void read();
        void write();
        void sum();
        void mul();
        
        Dmatrix a;
};