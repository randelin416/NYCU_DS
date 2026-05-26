#include "RedBlackTree.h"

// func : for RedBlackTree
static shared_ptr<RBTreeNode> toRBT(shared_ptr<TreeNode> node) {
    if (!node) return nullptr;
    return static_pointer_cast<RBTreeNode>(node);
}

// func : check if node is red
static bool isRed (shared_ptr<TreeNode> node) {
    if(!node) return false;
    return toRBT(node)->colour == RBTreeNode::RED;
}

void RedBlackTree::insert_fixup(shared_ptr<RBTreeNode> z) {
    // Todo: finish this
    /* 
        RB-INSERT-FIXUP(T, z)
            while z.p.color == RED
                if z.p == z.p.p.left
                    y = z.p.p.right
                    if y.color == RED
                        z.p.color = BLACK       
                        y.color = BLACK         
                        z.p.p.color = RED
                        z = z.p.p
                    else 
                        if z == z.p.right
                            z = z.p
                            LEFT-ROTATE(T, z)
                        z.p.color = BLACK
                        z.p.p.color = RED
                        RIGHT-ROTATE(T, z.p.p)
                else 
                    (same as 'then' clause with "right" and "left" exchanged)
    
            T.root.color = BLACK
    */
    while (z->parent && isRed(z->parent)) {
        auto a = toRBT(z->parent);
        auto b = toRBT(a->parent);

        if (a == b->left) {
            auto y = b->right;

            if(isRed(y)) {
                a->colour = RBTreeNode::BLACK;
                toRBT(y)->colour = RBTreeNode::BLACK;
                b->colour = RBTreeNode::RED;
                z = b;
            } else {
                if (z == a->right) {
                    z = a;
                    rotate_left(z);
                    a = toRBT(z->parent);
                    b = toRBT(a->parent);
                }
                a->colour = RBTreeNode::BLACK;
                b->colour = RBTreeNode::RED;
                rotate_right(b);
            }
        } else {
            auto y = b->left;

            if(isRed(y)) {
                a->colour = RBTreeNode::BLACK;
                toRBT(y)->colour = RBTreeNode::BLACK;
                b->colour = RBTreeNode::RED;
                z = b;
            } else {
                if (z == a->left) {
                    z = a;
                    rotate_right(z);
                    a = toRBT(z->parent);
                    b = toRBT(a->parent);
                }
                a->colour = RBTreeNode::BLACK;
                b->colour = RBTreeNode::RED;
                rotate_left(b);
            }
        }
    }

    toRBT(root)->colour = RBTreeNode::BLACK;
}

// func : check if node is black
static bool isBlack(shared_ptr<TreeNode> node) {
    if (!node) return true;
    return !isRed(node);
}

void RedBlackTree::remove_fixup(shared_ptr<RBTreeNode> x, shared_ptr<RBTreeNode> parent) {
    // Todo: finish this
    /*
        RB-DELETE-FIXUP(T, x)
            while x != T.root and x.color == BLACK
                if x == x.p.left then
                    w = x.p.right
                    if w.color == RED
                        w.color = BLACK
                        x.p.color = RED
                        LEFT-ROTATE(T, x.p)
                        w = x.p.right
                    if w.left.color == BLACK and w.right.color == BLACK
                        w.color = RED
                        x = x.p
                    else
                        if w.right.color == BLACK
                            w.left.color = BLACK
                            w.color = RED
                            RIGHT-ROTATE(T, w)
                            w = x.p.right
                        w.color = x.p.color
                        x.p.color = BLACK
                        w.right.color = BLACK
                        LEFT-ROTATE(T, x.p)
                        x = T.root
                else
                    (same as 'then' clause with "right" and "left" exchanged)
            x.color = BLACK
    */
   while (x != root && isBlack(x)) {
        if (!parent) break;

        // x is left child
        if (x == parent->left) {
            auto w = toRBT(parent->right); // sibling

            // Case 1: sibling is red
            if (isRed(w)) {
                w->colour = RBTreeNode::BLACK;
                parent->colour = RBTreeNode::RED;
                rotate_left(parent);
                w = toRBT(parent->right);
            }

            // Case 2: sibling's children are both black
            if (isBlack(w ? w->left : nullptr) &&
                isBlack(w ? w->right : nullptr)) {
                if (w) w->colour = RBTreeNode::RED;
                x = parent;
                parent = toRBT(x->parent);
            }

            // Case 3 / 4
            else {
                // Case 3: sibling's far child is black
                if (isBlack(w ? w->right : nullptr)) {
                    if (w && w->left) {
                        toRBT(w->left)->colour = RBTreeNode::BLACK;
                    }
                    if (w) {
                        w->colour = RBTreeNode::RED;
                        rotate_right(w);
                    }
                    w = toRBT(parent->right);
                }

                // Case 4: sibling's far child is red
                if (w) w->colour = parent->colour;
                parent->colour = RBTreeNode::BLACK;
                if (w && w->right) {
                    toRBT(w->right)->colour = RBTreeNode::BLACK;
                }

                rotate_left(parent);
                x = toRBT(root);
                parent = nullptr;
            }
        }

        // x is right child, mirror case
        else {
            auto w = toRBT(parent->left); // sibling

            // Case 1: sibling is red
            if (isRed(w)) {
                w->colour = RBTreeNode::BLACK;
                parent->colour = RBTreeNode::RED;
                rotate_right(parent);
                w = toRBT(parent->left);
            }

            // Case 2: sibling's children are both black
            if (isBlack(w ? w->right : nullptr) &&
                isBlack(w ? w->left : nullptr)) {
                if (w) w->colour = RBTreeNode::RED;
                x = parent;
                parent = toRBT(x->parent);
            }

            // Case 3 / 4
            else {
                // Case 3: sibling's far child is black
                if (isBlack(w ? w->left : nullptr)) {
                    if (w && w->right) {
                        toRBT(w->right)->colour = RBTreeNode::BLACK;
                    }
                    if (w) {
                        w->colour = RBTreeNode::RED;
                        rotate_left(w);
                    }
                    w = toRBT(parent->left);
                }

                // Case 4: sibling's far child is red
                if (w) w->colour = parent->colour;
                parent->colour = RBTreeNode::BLACK;
                if (w && w->left) {
                    toRBT(w->left)->colour = RBTreeNode::BLACK;
                }

                rotate_right(parent);
                x = toRBT(root);
                parent = nullptr;
            }
        }
    }

    if (x) {
        x->colour = RBTreeNode::BLACK;
    }
}


