#include <iostream>
#include "Dmatrix.hpp"
#include "menu.hpp"
#include <fstream>

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    Menu m;
    m.Run();

}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>

TEST_CASE("create", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Dmatrix c;
    in >> c;
    CHECK(c.getElement(0,0) == 2);
    CHECK(c.getElement(0,1) == 4);
    CHECK(c.getElement(0,2) == 2);
    CHECK(c.getElement(1,0) == 6);
    CHECK(c.getElement(1,1) == 2);
    CHECK(c.getElement(1,2) == 5);
    CHECK(c.getElement(2,0) == 3);
    CHECK(c.getElement(2,1) == 7);
    CHECK(c.getElement(2,2) == 8);
    CHECK(c.getElement(3,3) == 6);
    CHECK(c.getElement(3,4) == 5);
    CHECK(c.getElement(4,3) == 4);
    CHECK(c.getElement(4,4) == 8);

    Dmatrix b;
    in >> b;
    CHECK(b.getElement(0,0) == 4);
    CHECK(b.getElement(0,1) == 3);
    CHECK(b.getElement(1,0) == 2);
    CHECK(b.getElement(1,1) == 6);
    CHECK(b.getElement(2,2) == 5);

    Dmatrix a;
    in >> a;
    CHECK(a.getElement(0,0) == 2);
    CHECK(a.getElement(1,1) == 4);
}

TEST_CASE("getting and changing an element of the matrix", "")
{   
    vector<int> aaa;
    aaa.assign(5,1);
    // aaa.push_back(1);
    // aaa.push_back(1);
    // aaa.push_back(1);
    // aaa.push_back(1);
    // aaa.push_back(1);
    //aaa = {1,1,1,1,1};
    Dmatrix a(2,1,aaa);   CHECK(a.getElement(0,0) == 1);
    a.setElement(1,0,5);
    CHECK(a.getElement(1,0) == 5);
}

TEST_CASE("copy constructor", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Dmatrix a;
    in >> a;

    //Dmatrix b = a;
    Dmatrix b(a);
    CHECK(a.getElement(0,0) == b.getElement(0,0));
    CHECK(a.getElement(0,1) == b.getElement(0,1));
    CHECK(a.getElement(0,2) == b.getElement(0,2));
    CHECK(a.getElement(1,0) == b.getElement(1,0));
    CHECK(a.getElement(1,1) == b.getElement(1,1));
    CHECK(a.getElement(1,2) == b.getElement(1,2));
    CHECK(a.getElement(2,0) == b.getElement(2,0));
    CHECK(a.getElement(2,1) == b.getElement(2,1));
    CHECK(a.getElement(2,2) == b.getElement(2,2));
    CHECK(a.getElement(3,3) == b.getElement(3,3));
    CHECK(a.getElement(3,4) == b.getElement(3,4));
    CHECK(a.getElement(4,3) == b.getElement(4,3));
    CHECK(a.getElement(4,4) == b.getElement(4,4));
}

TEST_CASE("assignment operator", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Dmatrix a;
    in >> a;
    Dmatrix b;
    b = a; // check every non-zero item
    CHECK(a.getElement(0,0) == b.getElement(0,0));
    CHECK(a.getElement(0,1) == b.getElement(0,1));
    CHECK(a.getElement(0,2) == b.getElement(0,2));
    CHECK(a.getElement(1,0) == b.getElement(1,0));
    CHECK(a.getElement(1,1) == b.getElement(1,1));
    CHECK(a.getElement(1,2) == b.getElement(1,2));
    CHECK(a.getElement(2,0) == b.getElement(2,0));
    CHECK(a.getElement(2,1) == b.getElement(2,1));
    CHECK(a.getElement(2,2) == b.getElement(2,2));
    CHECK(a.getElement(3,3) == b.getElement(3,3));
    CHECK(a.getElement(3,4) == b.getElement(3,4));
    CHECK(a.getElement(4,3) == b.getElement(4,3));
    CHECK(a.getElement(4,4) == b.getElement(4,4));

    Dmatrix c; 
    c = b = a; // check every non-zero item
    CHECK(a.getElement(0,0) == c.getElement(0,0));
    CHECK(a.getElement(0,1) == c.getElement(0,1));
    CHECK(a.getElement(0,2) == c.getElement(0,2));
    CHECK(a.getElement(1,0) == c.getElement(1,0));
    CHECK(a.getElement(1,1) == c.getElement(1,1));
    CHECK(a.getElement(1,2) == c.getElement(1,2));
    CHECK(a.getElement(2,0) == c.getElement(2,0));
    CHECK(a.getElement(2,1) == c.getElement(2,1));
    CHECK(a.getElement(2,2) == c.getElement(2,2));
    CHECK(a.getElement(3,3) == c.getElement(3,3));
    CHECK(a.getElement(3,4) == c.getElement(3,4));
    CHECK(a.getElement(4,3) == c.getElement(4,3));
    CHECK(a.getElement(4,4) == c.getElement(4,4));

    c = c; // check every non-zero item
    CHECK(c.getElement(0,0) == 2);
    CHECK(c.getElement(0,1) == 4);
    CHECK(c.getElement(0,2) == 2);
    CHECK(c.getElement(1,0) == 6);
    CHECK(c.getElement(1,1) == 2);
    CHECK(c.getElement(1,2) == 5);
    CHECK(c.getElement(2,0) == 3);
    CHECK(c.getElement(2,1) == 7);
    CHECK(c.getElement(2,2) == 8);
    CHECK(c.getElement(3,3) == 6);
    CHECK(c.getElement(3,4) == 5);
    CHECK(c.getElement(4,3) == 4);
    CHECK(c.getElement(4,4) == 8);
}

