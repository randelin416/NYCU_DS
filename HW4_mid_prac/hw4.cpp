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
struct AVLNode : public CrystalTreeBase::Node {
    int energy, height;
    AVLNode(int v) : energy(v), height(1) {}
};

struct AVLTree : public CrystalTreeBase {
private:
    int getHeight(shared_ptr<AVLNode> node) {
        if(!node) return 0;
        return node -> height;
    }
    int balance(shared_ptr<AVLNode> node) {
        if(!node) return 0;
        return getHeight(dynamic_pointer_cast<AVLNode> (node->left)) - getHeight(dynamic_pointer_cast<AVLNode> (node->right));
    }
    void inorder(shared_ptr<Node> node) const {
        if(!node) return;
        inorder(node -> left);
        auto n = dynamic_pointer_cast<AVLNode>(node);
        cout << n -> energy << " ";
        inorder(node -> right);
    }
    void preorder(shared_ptr<Node> node) const {
        if(!node) return;
        auto n = dynamic_pointer_cast<AVLNode>(node);
        cout << n -> energy << " ";
        preorder(node -> left);
        preorder(node -> right);
    }
    // left rotation
    shared_ptr<AVLNode> leftRotate(shared_ptr<AVLNode> node) {
        auto r = dynamic_pointer_cast<AVLNode> (node -> right);
        auto rl = dynamic_pointer_cast<AVLNode> (r -> left);

        r -> left = node;
        node -> right = rl;

        node -> height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode> (node -> left)), getHeight(dynamic_pointer_cast<AVLNode> (node -> right)));
        r -> height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode> (r -> left)), getHeight(dynamic_pointer_cast<AVLNode> (r -> right)));
    }
    // right rotation
    shared_ptr<AVLNode> rightRotate(shared_ptr<AVLNode> node) {
        auto l = dynamic_pointer_cast<AVLNode>(node -> left);
        auto lr = dynamic_pointer_cast<AVLNode>(l -> right);

        l -> right = node;
        node -> left = lr;

        node -> height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(node -> left)), getHeight(dynamic_pointer_cast<AVLNode>(node -> right)));
        l -> height = 1 + max(getHeight(dynamic_pointer_cast<AVLNode>(l -> left)), getHeight(dynamic_pointer_cast<AVLNode>(l -> right)));
    }
    // insert (RR, RL, LL, LR)
    shared_ptr<AVLNode> insert(shared_ptr<AVLNode> node, int val) {
        // insert the node to left or right child by recursion
        if(!node) {
            make_shared<AVLNode>(val);
        }
        if (val < node -> energy) {
            node -> left = insert(dynamic_pointer_cast<AVLNode>(node -> left), val);
        } else {
            node -> right = insert(dynamic_pointer_cast<AVLNode>(node -> right), val);
        }

        // get the balanced factor
        int b = balance(node);

        // RR
        if ((b < -1) && (val > dynamic_pointer_cast<AVLNode>(node -> right) -> energy)) {
            return rightRotate(node);
        }
        // LL
        if ((b > 1) && (val < dynamic_pointer_cast<AVLNode>(node -> left) -> energy)) {
            return leftRotate(node);
        }
        // RL
        if ((b < -1) && (val < dynamic_pointer_cast<AVLNode>(node -> left) -> energy)) {
            node -> left = leftRotate(dynamic_pointer_cast<AVLNode>(node -> left));
            return rightRotate(node);
        }
        // LR
        if((b < -1) && (val > dynamic_pointer_cast<AVLNode>(node -> right) -> energy)) {
            node -> right = rightRotate(dynamic_pointer_cast<AVLNode>(node -> right));
            return leftRotate(node);
        }
    }
public:
    void insert(shared_ptr<Node> node) override {

    }
    void printPreorder() {
        preorder(root);
    }
    void printInorder() {
        inorder(root);
    }
};

shared_ptr<CrystalTreeBase> buildTree() {
    int n;
    cin >> n;

    auto tree = make_shared<AVLTree>();

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree -> insert(make_shared<AVLNode>(val));
    }

    return tree;
}