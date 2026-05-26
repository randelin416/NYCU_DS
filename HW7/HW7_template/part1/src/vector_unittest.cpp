#include <iostream>
#include <cassert>
#include <string>
#include "template_vector.h"

static int instance_count = 0;
struct Tracker {
    int id;
    Tracker(int i = 0) : id(i) { instance_count++; }
    Tracker(const Tracker& other) : id(other.id) { instance_count++; }
    ~Tracker() { instance_count--; }
};

void test_int_vector() {
    MyVector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    assert(v.size() == 3);
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
    std::cout << "✅ test_int_vector passed!\n";
}

void test_string_vector() {
    MyVector<std::string> v;
    v.push_back("Hello");
    v.push_back("Template");
    assert(v.size() == 2);
    assert(v[0] == "Hello");
    assert(v[1] == "Template");
    std::cout << "✅ test_string_vector passed!\n";
}

void test_double_vector() {
    MyVector<double> v;
    v.push_back(3.14159);
    v.push_back(2.71828);
    
    assert(v.size() == 2);
    assert(v[0] > 3.14 && v[0] < 3.15);
    std::cout << "✅ test_double_vector passed!\n";
}

struct Point {
    double x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

void test_custom_struct_vector() {
    MyVector<Point> v;
    v.push_back({1.2, 3.4});
    v.push_back({5.6, 7.8});

    assert(v.size() == 2);
    assert(v[0].x == 1.2 && v[0].y == 3.4);
    assert((v[1] == Point{5.6, 7.8}));
    std::cout << "✅ test_custom_struct_vector passed!\n";
}

void test_large_scale() {
    MyVector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    assert(v.size() == 1000);
    for (int i = 0; i < 1000; ++i) {
        assert(v[i] == i);
    }
    std::cout << "✅ test_large_scale passed!\n";
}

void test_memory_leak() {
    instance_count = 0;
    {
        MyVector<Tracker> v;
        v.push_back(Tracker(1));
        v.push_back(Tracker(2));
        v.push_back(Tracker(3));
        assert(instance_count > 0);
    }
    assert(instance_count == 0);
    std::cout << "✅ test_memory_leak passed!\n";
}

int main() {
    test_int_vector();
    test_string_vector();
    test_double_vector();
    test_custom_struct_vector();
    test_large_scale();
    test_memory_leak();
    return 0;
}