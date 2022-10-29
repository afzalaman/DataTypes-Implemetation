#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    
    private:
        vector<int> elements;
        int top;

    public:
        enum StackError 
        {
            EMPTY_Stack
        };

        void push(int a) 
        {
            elements.push_back(a);
            top = a;
        }
        void pop() throw (StackError)
        {   
            if (elements.size() == 0)
            {
                throw EMPTY_Stack;
            }
            elements.pop_back();
            if (elements.size() != 0)
            {
            top = elements[elements.size()-1];
            }
        }
        bool isEmpty() 
        {
            return elements.size() == 0;
        }
        int getTopElement() throw (StackError)
        {
            if (elements.size() == 0)
            {
                throw EMPTY_Stack;
            }
            return top;
        }
        vector<int> getAll()
        {
            return elements;
        }
        void setTop(int &a) throw (StackError)
        {
            if (elements.size() == 0)
            {
                throw EMPTY_Stack;
            }
            top = a;
        }
        int getSize()
        {
            return elements.size();
        }

        friend ostream& operator<<(ostream& os, const Stack& st)
        {
            os<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            os<<"Number of elements: " << st.elements.size() << "\nContent: " << endl;

            for (int i = 0 ; i< st.elements.size(); i++)
            {
                os << "[" << st.elements[i] << "] ";
            }
            os << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
            return os;
        }
        
};
