#include <iostream>
#include <vector>
#include "heap.hpp"
#include "Menu.hpp"

using namespace std;

/// Change between manual mode and unit test mode
#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Heap" << endl;
    Menu menu;
    menu.Run();


    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "heap.hpp"

///Test cases mentioned on practice

TEST_CASE("isEmpty, isIn","[heap]")
{
    heap M;
    CHECK( M.isEmpty() );

    Item e(1,"a");
    CHECK_FALSE( M.isIn(e.num) );
    M.insert(e);
    CHECK_FALSE( M.isEmpty() );
    CHECK( M.isIn(e.num) );

    M.erase(e.num);
    CHECK( M.isEmpty() );
    CHECK_FALSE( M.isIn(e.num) );
}

TEST_CASE("insert","[heap]")
{
    heap M;;
    Item e1(1,"a"); Item e2(2,"b"); Item e3(3,"c"); Item e4(4,"d"); Item e5(5,"e");

    M.insert(e2);
    CHECK( 1 == M.count());
    vector<Item> v= M.getItems();
    CHECK( v[0] == e2 );

    M.insert(e5);
    CHECK( 2 == M.count());
    v= M.getItems();
    CHECK( v[0] == e2 ); CHECK( v[1] == e5 );

    M.insert(e1);
    v= M.getItems();
    CHECK( v[0] == e1 ); CHECK( v[1] == e5 ); CHECK( v[2] == e2 );

    M.insert(e3);M.insert(e4);
    CHECK( 5 == M.count());
    v= M.getItems();
    CHECK( e1 == v[0]); CHECK( e3 == v[1]); CHECK( e2 == v[2]); CHECK( e5 == v[3]); CHECK( e4 == v[4]);
}

TEST_CASE("CSearch","[heap]")
{
    SECTION("empty map")
    {
        heap M;
        CHECK_FALSE(M.getCSearch(3).first);
    }

    ///Items for testing
    Item e1(1,"a"); Item e2(2,"b"); Item e3(3,"c"); Item e5(5,"a");
    SECTION("one item")
    {
        heap M;
        M.insert(e1);
        CHECK(M.getCSearch(e1.num).first);
        CHECK(0 == M.getCSearch(e1.num).second);
        M.erase(e1.num);
        CHECK( 0 == M.count());
    }

    SECTION("more items, first is searched")
    {
        heap M;
        M.insert(e5); M.insert(e2); M.insert(e3);
        CHECK(M.getCSearch(e2.num).first);
        CHECK(0 == M.getCSearch(e2.num).second);
        M.erase(e2.num);
        CHECK( 2 == M.count());
        vector<Item> v=M.getItems();
        CHECK(v[0]==e3); CHECK(v[1]==e5);
    }

    SECTION("more items, last is searched")
    {
        heap M;
        M.insert(e5); M.insert(e2); M.insert(e3);
        CHECK(M.getCSearch(e5.num).first);
        CHECK(1 == M.getCSearch(e5.num).second);
        M.erase(e5.num);
        CHECK( 2 == M.count());
        vector<Item> v=M.getItems();
        CHECK(v[0]==e2); CHECK(v[1]==e3);
    }

    SECTION("more items, middle is searched")
    {
        heap M;
        M.insert(e5); M.insert(e2); M.insert(e3);
        CHECK(M.getCSearch(e3.num).first);
        CHECK(2 == M.getCSearch(e3.num).second);
        M.erase(e3.num);
        CHECK( 2 == M.count());
        vector<Item> v=M.getItems();
        CHECK(v[0]==e2); CHECK(v[1]==e5);
    }

    SECTION("more items, searched does not exist")
    {
        heap M;
        M.insert(e5); M.insert(e2); M.insert(e3);
        CHECK_FALSE(M.getCSearch(e1.num).first);
        CHECK_FALSE(1 == M.getCSearch(4).second);
    }
}
TEST_CASE("erase","[heap]")
{
    Item e1(1,"a"); Item e2(2,"b"); Item e3(3,"c"); Item e4(4,"d"); Item e5(5,"e");
    SECTION("erase first")
    {
        heap M;;

        M.insert(e2);
        M.insert(e3);
        M.insert(e1);

        M.erase(e1.num);
        CHECK( 2 == M.count());
        vector<Item> v=M.getItems();
        CHECK(v[0]==e2); CHECK(v[1]==e3);
    }
    SECTION("erase last")
    {
        heap M;;

        M.insert(e2);
        M.insert(e3);
        M.insert(e1);

        M.erase(e3.num);
        CHECK( 2 == M.count());
        vector<Item> v=M.getItems();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }
    SECTION("erase middle")
    {
        heap M;

        M.insert(e2);
        M.insert(e3);
        M.insert(e1);

        M.erase(e3.num);
        CHECK( 2 == M.count());
        vector<Item> v=M.getItems();
        CHECK(v[1]==e2); CHECK(v[0]==e1);
    }
}

TEST_CASE("exceptions","[heap]")
{
    SECTION("more items, middle is searched")
    {
        Item e1(1,"a"); Item e2(2,"b"); Item e3(3,"c"); Item e5(5,"a");
        heap M;
        CHECK_THROWS(M.erase(2));
        M.insert(e5); M.insert(e2); M.insert(e3);
        CHECK_THROWS(M.insert(e5));
        CHECK_THROWS(M.insert(e2));
        CHECK_THROWS(M.erase(4));
    }

}

#endif