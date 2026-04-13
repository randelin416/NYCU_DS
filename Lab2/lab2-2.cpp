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
        virtual bool operator<(const Node& other) const { return (this < &other) ? true : false; }

        // You need to override this
        virtual string str() { ostringstream ss;  ss << this; return ss.str(); }
    };
    BST() : root(nullptr) {}

    // You need to override this
    virtual string str() { ostringstream ss;  ss << this; return ss.str(); }

    // You need to implement this
    void insert(shared_ptr<Node> node);

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
