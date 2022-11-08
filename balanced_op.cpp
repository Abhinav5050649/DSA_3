//To check for balanced binary tree
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

//Logic--> If function returns -1, then not balanced. Else, if num greater than or equal to 0 returned, then balanced tree
int check(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = check(root->left);
    int rh = check(root->right);

    if (lh == -1 || rh == -1)
        return -1;
    else if (abs(lh - rh) > 1)
        return -1;
    else
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

    cout << "Answer: " << check(root) << "\n";
    return 0;
}