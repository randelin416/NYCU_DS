#include "BinarySearchTree.h"
#include <functional>
#include <stdexcept>


static void clear(shared_ptr<TreeNode> node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
}


BinarySearchTree::~BinarySearchTree() {
    clear(root);
    // my code
    root = nullptr;
}



bool TreeNode::operator<(const TreeNode& other) const {
    // Todo: finish this
    return value < other.value;
}



shared_ptr<TreeNode> BinarySearchTree::find_node(int value) {
    // Todo: finish this
    auto cur = root;
    while(cur) {
        if (cur->value == value) return cur;
        else if (cur->value < value)
            cur = cur->right;
        else
            cur = cur->left;
    }
    return nullptr;
}


void BinarySearchTree::insert(shared_ptr<TreeNode> node) {
    // Todo: finish this
    if (!node) return;

    node->left = nullptr;
    node->right = nullptr;

    shared_ptr<TreeNode> parent = nullptr;
    auto cur = root;

    while(cur) {
        parent = cur;
        if (node->value < cur->value)
            cur = cur->left;
        else
            cur = cur->right;
    }

    node->parent = parent;

    if(!parent) {
        root = node;
    } else if (node->value < parent->value) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

void BinarySearchTree::insert(int value) {
    insert(make_shared<TreeNode>(value));
}


void BinarySearchTree::transplant(shared_ptr<TreeNode> u, shared_ptr<TreeNode> v) {
    // Todo: finish this
    /*
        TRANSPLANT(T, u, v)
            if u.p === T.nil
                T.root = v
            elseif u == u.p.left
                u.p.left = v
            else
                u.p.right = v
            v.p = u.p
    */
    // when delete a node, need to transplant its child to its position, and update the parent of the child to the parent of the deleted node
    // u : the node which will be deleted (be replaced)
    // v : the child of the deleted node, which will be transplanted to the position
    if (!u) return;

    if (!u->parent) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v) {
        v->parent = u->parent;
    }
}

// func : find min node
static shared_ptr<TreeNode> min(shared_ptr<TreeNode> node) {
    if (!node) return nullptr;
    while (node->left) {
        node = node->left;
    }
    return node;
}

void BinarySearchTree::remove(int value) {
    // Todo: finish this
    /*
        REMOVE(v)
            if v.left == T.nil
                TRANSPLANT(T, v, v.right)
        elseif v.right == T.nil
            TRANSPLANT(T, v, v.left)
        else
            y = TREE-MINIMUM(v.right)
            if y.p != v
                TRANSPLANT(T, y, y.right)
                y.right = v.right
                y.right.p = y
            TRANSPLANT(T, v, y)
            y.left = v.left
            y.left.p = y
    */
    
    auto node = find_node(value);
    if (!node) return;
    
    if (!node->left) {
        transplant(node, node->right);
    } else if (!node->right) {
        transplant(node, node->left);
    } else {
        auto y = min(node->right);
        if (y->parent != node) {
            transplant(y, y->right);

            y->right = node->right;
            if (y->right)
                y->right->parent = y;
        }

        transplant(node, y);

        y->left = node->left;
        if (y->left)
            y->left->parent = y;
    }

    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
}

void BinarySearchTree::rotate_left(shared_ptr<TreeNode> x) {    
    
    if (!x) return;
    
    // Todo: finish this
    /*
      Todo
        - Psudo-code:

            LEFT-ROTATE(T, x)
                y = x.right;
                x.right = y.left
                if y.left != T.nil
                    y.left.p = x
                y.p = x.p
                if x.p == T.nil
                    T.root = y
                elseif x == x.p.left
                    x.p.left = y
                else x.p.right = y
                y.left = x
                x.p = y
    */

    if (!x->right) return;

    auto y = x->right;
    x->right = y->left;

    if (y->left)
        y->left->parent = x;
    y->parent = x->parent;

    if (!x->parent) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}


void BinarySearchTree::rotate_right(shared_ptr<TreeNode> y) {

    if (!y) return;

    // Todo: similar to rotate_left
    /*
      Todo
        - Psudo-code:

            RIGHT-ROTATE(T, y)
                x = y.left;
                y.left = x.right
                if x.right != T.nil
                    x.right.p = y
                x.p = y.p
                if y.p == T.nil
                    T.root = x
                elseif y == y.p.right
                    y.p.right = x
                else y.p.left = x
                x.right = y
                y.p = x
    */
    if (!y->left) return;

    auto x = y->left;
    y->left = x->right;
    if (x->right) {
        x->right->parent = y;
    }
    x->parent = y->parent;

    if (!y->parent) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}


#include <sstream>
#include <queue>


std::string BinarySearchTree::serialize() {
    // Todo: finish this
    if (!root) return "";

    if (!root) return "";

    std::queue<shared_ptr<TreeNode>> q;
    std::string tokens[10000];
    int count = 0;

    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        if (node) {
            tokens[count++] = std::to_string(node->value);
            q.push(node->left);
            q.push(node->right);
        } else {
            tokens[count++] = "#";
        }
    }

    while (count > 0 && tokens[count - 1] == "#") {
        count--;
    }

    std::ostringstream out;
    for (int i = 0; i < count; i++) {
        if (i > 0) out << " ";
        out << tokens[i];
    }

    return out.str();
}

void BinarySearchTree::deserialize(const std::string& code) {
    // Todo: finish this
    clear(root);
    root = nullptr;

    if (code.empty()) return;

    std::string tokens[10000];
    int count = 0;

    std::stringstream ss(code);
    std::string token;

    while (ss >> token) {
        tokens[count++] = token;
    }

    if (count == 0 || tokens[0] == "#") return;

    root = make_shared<TreeNode>(std::stoi(tokens[0]));

    std::queue<shared_ptr<TreeNode>> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < count) {
        auto cur = q.front();
        q.pop();

        if (i < count && tokens[i] != "#") {
            cur->left = make_shared<TreeNode>(std::stoi(tokens[i]), cur);
            q.push(cur->left);
        }
        i++;

        if (i < count && tokens[i] != "#") {
            cur->right = make_shared<TreeNode>(std::stoi(tokens[i]), cur);
            q.push(cur->right);
        }
        i++;
    }
}

