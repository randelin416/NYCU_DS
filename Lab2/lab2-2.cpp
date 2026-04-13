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
void BST::insert(shared_ptr<Node> node) {
    if(!root) {
        root = node;
        return;
    }
    auto cur = root;
    while (true) {
        if(*node < *cur) {
            if(cur -> left == nullptr) {
                cur -> left = node;
                return;
            }
            cur = cur -> left;
        } else {
            if(cur -> right == nullptr) {
                cur -> right = node;
                return;
            }
            cur = cur -> right;
        }
    }
}

struct TreeNode : public BST::Node {
    int val;
    TreeNode(int v) : val(v) {}

    // trans to TreeNode to compare
    bool operator<(const Node& other) const override {
        const TreeNode& treeNode = static_cast<const TreeNode&>(other);
        return (this -> val < treeNode.val) ? true : false; 
    }
};

class MyBST : public BST {
    // do something to get the result
public:
    void getRightView(shared_ptr<Node> cur, int level, vector<int>& rightView) {
        if(!cur) return;
        if(rightView.size() == level) {
            auto temp = static_pointer_cast<TreeNode>(cur);
            rightView.push_back(temp -> val);
        }
        getRightView(cur -> right, level + 1, rightView);
        getRightView(cur -> left, level + 1, rightView);
    }
    string str() override {
        string res  = "";
        vector<int> viewRight;
        
        if(!root) return "";
        getRightView(root, 0, viewRight);

        // vector to string
        for (int v: viewRight) {
            res += to_string(v) + " ";
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};


shared_ptr<BST> buildBST() {
    int n, v;
    if (!(cin >> n))
        return nullptr;

    auto bst = make_shared<MyBST>();
    for(int i = 0; i < n; i++) {
        cin >> v;
        bst -> insert(make_shared<TreeNode>(v));
    }
    return bst;
}