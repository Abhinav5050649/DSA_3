//Maximum Sum Path of Binary Tree
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

int findMaxPathSum(Node* root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = max(0, findMaxPathSum(root->left, maxi));
    int rh = max(0, findMaxPathSum(root->right, maxi));

    maxi = max(maxi, max(lh, rh) + root->data);

    return root->data + lh + rh;
}

int maxPathSum(Node *root)
{
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
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

    int ans = maxPathSum(root);

    cout << "Maximum Path Sum: " << ans << "\n";
    return 0;
}