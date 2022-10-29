#include "Dmatrix.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

//Task: 	constructor with size of the two blocks
//Input:    int k,int l    - the new size
//Output:   Dmatrix this - default matrix
//Activity: creates the array of the block of size k and size l
Dmatrix::Dmatrix(int k,int l)
{   b1=k;
    b2=l;
    if (k < 0 || l < 0)
    {
         throw INVALID;
    }
    _v.clear();
    _v.resize((k*k)+(l*l));
}

//Task: 	constructor the elements of the block and size b1 and b2
//Input:    int k,int l,vector<int> v     - the new blocks and a vector
//Output:   Dmatrix this         - default matrix
//Activity: creates the array of the two block matrix and fills in its elements based on vector v
Dmatrix::Dmatrix(int k,int l,const vector<int> &v)
{   
    b1=k;
    b2=l;
    _v = v;
}

//Task: 	copy constructor
//Input:    Dmatrix a    - matrix
//Output:   Dmatrix this - default matrix
//Activity: creates the array of the two blocks matrix and fills in its elements based on matrix a
Dmatrix::Dmatrix(const Dmatrix& a)
{
     b1=a.b1;
    b2=a.b2;
    int s = a.getSize();
    _v.resize(s);
    for(int i = 0; i < s; ++i)
    {
     _v[i] = a._v[i];
    }
}

//Task: 	assignment operator
//Input:    Dmatrix a    - matrix
//Output:   Dmatrix this - default matrix
//Activity: fills in the elements of the two blocks matrix based on matrix a
Dmatrix &Dmatrix::operator=(const Dmatrix& a)
{   
    b1=a.b1;
    b2=a.b2;
    int s = a.getSize();
    _v.resize(s);
    for(int i = 0; i < s; ++i)
    {
     _v[i] = a._v[i];
    }
    return *this;
}

//Task: 	resizing a matrix
//Input:    int k,int l    - the new sizes
//Output:   Dmatrix this - default matrix
//Activity: resizes the matrix to k ,l
void Dmatrix::reSize(int k,int l)
{
    if(k <= 0 || l <= 0)
    {
         throw INVALID;
    }
    b1=k;
    b2=l;
    _v.resize((k*k)+(l*l));
    
}

//Task: 	adding
//Input:    Dmatrix a    - matrix
//          Dmatrix b    - matrix
//Output:   Dmatrix      - result matrix
//Activity: adds the elements of the blocks of the matrices
Dmatrix operator+(const Dmatrix& a ,const Dmatrix& b)
{
    int s = a.getSize();
    if(s != b.getSize())
    { 
        throw Dmatrix::DIFFERENT;
    }

    Dmatrix c(a);

    for(int i = 0; i <s;i++)
    {
        c._v[i] += b._v[i];
    }
    return c;
}

//Task: 	inBlock
//Input:    int i, int j    - row columm index
//Output:   Bool      - Boolean value
//Activity: check whether the i j is in block area 
bool Dmatrix::inBlock(int i, int j) const
{
    return ((i < b1 && j < b1) || (i >= b1 && j >= b1 && (i <= b1+b2 && j <= b1+b2)));
}

//Task: 	multiplying
//Input:    Dmatrix a    - matrix
//          Dmatrix b    - matrix
//Output:   Dmatrix      - result matrix
//Activity: multiplies the elements of the blocks of the matrices
Dmatrix operator*(const Dmatrix& a ,const Dmatrix& b)
{
    int s = a.getSize();
    if(s != b.getSize())
    {
        throw Dmatrix::DIFFERENT;
    }

    Dmatrix c(a.b1,a.b2);

     for (int i=0;i<a.getMsize();i++)
        {
            for (int j=0;j<a.getMsize();j++)
            {
                if (a.inBlock(i,j)) /// only the block part need calculation
                {
                    for (int k=0;k<a.getMsize();k++)
                    {
                        c.setElement(i,j,c.getElement(i,j)+a.getElement(i,k)*b.getElement(k,j));
                    }
                }
            }
        }
    return c;
}

//Task: 	writing
//Input:    ostream os - target of writing
//          Dmatrix a     - matrix
//Output:   ostream os - target of writing
//Activity: writes the elements of the matrix
ostream& operator<<(ostream& os, const Dmatrix& a)
{
    int s = a.getMsize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++)
            os << setw(5) << a.getElement(i,j);
        os << endl;
    }
    return os;
}

//Task: 	reading
//Input:    istream is - source of writing
//          Dmatrix a     - matrix
//Output:   istream is - source of writing
//Activity: reads the elements of the block of the matrix
istream& operator>>(istream& is, Dmatrix& a)
{
    int k,l;
    int n;
    is >> k ;
    is >> l;
    a.reSize(k,l);
        for(int i = 0; i < (k+l);i++)
        {
        for(int j = 0; j < (k+l);j++)
        {
        if (a.inBlock(i,j))
        {
        cout << "[" << i+1 << "," << j+1 << "]=";
        is >> n;
        a.setElement(i,j,n);
        }
        }
    }
    cout<<endl;
    return is;
}

//Task: 	indexing
//Input:    int i,j - indices of the matrix
//Output:   int  - gives the index of the vector
//Activity: gives the index of the vector besed on on i & j indices of the matrix
int Dmatrix::ind(int i, int j) const
{
    if (inBlock(i,j))
    {
        int n = getMsize();
        if (i < b1 && j < b1)
        {
            return ((i*(n-b2))+j);
        }
        else
        {
            return (((b1*b1)-1)+((i-b1)*(n-b1))+(j-b1+1));
        }
    }
    else
    {
        throw INVALID;
    }
}

//Task: 	getting
//Input:    int i,j - indexes of the element
//Output:   int     - the element of the matrix in the ith row and jth column
//Activity: gets the given element of the block matrix
int Dmatrix::getElement(int i, int j) const
{   
    int n = getMsize();
    if ((i >= n || j >= n ) || (i < 0 || j < 0 ))
    {
         throw OVERINDEXED;
    }
    else if (inBlock(i,j))
    {
       return _v[ind(i,j)];
    }
    else
    {
        return 0; // in the null part 
    }
}

//Task: 	setting
//Input:    int i,j - indexes of the element
//Output:   int     - the element of the matrix in ith row and jth column
//Activity: set the given value to the ith row and jth column of the block matrix
void Dmatrix::setElement(int i, int j,int e)
{   
    int n = getMsize();
    if ((i >= n || j >= n ) || (i < 0 || j < 0 ))
    {
         throw OVERINDEXED;
    }
    else if(!inBlock(i,j))
    {
        throw NULLPART;
    }
    else
    {
        _v[ind(i,j)] = e;
    }
}

//we can also use the following in placeof the getters and setters:-
// int Dmatrix::operator()(int i, int j) const
// {
//     int s = getMsize();
//     if ((i >= s || i < 0 ) || (j >= s || j < 0 )) throw OVERINDEXED;
//     if (!inBlock(i,j)) return 0;
//     return _v[ind(i,j)];
// }

// int& Dmatrix::operator()(int i, int j)
// {
//     int s = getMsize();
//     if ((i >= s || i < 0 ) || (j >= s || j < 0 )) throw OVERINDEXED;
//     if (!inBlock(i,j)) throw NULLPART;
//     return _v[ind(i,j)];
// }