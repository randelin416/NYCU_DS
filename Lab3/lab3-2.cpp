#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*********************************************************************************
 * This function builds a binary search tree (BST) from a vector of integers.    *
 * It inserts each integer into the BST in the order they appear in the vector.  *
 * Trying to understand the code will be a waste of time ^.<                     *
 *********************************************************************************/
#define ______ TreeNode
TreeNode* build_bst(const vector<int>& _){______* __=nullptr;for(int ___:_){______* ____=new ______(___);if(!__)__=____;else{______* _____=__;while(69){if(___<_____->val){if(!_____->left){_____->left=____;break;}_____=_____->left;}else{if(!_____->right){_____->right=____;break;}_____=_____->right;}}}}return __;}

void delete_bst(TreeNode* root){
    if(root){
        delete_bst(root->left);
        delete_bst(root->right);
        delete root;
    }
}

void print_zip_tie_merge(TreeNode* root1, int n1, TreeNode* root2, int n2); // implement this function

int main() {
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        int n1 = 0, n2 = 0;
        scanf("%d %d", &n1, &n2);
        vector<int> bocchi(n1), kita(n2);

        // input nodes for Bocchi
        for (int i = 0; i < n1; ++i) {
            scanf("%d", &bocchi[i]);
        }
        TreeNode* bocchi_the_tree = build_bst(bocchi);
        
        // input nodes for Kita
        for (int i = 0; i < n2; ++i) {
            scanf("%d", &kita[i]);
        }
        TreeNode* kita_the_tree = build_bst(kita);

        print_zip_tie_merge(bocchi_the_tree, n1, kita_the_tree, n2);

        // clean up
        delete_bst(bocchi_the_tree);
        delete_bst(kita_the_tree);
    }
}

// Your code starts here

void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

void print_zip_tie_merge(TreeNode* root1, int n1, TreeNode* root2, int n2) {
    vector<int> v1;
    vector<int> v2;

    inorder(root1, v1);
    inorder(root2, v2);

    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            printf("%d ", v1[i]);
            i++;
        } else {
            printf("%d ", v2[j]);
            j++;
        }
    }

    while (i < n1) {
        printf("%d ", v1[i]);
        i++;
    }

    while (j < n2) {
        printf("%d ", v2[j]);
        j++;
    }

    printf("\n");
}