#ifndef __REDBLACKTREE_H__
#define __REDBLACKTREE_H__

#include "BinarySearchTree.h"


struct RBTreeNode : TreeNode {
    // Todo: implement this in your way
    enum Colour { RED, BLACK };
    Colour colour;

    RBTreeNode(int v) : TreeNode(v), colour(RED) {}
    RBTreeNode(int v, shared_ptr<TreeNode> p) : TreeNode(v, p), colour(RED) {}

    bool isRed() const {
        return colour == RED;
    }

    bool isBlack() const {
        return colour == BLACK;
    }

    void setRed() {
        colour = RED;
    }

    void setBlack() {
        colour = BLACK;
    }
};

class RedBlackTree : public BinarySearchTree {
public:
    RedBlackTree() : BinarySearchTree() {};
    void insert(int value) override;
    void remove(int value) override;
    std::string serialize() override;
    void deserialize(const std::string& code) override;

private:
    void insert_fixup(shared_ptr<RBTreeNode> z);
    void remove_fixup(shared_ptr<RBTreeNode> x, shared_ptr<RBTreeNode> parent);
};

#endif