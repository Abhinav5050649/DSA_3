//Program to find max height of binary tree
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
    Node* n = new Node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    
    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    return 1 + max(lh, rh);
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


    cout << "Maximum Height of Binary Tree: " << maxHeight(root) << "\n";
    return 0;
}