#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;
struct Item
{
    ///public attributes
    int num;
    string data;

    Item()
    {
        this->num = 0;
        this->data = "";
    };
    Item(int k,string d)
    {
        num = k;
        data = d;
    };

    friend istream& operator>>(istream& is, Item& item){
        cout << "Num: ";
        is >> item.num ;
        cout<<"Data: ";
        is >> item.data;
        return is;
    }


    friend ostream& operator<<(ostream& os, const Item& item){
        os << "(" << item.num << "," << item.data << ")";
        return os;
    }

    
    bool operator==(const Item& b)
    {
         return (num == b.num && data == b.data);
    }

    bool operator>(const Item& b)
    {
         return num > b.num;
    }
    bool operator<(const Item& b)
    {
         return num < b.num;
    }
};

class heap
{
    public:

        enum CustomExceptions {ExistingItemException, NonExistingItemException, EmptyException};

        int count() const { return heapVector.size();}
        void insert(Item a) throw (CustomExceptions);
        void erase(int num) throw (CustomExceptions);
        Item maxItem() throw (CustomExceptions);
        void heapifyUp();
        void heapifyDown();
        bool isIn(int num) const;
        string &operator[](int num) throw (CustomExceptions);
        bool isEmpty() const {return heapVector.size()==0;}
        friend ostream& operator<<(ostream& s, const heap& m); ///print a line

        ///Methods for testing
        vector<Item> getItems() const;
        pair<bool,int> getCSearch(int num) const {return CSearch(num);}

    private:
        vector<Item> heapVector; 

        pair<bool,int> CSearch(int num) const;


        // a bunch of helping functions below  :)

        int getLeftChildIndex(int parentIndex)
        { 
            return 2 * parentIndex + 1;
        }
        int getRightChildIndex(int parentIndex)
        { 
            return 2 * parentIndex + 2;
        }
        int getParentIndex(int childIndex)
        {
            return (childIndex - 1) / 2;
        }

        bool hasLeftChild(int index) 
        {
            return getLeftChildIndex(index) < heapVector.size();
        }
        bool hasRightChild(int index)
        {
            return getRightChildIndex(index) < heapVector.size();
        }
        bool hasParent (int index) 
        {
            return getParentIndex (index) >= 0;
        }

        Item leftChild(int index) 
        {
            return heapVector[getLeftChildIndex(index)];
        }
        Item rightChild(int index) 
        { 
            return heapVector[getRightChildIndex(index)];
        }
        Item parent(int index) 
        {
            return heapVector[getParentIndex(index)];
        }

        void swap(int a, int b)
        {
            Item temp = heapVector[a];
            heapVector[a] = heapVector[b];
            heapVector[b] = temp;       
        }


};