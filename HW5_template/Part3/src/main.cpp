#include "BinarySearchTree.h"
#include <iostream>


/**
 * This file is not graded, and students are free to modify this file to test the results.
 * check the makefile
 */


int main()
{
    std::cout << "These are some cases to show the serialization: " << std::endl; 

    {
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(70);
        std::cout << "Serialized BST: " << bst.serialize() << std::endl;
        // Serialized BST: 50 # 70
    }

    {
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);

        std::cout << "Serialized BST: " << bst.serialize() << std::endl;
        // Serialized BST: 50 30 70 20 40
    }


    {
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.remove(50);

        std::cout << "Serialized BST: " << bst.serialize() << std::endl;
        // Serialized BST: 70 30 # 20 40
    }


    {
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.remove(50);
        bst.insert(50);
        bst.remove(30);

        std::cout << "Serialized BST: " << bst.serialize() << std::endl;
        // Serialized BST: 70 40 # 20 50
    }

}