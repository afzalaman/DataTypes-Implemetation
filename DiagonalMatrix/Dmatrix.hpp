#pragma once
#include <iostream>
#include <vector>

using namespace std;
//Class of two blocks matrices


class Dmatrix {
public:
    enum Exceptions
    {
        OVERINDEXED, NULLPART, DIFFERENT, INVALID
    };

    Dmatrix()
    {
         _v.clear();
         b1=0;
         b2=0;
    }
    Dmatrix(int k,int l);

    //~Dmatrix() { } 

    Dmatrix(int k,int l,const vector<int> &v);
    Dmatrix(const Dmatrix& a);

    Dmatrix &operator=(const Dmatrix& a);

    int getSize() const 
    {
        return _v.size();
    }
    int getMsize() const
    {
        return b1+b2;
    }

    bool inBlock(int i, int j) const;
    void reSize(int k,int l);
    int getElement(int i, int j) const ;
    void setElement(int i, int j, int e);
    //int operator()(int i, int j) const;
    //int& operator()(int i, int j); //can be used in place of getters and setters 
    friend Dmatrix operator+ (const Dmatrix& a, const Dmatrix& b);
    friend Dmatrix operator* (const Dmatrix& a, const Dmatrix& b);

    int ind(int i, int j) const;
    friend istream& operator>> (istream& s, Dmatrix& a);
    friend ostream& operator<< (ostream& s, const Dmatrix& a);
private:
    vector<int> _v;
    int b1,b2;
};
