#ifndef __BST_TEMPLATE_H__
#define __BST_TEMPLATE_H__

// Default Comparator: Ascending Order
template <typename T>
struct Less {
    static bool compare(T a, T b) { return a < b; }
};

// Custom Comparator: Descending Order
template <typename T>
struct Greater {
    static bool compare(T a, T b) { return a > b; }
};

template <typename T>
struct TreeNode {
    T value;
    TreeNode *left, *right;
    TreeNode(T v) : value(v), left(nullptr), right(nullptr) {}
};

// TODO: Make this a template class supporting custom comparator
template <typename T, typename Compare = Less<T>>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}
    
    // TODO: Implement destructor to prevent memory leaks
    ~BinarySearchTree() {
        
    }

    // TODO: Implement insert using Compare::compare(a, b)
    void insert(T value) {
        
    }

    // TODO: Implement search
    bool search(T value) {
        
    }

private:
    TreeNode<T>* root;
};

#endif