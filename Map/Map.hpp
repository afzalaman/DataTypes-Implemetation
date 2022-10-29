#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;
struct Item
{
    int key;
    string data;

    Item()
    {
        this->key = 0;
        this->data = "";
    };
    Item(int k,string d)
    {
        key = k;
        data = d;
    };

    friend istream& operator>>(istream& is, Item& item){
        cout << "Key: ";
        is >> item.key ;
        cout<<"Data: ";
        is >> item.data;
        return is;
    }


    friend ostream& operator<<(ostream& os, const Item& item){
        os << "(" << item.key << "," << item.data << ")";
        return os;
    }

    
    bool operator==(const Item& b)
    {
         return (key == b.key && data == b.data);
    }

};

class Map
{
    public:

        enum CustomExceptions { ExistingKeyException, NonExistingKeyException};

        int count() const { return mapVector.size();}
        void insert(Item a);
        void erase(int key) throw (CustomExceptions);
        bool isIn(int key) const;
        string &operator[](int key) throw (CustomExceptions);
        bool isEmpty() const {return mapVector.size()==0;}
        friend ostream& operator<<(ostream& s, const Map& m); ///print a line

        ///Methods for testing
        vector<Item> getItems() const;
        pair<bool,int> getLogSearch(int key) const {return logSearch(key);}

    private:
        vector<Item> mapVector; // we are going to store all the map content on this vector

        pair<bool,int> logSearch(int key) const;

};
