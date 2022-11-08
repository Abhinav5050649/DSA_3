//Printing Left View of binary tree
#include "bits/stdc++.h"
using namespace std;

typedef struct Node
{
    int data;
    Node* left;
    Node* right;
}
Node;

Node* newNode(int val)
{
    Node *node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void recursion(Node *root, int level, vector<int> &res)
{
    if (root == NULL)   return;

    if (res.size() == level)    res.push_back(root->data);
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
}

vector<int> leftView(Node *root){
    vector<int> res;
    recursion(root, 0, res);
    return res;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right=newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> ans = leftView(root);

    cout << "Left Side View of Binary Tree:\n";
    for (auto it: ans)
    {
        cout << it << " ";
    }
    cout << "\n";

    ans.clear();
    return 0;
}