#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <string>


struct TreeNode {
    int value;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v, TreeNode* p = nullptr) : value(v), left(nullptr), right(nullptr), parent(p) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    void insert(int value);
    void remove(int value);     // if the vitim is an internal node, use the min of right subtree to replace it.
    bool search(int value);     // find the node and return the value of the node
    int get_parent(int value);  // find the node and return the value of its parent

    std::string serialize();
    void deserialize(const std::string& code);

private:
    TreeNode* root;
};


#endif