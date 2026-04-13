#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// Template Code (Do not modify)
// ==========================================

class CrystalTreeBase {
public:
    struct Node {
        Node() : left(nullptr), right(nullptr) {}
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        virtual ~Node() = default;
    };

    CrystalTreeBase() : root(nullptr) {}
    virtual ~CrystalTreeBase() = default;

    virtual void insert(shared_ptr<Node> node) = 0;
    virtual void printPreorder() const = 0;
    virtual void printInorder() const = 0;

protected:
    shared_ptr<Node> root;
};

// You need to implement this
shared_ptr<CrystalTreeBase> buildTree();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        auto tree = buildTree();
        
        cout << "Preorder: ";
        tree->printPreorder();
        cout << "\n";

        cout << "Inorder: ";
        tree->printInorder();
        cout << "\n";
    }
    return 0;
}

// ==========================================
// Your code starts here 
// ==========================================
/* HINTS for Implementation:
  1. Extend the base Node struct to hold your 'energy' and 'height' properties.
  2. Extend CrystalTreeBase to create your AVLTree class.
  3. You will need to dynamic_pointer_cast<YourNodeClass> when implementing insert() to access
     energy/height.
  4. Implement the buildTree() function to read 'N', read the values, create the nodes, insert
     them into your tree, and return the tree pointer.
*/

// extend the base Node struct to hold your 'energy' and 'height' properties.
struct AVLNode : public CrystalTreeBase::Node {
    int val;
    int height;

    AVLNode(int v) {
        val = v;
        height = 1;
    }
};

// extend CrystalTreeBase to create your AVLTree class.
class AVLTree : public CrystalTreeBase {
private:
    int getHeight(shared_ptr<AVLNode> node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalance(shared_ptr<AVLNode> node) {
        if (!node) return 0;
        return getHeight(dynamic_pointer_cast<AVLNode>(node->left)) -
               getHeight(dynamic_pointer_cast<AVLNode>(node->right));
    }

    shared_ptr<AVLNode> rightRotate(shared_ptr<AVLNode> y) {
        auto x = dynamic_pointer_cast<AVLNode>(y->left);
        auto T2 = dynamic_pointer_cast<AVLNode>(x->right);

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(y->left)),
                            getHeight(dynamic_pointer_cast<AVLNode>(y->right)));

        x->height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(x->left)),
                            getHeight(dynamic_pointer_cast<AVLNode>(x->right)));

        return x;
    }

    shared_ptr<AVLNode> leftRotate(shared_ptr<AVLNode> x) {
        auto y = dynamic_pointer_cast<AVLNode>(x->right);
        auto T2 = dynamic_pointer_cast<AVLNode>(y->left);

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(x->left)),
                            getHeight(dynamic_pointer_cast<AVLNode>(x->right)));

        y->height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(y->left)),
                            getHeight(dynamic_pointer_cast<AVLNode>(y->right)));

        return y;
    }

    shared_ptr<AVLNode> insertNode(shared_ptr<AVLNode> node, int val) {
        if (!node) return make_shared<AVLNode>(val);

        if (val < node->val)
            node->left = insertNode(dynamic_pointer_cast<AVLNode>(node->left), val);
        else
            node->right = insertNode(dynamic_pointer_cast<AVLNode>(node->right), val);

        node->height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(node->left)),
                               getHeight(dynamic_pointer_cast<AVLNode>(node->right)));

        int balance = getBalance(node);

        // LL
        if (balance > 1 && val < dynamic_pointer_cast<AVLNode>(node->left)->val)
            return rightRotate(node);

        // RR
        if (balance < -1 && val > dynamic_pointer_cast<AVLNode>(node->right)->val)
            return leftRotate(node);

        // LR
        if (balance > 1 && val > dynamic_pointer_cast<AVLNode>(node->left)->val) {
            node->left = leftRotate(dynamic_pointer_cast<AVLNode>(node->left));
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && val < dynamic_pointer_cast<AVLNode>(node->right)->val) {
            node->right = rightRotate(dynamic_pointer_cast<AVLNode>(node->right));
            return leftRotate(node);
        }

        return node;
    }

    void preorder(shared_ptr<Node> node) const {
        if (!node) return;
        auto n = dynamic_pointer_cast<AVLNode>(node);
        cout << n->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(shared_ptr<Node> node) const {
        if (!node) return;
        inorder(node->left);
        auto n = dynamic_pointer_cast<AVLNode>(node);
        cout << n->val << " ";
        inorder(node->right);
    }

public:
    void insert(shared_ptr<Node> node) override {
        auto n = dynamic_pointer_cast<AVLNode>(node);
        root = insertNode(dynamic_pointer_cast<AVLNode>(root), n->val);
    }

    void printPreorder() const override {
        preorder(root);
    }

    void printInorder() const override {
        inorder(root);
    }
};

shared_ptr<CrystalTreeBase> buildTree() {
    int N;
    cin >> N;

    auto tree = make_shared<AVLTree>();

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        tree->insert(make_shared<AVLNode>(val));
    }

    return tree;
}