TEST_CASE("add", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Dmatrix a, b, c, d, f, e, z, y; 
    in >> d;
    in >> b;
    in >> z;

    c = d + b; // check every non-zero item
    CHECK(c.getElement(0,0) == 5);
    CHECK(c.getElement(0,1) == 6);
    CHECK(c.getElement(0,2) == 7);
    CHECK(c.getElement(1,0) == 12);
    CHECK(c.getElement(1,1) == 9);
    CHECK(c.getElement(1,2) == 14);
    CHECK(c.getElement(2,0) == 6);
    CHECK(c.getElement(2,1) == 9);
    CHECK(c.getElement(2,2) == 12);
    CHECK(c.getElement(3,3) == 9);
    CHECK(c.getElement(3,4) == 6);
    CHECK(c.getElement(4,3) == 10);
    CHECK(c.getElement(4,4) == 16);

    a = b + d; // check every non-zero item
    CHECK(a.getElement(0,0) == c.getElement(0,0));
    CHECK(a.getElement(0,1) == c.getElement(0,1));
    CHECK(a.getElement(0,2) == c.getElement(0,2));
    CHECK(a.getElement(1,0) == c.getElement(1,0));
    CHECK(a.getElement(1,1) == c.getElement(1,1));
    CHECK(a.getElement(1,2) == c.getElement(1,2));
    CHECK(a.getElement(2,0) == c.getElement(2,0));
    CHECK(a.getElement(2,1) == c.getElement(2,1));
    CHECK(a.getElement(2,2) == c.getElement(2,2));
    CHECK(a.getElement(3,3) == c.getElement(3,3));
    CHECK(a.getElement(3,4) == c.getElement(3,4));
    CHECK(a.getElement(4,3) == c.getElement(4,3));
    CHECK(a.getElement(4,4) == c.getElement(4,4));

    e = (d+b)+d;
    f = d+(b+d); // check every non-zero item
    CHECK(e.getElement(0,0) == f.getElement(0,0));
    CHECK(e.getElement(0,1) == f.getElement(0,1));
    CHECK(e.getElement(0,2) == f.getElement(0,2));
    CHECK(e.getElement(1,0) == f.getElement(1,0));
    CHECK(e.getElement(1,1) == f.getElement(1,1));
    CHECK(e.getElement(1,2) == f.getElement(1,2));
    CHECK(e.getElement(2,0) == f.getElement(2,0));
    CHECK(e.getElement(2,1) == f.getElement(2,1));
    CHECK(e.getElement(2,2) == f.getElement(2,2));
    CHECK(e.getElement(3,3) == f.getElement(3,3));
    CHECK(e.getElement(3,4) == f.getElement(3,4));
    CHECK(e.getElement(4,3) == f.getElement(4,3));
    CHECK(e.getElement(4,4) == f.getElement(4,4));

    y = c + z; // null matrix test
    CHECK(y.getElement(0,0) == 5);
    CHECK(y.getElement(0,1) == 6);
    CHECK(y.getElement(0,2) == 7);
    CHECK(y.getElement(1,0) == 12);
    CHECK(y.getElement(1,1) == 9);
    CHECK(y.getElement(1,2) == 14);
    CHECK(y.getElement(2,0) == 6);
    CHECK(y.getElement(2,1) == 9);
    CHECK(y.getElement(2,2) == 12);
    CHECK(y.getElement(3,3) == 9);
    CHECK(y.getElement(3,4) == 6);
    CHECK(y.getElement(4,3) == 10);
    CHECK(y.getElement(4,4) == 16);
}

