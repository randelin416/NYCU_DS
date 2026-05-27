#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BST {
public:
    struct Node {
        Node() : left(nullptr), right(nullptr) {}
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        
        // You need to override this
        virtual bool operator<(const Node& other) const = 0;

        // You need to override this
        virtual string str() = 0;
    };
    BST() : root(nullptr) {}

    // You need to override this
    virtual string str() = 0;

    // You need to override this
    virtual void insert(shared_ptr<Node> node) = 0;

protected:
    shared_ptr<Node> root;
};

// You need to implement this
shared_ptr<BST> buildBST(); 

int main() {
    int T; cin >> T;
    for (int i=0; i<T; ++i) {
        auto bst = buildBST();
        cout << bst->str() << endl;
    }
    return 0;
}

// Your code starts here
class WeakRBTree : public BST {
private:
    enum Color { RED, BLACK };

    bool globalFlip = false;

public:
    struct RBNode : public BST::Node {
        int value;
        Color color;

        RBNode(int v) : BST::Node(), value(v), color(RED) {}

        bool operator<(const BST::Node& other) const override {
            const RBNode& rhs = dynamic_cast<const RBNode&>(other);
            return value < rhs.value;
        }

        string str() override {
            return to_string(value);
        }
    };

private:
    bool isRed(shared_ptr<RBNode> node) {
        if (!node) return false;

        bool storedRed = (node->color == RED);
        return storedRed ^ globalFlip;
    }

    void setActualRed(shared_ptr<RBNode> node) {
        node->color = globalFlip ? BLACK : RED;
    }

    void inorder(shared_ptr<BST::Node> node, stringstream& ss) {
        if (!node) return;

        inorder(node->left, ss);

        auto rb = dynamic_pointer_cast<RBNode>(node);

        if (isRed(rb)) {
            ss << "'" << rb->value << " ";
        } else {
            ss << rb->value << " ";
        }

        inorder(node->right, ss);
    }

public:
    string str() override {
        stringstream ss;
        inorder(root, ss);
        return ss.str();
    }

    void insert(shared_ptr<BST::Node> node) override {
        auto newNode = dynamic_pointer_cast<RBNode>(node);
        if (!newNode) return;

        setActualRed(newNode);

        if (!root) {
            root = newNode;
            return;
        }

        shared_ptr<BST::Node> curr = root;
        shared_ptr<BST::Node> parent = nullptr;

        while (curr) {
            parent = curr;

            if (*newNode < *curr) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (*newNode < *parent) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        auto rbParent = dynamic_pointer_cast<RBNode>(parent);

        if (isRed(rbParent)) {
            globalFlip = !globalFlip;
            setActualRed(newNode);
        }
    }
};

shared_ptr<BST> buildBST() {
    int n;
    cin >> n;

    auto tree = make_shared<WeakRBTree>();

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree->insert(make_shared<WeakRBTree::RBNode>(x));
    }

    return tree;
}