void RedBlackTree::insert(int value) {
    // Todo: finish this
    /*
        RB-INSERT(T, z)
            BST-INSERT(T, z)
            z.color = RED
            RB-INSERT-FIXUP(z)
    */
    auto node = make_shared<RBTreeNode>(value);
    BinarySearchTree::insert(node);
    node->colour = RBTreeNode::RED;
    insert_fixup(node);
}

// func : find the minimum node
static shared_ptr<RBTreeNode> min(shared_ptr<TreeNode> node) {
    while (node && node->left) {
        node = node->left;
    }
    return toRBT(node);
}

void RedBlackTree::remove(int value) {
    // Todo: finish this
    /*
        RB-DELETE(T, z)
            y = z
            y-original-color = y.color
            if z.left == T.nil
                x = z.right
                RB-TRANSPLANT(T, z, z.right) 
            elseif z.right == T.nil
                x = z.left
                RB-TRANSPLANT(T, z, z.left)
            else y = TREE-MINIMUM(z.right)
                y-original-color = y.color
                x = y.right
                if y.p == z
                    x.p = y
                else 
                    RB-TRANSPLANT(T, y, y.right)
                    y.right = z.right
                    y.right.p = y
                RB-TRANSPLANT(T, z, y)
                y.left = z.left
                y.left.p = y
                y.color = z.color
            if y-original-color == BLACK
                RB-DELETE-FIXUP(T, x)
    */
    auto z = toRBT(find_node(value));
    if (!z) return;

    auto y = z;
    auto y_original_colour = y->colour;

    shared_ptr<RBTreeNode> x = nullptr;
    shared_ptr<RBTreeNode> x_parent = nullptr;

    // Case 1: z has no left child
    if (!z->left) {
        x = toRBT(z->right);
        x_parent = toRBT(z->parent);
        transplant(z, z->right);
    }

    // Case 2: z has no right child
    else if (!z->right) {
        x = toRBT(z->left);
        x_parent = toRBT(z->parent);
        transplant(z, z->left);
    }

    // Case 3: z has two children
    else {
        y = min(z->right);
        y_original_colour = y->colour;
        x = toRBT(y->right);

        if (y->parent == z) {
            x_parent = y;
            if (x) x->parent = y;
        } else {
            x_parent = toRBT(y->parent);

            transplant(y, y->right);

            y->right = z->right;
            if (y->right) y->right->parent = y;
        }

        transplant(z, y);

        y->left = z->left;
        if (y->left) y->left->parent = y;

        y->colour = z->colour;
    }

    z->left = nullptr;
    z->right = nullptr;
    z->parent = nullptr;

    if (y_original_colour == RBTreeNode::BLACK) {
        remove_fixup(x, x_parent);
    }
}


#include <sstream>
#include <queue>


string RedBlackTree::serialize() {
    // Todo: finish this
    // We use "(" + std::to_string(node->value) + ")"  for red nodes
    if (!root) return "";

    std::queue<shared_ptr<TreeNode>> q;
    std::string tokens[10000];
    int count = 0;

    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        if (node) {
            auto rb = toRBT(node);

            if (rb->colour == RBTreeNode::RED) {
                tokens[count++] = "(" + std::to_string(rb->value) + ")";
            } else {
                tokens[count++] = std::to_string(rb->value);
            }

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

void RedBlackTree::deserialize(const string& code) {
    // Todo: finish this
    root = nullptr;

    if (code.empty()) return;

    string tokens[10000];
    int count = 0;

    stringstream ss(code);
    string token;

    while (ss >> token) {
        tokens[count++] = token;
    }

    if (count == 0 || tokens[0] == "#") return;

    bool red = false;
    string val = tokens[0];

    if (val[0] == '(') {
        red = true;
        val = val.substr(1, val.length() - 2);
    }

    auto rootNode = make_shared<RBTreeNode>(stoi(val));
    if (!red) rootNode->setBlack();

    root = rootNode;

    std::queue<shared_ptr<TreeNode>> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < count) {
        auto curr = q.front();
        q.pop();

        // left child
        if (i < count && tokens[i] != "#") {
            bool red = false;
            string val = tokens[i];

            if (val[0] == '(') {
                red = true;
                val = val.substr(1, val.length() - 2);
            }

            auto node = make_shared<RBTreeNode>(stoi(val), curr);
            if (!red) node->setBlack();

            curr->left = node;
            q.push(node);
        }
        i++;

        // right child
        if (i < count && tokens[i] != "#") {
            bool red = false;
            string val = tokens[i];

            if (val[0] == '(') {
                red = true;
                val = val.substr(1, val.length() - 2);
            }

            auto node = make_shared<RBTreeNode>(stoi(val), curr);
            if (!red) node->setBlack();

            curr->right = node;
            q.push(node);
        }
        i++;
    }
}
