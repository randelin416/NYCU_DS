#include <iostream>
#include <cassert>
#include <string>
#include "template_vector.h"
#include "traits.h"

void test_int_accumulator() {
    MyVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int sum = Accumulator<int>::sum(v);
    assert(sum == 6);
    std::cout << "✅ test_int_accumulator passed!\n";
}

void test_double_accumulator() {
    MyVector<double> v;
    v.push_back(1.5);
    v.push_back(2.5);
    v.push_back(3.0);
    double sum = Accumulator<double>::sum(v);
    assert(sum == 7.0);
    std::cout << "✅ test_double_accumulator passed!\n";
}

void test_string_accumulator() {
    MyVector<std::string> v;
    v.push_back("Apple");
    v.push_back("Banana");
    v.push_back("Cherry");
    std::string result = Accumulator<std::string>::sum(v);
    assert(result == "Apple, Banana, Cherry");
    std::cout << "✅ test_string_accumulator passed!\n";
}

void test_empty_accumulator() {
    MyVector<int> v_int;
    assert(Accumulator<int>::sum(v_int) == 0);

    MyVector<std::string> v_str;
    assert(Accumulator<std::string>::sum(v_str) == "");
    
    std::cout << "✅ test_empty_accumulator passed!\n";
}

void test_single_element_string() {
    MyVector<std::string> v;
    v.push_back("Apple");
    assert(Accumulator<std::string>::sum(v) == "Apple");
    std::cout << "✅ test_single_element_string passed!\n";
}

int main() {
    test_int_accumulator();
    test_double_accumulator();
    test_string_accumulator();
    test_empty_accumulator();
    test_single_element_string();
    return 0;
}