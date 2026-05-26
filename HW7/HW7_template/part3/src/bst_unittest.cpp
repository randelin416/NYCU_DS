#include <iostream>
#include <cassert>
#include <string>
#include "bst_template.h"

static int instance_count = 0;
struct Tracker {
    int id;
    Tracker(int i = 0) : id(i) { instance_count++; }
    Tracker(const Tracker& other) : id(other.id) { instance_count++; }
    ~Tracker() { instance_count--; }
    
    bool operator<(const Tracker& other) const { return id < other.id; }
    bool operator>(const Tracker& other) const { return id > other.id; }
    bool operator==(const Tracker& other) const { return id == other.id; }
};

void test_ascending_int_bst() {
    BinarySearchTree<int, Less<int>> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    
    assert(bst.search(50) == true);
    assert(bst.search(30) == true);
    assert(bst.search(70) == true);
    assert(bst.search(20) == true);
    assert(bst.search(40) == true);
    assert(bst.search(100) == false);
    std::cout << "✅ test_ascending_int_bst passed!\n";
}

void test_descending_int_bst() {
    BinarySearchTree<int, Greater<int>> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(80);
    bst.insert(60);
    
    assert(bst.search(50) == true);
    assert(bst.search(30) == true);
    assert(bst.search(70) == true);
    assert(bst.search(80) == true);
    assert(bst.search(60) == true);
    assert(bst.search(10) == false);
    std::cout << "✅ test_descending_int_bst passed!\n";
}

void test_string_bst() {
    BinarySearchTree<std::string, Less<std::string>> bst;
    bst.insert("Monkey");
    bst.insert("Apple");
    bst.insert("Zebra");
    
    assert(bst.search("Apple") == true);
    assert(bst.search("Monkey") == true);
    assert(bst.search("Zebra") == true);
    assert(bst.search("Banana") == false);
    std::cout << "✅ test_string_bst passed!\n";
}

void test_edge_cases() {
    BinarySearchTree<int, Less<int>> bst;
    
    assert(bst.search(10) == false);
    
    bst.insert(10);
    bst.insert(10);
    assert(bst.search(10) == true);
    
    std::cout << "✅ test_edge_cases passed!\n";
}

void test_memory_leak() {
    instance_count = 0;
    {
        BinarySearchTree<Tracker, Less<Tracker>> bst;
        bst.insert(Tracker(50));
        bst.insert(Tracker(30));
        bst.insert(Tracker(70));
        assert(instance_count > 0);
    }
    assert(instance_count == 0);
    std::cout << "✅ test_memory_leak passed!\n";
}

int main() {
    test_ascending_int_bst();
    test_descending_int_bst();
    test_string_bst();
    test_edge_cases();
    test_memory_leak();
    return 0;
}