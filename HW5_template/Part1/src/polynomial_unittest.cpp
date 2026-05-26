#include "polynomial.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_insertion()
{
    {
        Polynomial p;
        p.insert(3, 2);
        p.insert(2, 2);
        assert(p.toString() == "5x^2");
    }

    {
        Polynomial p;
        p.insert(3, 2);
        p.insert(2, 1);
        p.insert(5, 1);
        assert(p.toString() == "3x^2 + 7x");
    }

    {
        Polynomial p;
        p.insert(6, 5);
        p.insert(4, 10);
        p.insert(5, 3);
        p.insert(3, 2);
        p.insert(2, 1);
        p.insert(5, 10);
        p.insert(100, 0);
        assert(p.toString() == "9x^10 + 6x^5 + 5x^3 + 3x^2 + 2x + 100");
    }

    std::cout << "✅ test_insertion passed!\n";
}


void test_addition()
{
    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);
        p1.insert(2, 0);

        p2.insert(4, 3);
        p2.insert(1, 1);
        p2.insert(1, 0);

        auto p = p1 + p2;
        assert(p2.toString() == "4x^3 + x + 1");
        assert(p.toString() == "4x^3 + 3x^2 + 6x + 3");
        p1 += p2;
        assert(p1.toString() == "4x^3 + 3x^2 + 6x + 3");
        assert(p2.toString() == "4x^3 + x + 1");
    }

    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);
        p1.insert(2, 0);

        p2.insert(4, 3);
        p2.insert(2, 1);
        p2.insert(1, 0);

        p2 += p1;
        assert(p1.toString() == "3x^2 + 5x + 2");
        assert(p2.toString() == "4x^3 + 3x^2 + 7x + 3");
    }

    std::cout << "✅ test_addition passed!\n";
}


void test_multiplication()
{
    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);
        p1.insert(2, 0);

        p2.insert(4, 3);
        p2.insert(1, 1);
        p2.insert(1, 0);

        auto p = p1 * p2;
        assert(p.toString() == "12x^5 + 20x^4 + 11x^3 + 8x^2 + 7x + 2");
    }

    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);
        p1.insert(2, 0);

        p2.insert(4, 3);
        p2.insert(1, 1);
        p2.insert(1, 0);

        auto p = p1 * p2;
        p1 *= p2;
        assert(p1.toString() == p.toString());
    }

    std::cout << "✅ test_multiplication passed!\n";
}


void test_equal()
{
    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);

        p2.insert(3, 2);
        p2.insert(5, 1);

        assert(p1 == p2);
        assert(!(p1 != p2));
    }

    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);
        p1.insert(2, 0);

        p2.insert(3, 2);
        p2.insert(5, 1);
        p2.insert(1, 0);

        assert(!(p1 == p2));
        assert(p1 != p2);
    }

    {
        Polynomial p1, p2;
        
        p1.insert(3, 2);
        p1.insert(5, 1);
        p1.insert(2, 0);

        p2.insert(4, 3);
        p2.insert(1, 1);
        p2.insert(1, 0);

        auto p = p1 * p2;
        p1 *= p2;
        assert(p1 == p);    
    }

    std::cout << "✅ test_equal passed!\n";
}

int main()
{
    test_insertion();
    test_addition();
    test_multiplication();
    test_equal();

    return 0;
}