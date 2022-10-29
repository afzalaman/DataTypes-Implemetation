#include "heap.hpp"

using namespace std;


pair<bool,int> heap::CSearch(int num) const
{
    int indexx = -1;
    bool exists = false;
    for (int i=0 ; i<heapVector.size(); i++)
    {
        if (num == heapVector[i].num)
        {
            exists = true;
            indexx = i;
        }
    }
    return pair<bool,int>(exists,indexx);
}

void heap::insert(Item e) throw (CustomExceptions)
{
    pair<bool,int> out = CSearch(e.num);

    if (!out.first)
    {
        //heapVector.resize(heapVector.size()+1);
        heapVector.push_back(e);
        heapifyUp(); ///////////////////////////////////////to maintain heap property
    }
    else  throw ExistingItemException;
}

void heap::erase(int num) throw (CustomExceptions)
{ 

    pair<bool,int> out = CSearch(num);

    if (out.first) 
    {
        heapVector[out.second]=heapVector[heapVector.size()-1];
        heapVector.pop_back();
        heapifyDown(); ///////////////////////////////////////to maintain heap property
    }
    else throw NonExistingItemException;
}
Item heap::maxItem() throw (heap::CustomExceptions)
{
    if (heapVector.size() == 0 )
    {
        throw heap::EmptyException;
    }
    int ind = 0;
    for(unsigned i=1; i < heapVector.size(); i++)
    {
        if(heapVector[i]>heapVector[ind])
        {
        ind = i ;
        }
    }
        
    return heapVector[ind];
}
void heap::heapifyUp()
{
    int index = heapVector.size()-1;
    while (hasParent(index) && parent(index) > heapVector[index])
    {
        swap (getParentIndex(index),index);
        index = getParentIndex(index);
    }
}

void heap::heapifyDown()
{
    int index = 0;
    while (hasLeftChild(index))
    {
        int smallChildI = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) < leftChild(index))
        {
            smallChildI = getRightChildIndex(index);
        }
        if (heapVector[index] < heapVector[smallChildI])
        {
            break;
        }
        else
        {
            swap(index,smallChildI);
        }
        index = smallChildI;
    }
}

bool heap::isIn(int num) const{

    return CSearch(num).first;
}

string &heap::operator[](int num) throw (CustomExceptions)
{ 

    pair<bool,int> out = CSearch(num);

    if (out.first) return heapVector[out.second].data;

    else throw NonExistingItemException;
    
}

ostream& operator<<(ostream& s, const heap& m) 
{

    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s << "Number of elements: " << m.heapVector.size() << "\nContent: " << endl;
    for(unsigned i = 0; i < m.heapVector.size(); ++i){
        s << " " << m.heapVector[i];
    }
    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

vector<Item> heap::getItems() const 
{
    vector<Item> v;
    for(unsigned i=0; i<heapVector.size(); ++i) v.push_back(heapVector[i]);

    return v;
}
