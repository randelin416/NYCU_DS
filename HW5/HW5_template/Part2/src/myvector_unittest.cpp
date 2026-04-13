#include <iostream>
#include <cassert>

#include "myvector.h"

using namespace std;


void test_pushBackAndPeek()
{
    {
        auto v = MyVector<int>();
        v.push_back(10);

        assert(v.front() == 10);
        assert(v.back() == 10);
    } 

    {
        auto v = MyVector<int>();

        v.push_back(10);
        v.push_back(21);
        v.push_back(33);
        v.push_back(42);
    
        assert(v.front() == 10);
        assert(v.back() == 42);
    } 
    std::cout << "✅ test_pushBackAndPeek passed!\n";
}


void test_pushBackAndPop()
{
    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(20);
        v.pop_front();
        assert(v.front() == 20);
        assert(v.back() == 20);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(20);
        v.pop_back();
        assert(v.front() == 10);
        assert(v.back() == 10);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(15);
        v.push_back(20);
        v.push_back(25);
        v.push_back(30);
        v.push_back(35);
        v.pop_back();
        v.pop_front();
        v.pop_back();
        v.pop_front();
        assert(v.front() == 20);
        assert(v.back() == 25);
    }
    std::cout << "✅ test_pushBackAndPop passed!\n";
}

#include <vector>
#include <cstdlib> 
#include <ctime>

void test_indexing()
{

    {
        auto v = MyVector<int>();

        v.push_back(10);
        v.push_back(21);
        v.push_back(33);
        v.push_back(42);

        assert(v[0] == 10);
        assert(v[1] == 21);
        assert(v[2] == 33);
        assert(v[3] == 42);
    }

    std::vector<int> numbers;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 100; ++i) { numbers.push_back(rand()); }

    {
        auto v = MyVector<int>();
        for (int num : numbers) { v.push_back(num); }
        for (int i = 0; i < 100; ++i) {
            assert(v[i] == numbers[i]);
        }
    }

    std::cout << "✅ test_indexing passed!\n";
}



void test_removing()
{
    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(15);
        v.remove(5);

        assert(v[0] == 10);
        assert(v.back() == 15);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(15);
        v.remove(10);

        assert(v[0] == 15);
        assert(v.back() == 15);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(15);
        v.remove(15);

        assert(v[0] == 10);
        assert(v.back() == 10);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.remove(10);

        assert(v.empty() == true);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.remove(20);
        v.remove(10);
        v.remove(30);
        v.remove(40);
        assert(v.empty() == true);
    }

    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.remove(20);
        v.remove(10);
        v.remove(30);
        assert(v.size() == 1);
        assert(v[0] == 40);
    }

    std::cout << "✅ test_removing passed!\n";
}


void test_insertion()
{
    {
        auto v = MyVector<int>();
        v.push_back(10);
        v.push_back(15);
        v.push_back(20);
        v.push_back(25);
        v.push_back(30);
        v.push_back(35);
        v.insert(1, 12);
        v.insert(3, 18);
        v.insert(8, 40);

        assert(v.size() == 9);
        assert(v[1] == 12);
        assert(v[3] == 18);
        assert(v[4] == 20);
        assert(v[8] == 40);
    }

    {
        auto v = MyVector<int>();
        v.insert(0, 10);
        v.insert(1, 20);
        v.insert(1, 15);

        assert(v.size() == 3);
        assert(v[0] == 10);
        assert(v[1] == 15);
        assert(v[2] == 20);
    }

    std::cout << "✅ test_insertion passed!\n";
}


void test_exceptions()
{

    {
        bool exceptionCaught = false;
        
        auto v = MyVector<int>();        
        try {
            v[1];
        }
        catch (std::exception& e) { exceptionCaught = true; }

        assert(exceptionCaught == true);
    }

    {
        bool exceptionCaught = false;

        auto v = MyVector<int>();
        v.push_back(10);
        try {
            v.pop_back();
            v.pop_front();
        }
        catch (std::exception& e) { exceptionCaught = true; }

        assert(exceptionCaught == false);
    }

    {
        bool exceptionCaught = false;

        auto v = MyVector<int>();
        v.push_back(10);
        try {
            v.pop_back();
            v.pop_front();
            v.front();
        }
        catch (std::exception& e) { exceptionCaught = true; }

        assert(exceptionCaught == true);
    }

    {
        bool exceptionCaught = false;

        auto v = MyVector<int>();
        try {
            v.push_back(10);
            v.remove(20);
        }
        catch (std::exception& e) { exceptionCaught = true; }

        assert(exceptionCaught == false);
    }


    {
        bool exceptionCaught = false;

        auto v = MyVector<int>();
        try {
            v.push_back(10);
            v.insert(2, 20);
        }
        catch (std::exception& e) { exceptionCaught = true; }

        assert(exceptionCaught == true);
    }

}


int main() 
{
    test_pushBackAndPeek();
    test_pushBackAndPop();
    test_indexing();
    test_removing();
    test_insertion();
    test_exceptions();

    return 0;
}