TEST_CASE("multiply", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Dmatrix a, b, c, d, z, y, one,ans; 
    in >> a;
    in >> b;
    in >> z;
    in >> one;

    c = a * b;
    CHECK(c.getElement(0,0) == 36);
    CHECK(c.getElement(0,1) == 36);
    CHECK(c.getElement(0,2) == 54);
    CHECK(c.getElement(1,0) == 45);
    CHECK(c.getElement(1,1) == 36);
    CHECK(c.getElement(1,2) == 68);
    CHECK(c.getElement(2,0) == 75);
    CHECK(c.getElement(2,1) == 71);
    CHECK(c.getElement(2,2) == 110);
    CHECK(c.getElement(3,3) == 48);
    CHECK(c.getElement(3,4) == 46);
    CHECK(c.getElement(4,3) == 60);
    CHECK(c.getElement(4,4) == 68);
    
    

    d = b * a;
    CHECK(d.getElement(0,0) == 33);
    CHECK(d.getElement(0,1) == 51);
    CHECK(d.getElement(0,2) == 56);
    CHECK(d.getElement(1,0) == 81);
    CHECK(d.getElement(1,1) == 101);
    CHECK(d.getElement(1,2) == 119);
    CHECK(d.getElement(2,0) == 30);
    CHECK(d.getElement(2,1) == 44);
    CHECK(d.getElement(2,2) == 48);
    CHECK(d.getElement(3,3) == 22);
    CHECK(d.getElement(3,4) == 23);
    CHECK(d.getElement(4,3) == 68);
    CHECK(d.getElement(4,4) == 94);

    y = z * d; // null matrix test
    CHECK(y.getElement(0,0) == 0);
    CHECK(y.getElement(0,1) == 0);
    CHECK(y.getElement(0,2) == 0);
    CHECK(y.getElement(1,0) == 0);
    CHECK(y.getElement(1,1) == 0);
    CHECK(y.getElement(1,2) == 0);
    CHECK(y.getElement(2,0) == 0);
    CHECK(y.getElement(2,1) == 0);
    CHECK(y.getElement(2,2) == 0);
    CHECK(y.getElement(3,3) == 0);
    CHECK(y.getElement(3,4) == 0);
    CHECK(y.getElement(4,3) == 0);
    CHECK(y.getElement(4,4) == 0);

    ans = d * one; // identity matrix test
    CHECK(ans.getElement(0,0) == 33);
    CHECK(ans.getElement(0,1) == 51);
    CHECK(ans.getElement(0,2) == 56);
    CHECK(ans.getElement(1,0) == 81);
    CHECK(ans.getElement(1,1) == 101);
    CHECK(ans.getElement(1,2) == 119);
    CHECK(ans.getElement(2,0) == 30);
    CHECK(ans.getElement(2,1) == 44);
    CHECK(ans.getElement(2,2) == 48);
    CHECK(ans.getElement(3,3) == 22);
    CHECK(ans.getElement(3,4) == 23);
    CHECK(ans.getElement(4,3) == 68);
    CHECK(ans.getElement(4,4) == 94);
}

TEST_CASE("exceptions", "")
{

    Dmatrix a(3,2);

    try
    {
        a.setElement(5,3,4);
    }
    catch(Dmatrix::Exceptions ex)
    {
        CHECK(ex == Dmatrix::OVERINDEXED);
    }

    try
    {
        a.setElement(-1,4,4);
    }
    catch(Dmatrix::Exceptions ex)
    {
        CHECK(ex == Dmatrix::OVERINDEXED);
    }

    Dmatrix b(2,1);
    Dmatrix c(3,2);


    try
    {
        c = a + b;
    }
    catch(Dmatrix::Exceptions ex)
    {
        CHECK(ex == Dmatrix::DIFFERENT);
    }

    try
    {
        c = a * b;
    }
    catch(Dmatrix::Exceptions ex)
    {
        CHECK(ex == Dmatrix::DIFFERENT);
    }


    try
    {
        a.setElement(1,4,4);
    }
    catch(Dmatrix::Exceptions ex)
    {
        CHECK(ex == Dmatrix::NULLPART);
    }

    try
    {
        int  k = a.getElement(7,4);
    }
    catch(Dmatrix::Exceptions ex)
    {
        CHECK(ex == Dmatrix::OVERINDEXED);
    }
}

#endif
