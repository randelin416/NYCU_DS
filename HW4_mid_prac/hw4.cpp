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
