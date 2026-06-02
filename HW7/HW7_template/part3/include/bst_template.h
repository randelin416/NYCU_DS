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
        clear(root);
    }

    // TODO: Implement insert using Compare::compare(a, b)
    void insert(T value) {
        root = insertNode(root, value);
    }

    // TODO: Implement search
    bool search(T value) {
        TreeNode<T>* curr = root;

        while (curr) {
            if (!Compare::compare(value, curr->value) &&
                !Compare::compare(curr->value, value)) {
                return true;
            }

            if (Compare::compare(value, curr->value)) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return false;
    }

private:
    TreeNode<T>* root;

    // My code
    TreeNode<T>* insertNode(TreeNode<T>* node, T value) {
        if (!node) {
            return new TreeNode<T>(value);
        }

        // duplicate: do nothing
        if (!Compare::compare(value, node->value) &&
            !Compare::compare(node->value, value)) {
            return node;
        }

        if (Compare::compare(value, node->value)) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void clear(TreeNode<T>* node) {
        if (!node) return;

        clear(node->left);
        clear(node->right);
        delete node;
    }
};

#endif