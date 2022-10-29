#include <iostream>
#include <vector>
#include "Stack.hpp"
#include "Menu.hpp"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Stack" << endl;

    Menu menu;
    menu.Run();

    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Stack.hpp"

TEST_CASE("isEmpty()","[Stack]")
{
    Stack Q1;
    CHECK( Q1.isEmpty() == TRUE ); // failed

    int e = 1;
    Q1.push(e);
    CHECK( Q1.isEmpty() == FALSE );

    e=Q1.getTopElement();
    Q1.pop();
    CHECK( Q1.isEmpty() == TRUE );
}
TEST_CASE("push","[Stack]")
{
    Stack Q;
    int e1=1; int e2=2; int e3=3; int e4=4; int e5=5;
    {
        Q.push(e1);
        CHECK( 1 == Q.getSize());
        vector<int> v= Q.getAll();
        CHECK( v[0] == e1 );
    }

    {
        Q.push(e2);Q.push(e3);Q.push(e4);Q.push(e5);
        CHECK( 5 == Q.getSize());
        vector<int> v= Q.getAll();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]); CHECK( e3 == v[2]); CHECK( e4 == v[3]); CHECK( e5 == v[4]);
    }
}
TEST_CASE("pop","[Stack]")
{
    Stack Q;
    int e1=1; int e2=2; int e3=3; int e4=4; int e5=5;
    {
        Q.push(e1);
        CHECK( 1 == Q.getSize());
        Q.pop();
        CHECK( 0 == Q.getSize());
    }

    {
        Q.push(e2);Q.push(e3);Q.push(e4);Q.push(e5);
        CHECK( 4 == Q.getSize());
        Q.pop();Q.pop();
        CHECK( 2 == Q.getSize());
        vector<int> v= Q.getAll();
        CHECK( e2 == v[0]); CHECK( e3 == v[1]);
        Q.pop();Q.pop();
        CHECK( Q.isEmpty() == TRUE );
        CHECK_THROWS(Q.getTopElement()); // pass
        CHECK_THROWS(Q.pop());
    }
}
TEST_CASE("getTopElement","[Stack]")
{
    Stack Q;
    int e1=1; int e2=2; int e3=3; int e4=4; int e5=5;
    {
        Q.push(e1);
        CHECK( e1 == Q.getTopElement());
        Q.push(e2);
        CHECK( e2 == Q.getTopElement());
    }

    {
        Q.push(e2);Q.push(e3);Q.push(e4);Q.push(e5);
        CHECK( e5 == Q.getTopElement());
        Q.pop();Q.pop();
        CHECK( e3 == Q.getTopElement());
    }
}

#endif