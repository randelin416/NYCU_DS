#include "BinarySearchTree.h"
#include <iostream>
#include <cassert>

void test_insertAndSearch() 
{
    BinarySearchTree bst;
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

    std::cout << "✅ test_insertAndSearch passed!\n";
}

void test_remove() 
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.remove(30);

    assert(bst.search(30) == false);
    assert(bst.search(50) == true);
    assert(bst.search(70) == true);

    std::cout << "✅ test_remove passed!\n";
}

void test_serialization() 
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    std::string serializedData = bst.serialize();
    
    BinarySearchTree newTree;
    newTree.deserialize(serializedData);

    assert(newTree.search(50) == true);
    assert(newTree.search(30) == true);
    assert(newTree.search(70) == true);
    assert(newTree.search(100) == false);

    std::cout << "✅ test_serialization passed!\n";
}

void test_emptyTree() 
{
    BinarySearchTree bst;
    std::string serializedData = bst.serialize();

    BinarySearchTree newTree;
    newTree.deserialize(serializedData);

    assert(newTree.search(50) == false);

    std::cout << "✅ test_emptyTree passed!\n";
}

void test_parentPointer() 
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    assert(bst.get_parent(30) == 50);
    assert(bst.get_parent(70) == 50);
    assert(bst.get_parent(20) == 30);
    assert(bst.get_parent(40) == 30);
    assert(bst.get_parent(50) == -1);

    std::cout << "✅ test_parentPointer passed!\n";
}

void test_edgeCases() 
{
    BinarySearchTree bst;

    bst.insert(10);
    bst.remove(10);
    assert(bst.search(10) == false);

    bst.insert(15);
    assert(bst.search(15) == true);
    bst.remove(15);
    assert(bst.search(15) == false);

    std::cout << "✅ test_edgeCases passed!\n";
}

int main() 
{
    test_insertAndSearch();
    test_remove();
    test_serialization();
    test_emptyTree();
    test_parentPointer();
    test_edgeCases();

    std::cout << "🎉 all tests are passed!\n";
    return 0;
}