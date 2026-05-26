#include "BinarySearchTree.h"
#include <sstream>


/*
TODO:  Please complete this file.
    - You CANNOT use any standard libraries such as <vector> or <queue> ...etc
    - You MAY implement the necessary data structures yourself or use the code from Part 1 and 2.
    - If necessary, you can modify your Makefile for your additional files."
*/

// constructor
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

// destructor
static void deleteTree(TreeNode* node)
{
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
BinarySearchTree::~BinarySearchTree()
{
    deleteTree(root);
}

// insert
void BinarySearchTree::insert(int value)
{
    if (!root)
    {
        root = new TreeNode(value);
        return;
    }

    TreeNode* curr = root;
    TreeNode* parent = nullptr;

    while (curr)
    {
        parent = curr;
        if (value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    TreeNode* node = new TreeNode(value, parent);

    if (value < parent->value)
        parent->left = node;
    else
        parent->right = node;
}

// search
bool BinarySearchTree::search(int value)
{
    TreeNode* curr = root;

    while (curr)
    {
        if (curr->value == value) return true;
        if (value < curr->value) curr = curr->left;
        else curr = curr->right;
    }

    return false;
}

// get_parent
int BinarySearchTree::get_parent(int value)
{
    TreeNode* curr = root;

    while (curr)
    {
        if (curr->value == value)
        {
            if (!curr->parent) return -1;
            return curr->parent->value;
        }

        if (value < curr->value) curr = curr->left;
        else curr = curr->right;
    }

    return -1;
}

// find minimum
static TreeNode* findMin(TreeNode* node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

// remove
void BinarySearchTree::remove(int value)
{
    TreeNode* curr = root;

    while (curr && curr->value != value)
    {
        if (value < curr->value) curr = curr->left;
        else curr = curr->right;
    }

    if (!curr) return;

    // case 1: leaf
    if (!curr->left && !curr->right)
    {
        if (!curr->parent)
            root = nullptr;
        else if (curr->parent->left == curr)
            curr->parent->left = nullptr;
        else
            curr->parent->right = nullptr;

        delete curr;
    }

    // case 2: 1 child
    else if (!curr->left || !curr->right)
    {
        TreeNode* child = (curr->left) ? curr->left : curr->right;

        if (!curr->parent)
        {
            root = child;
            child->parent = nullptr;
        }
        else
        {
            child->parent = curr->parent;

            if (curr->parent->left == curr)
                curr->parent->left = child;
            else
                curr->parent->right = child;
        }

        delete curr;
    }

    // case 3: 2 children
    else
    {
        TreeNode* succ = findMin(curr->right);
        curr->value = succ->value;
        remove(succ->value);
    }
}

// serialize
std::string BinarySearchTree::serialize()
{
    if (!root) return "";

    std::stringstream ss;

    // simple queue (array simulation)
    TreeNode* queue[1000];
    int front = 0, back = 0;

    queue[back++] = root;

    while (front < back)
    {
        TreeNode* node = queue[front++];

        if (node)
        {
            ss << node->value << " ";
            queue[back++] = node->left;
            queue[back++] = node->right;
        }
        else
        {
            ss << "# ";
        }
    }

    std::string result = ss.str();

    // remove space
    if (!result.empty())
        result.pop_back();

    return result;
}

// deserialize
void BinarySearchTree::deserialize(const std::string& code)
{
    // clear old tree
    remove(root ? root->value : 0);

    root = nullptr;
    if (code.empty()) return;

    std::string tokens[100];
    int count = 0;

    std::string temp = "";
    for (char c : code)
    {
        if (c == ' ')
        {
            if (!temp.empty())
            {
                tokens[count++] = temp;
                temp = "";
            }
        }
        else
        {
            temp += c;
        }
    }
    if (!temp.empty()) tokens[count++] = temp;

    if (tokens[0] == "#") return;

    // build root
    root = new TreeNode(std::stoi(tokens[0]));

    TreeNode* queue[1000];
    int front = 0, back = 0;
    queue[back++] = root;

    int i = 1;

    while (front < back && i < count)
    {
        TreeNode* curr = queue[front++];

        // left
        if (i < count && tokens[i] != "#")
        {
            curr->left = new TreeNode(std::stoi(tokens[i]), curr);
            queue[back++] = curr->left;
        }
        i++;

        // right
        if (i < count && tokens[i] != "#")
        {
            curr->right = new TreeNode(std::stoi(tokens[i]), curr);
            queue[back++] = curr->right;
        }
        i++;
    }
}