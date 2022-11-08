//Inorder Tree traversal (Recursive)
#include "bits/stdc++.h"
using namespace std;

typedef struct Node
{
    int data;
    Node *left, *right;

    Node()
    {
        data = 0;
        left = NULL, right = NULL;
    }

    Node(int d)
    {
        data = d;
        left = NULL, right = NULL;
    }
}
Node;

Node* newNode(int val)
{
    Node *n = new Node(val);
    return n;
}

void InOrder_Traversal(Node* curr, vector<int> &InOrder)
{
    if (curr == NULL)
        return;
    
    InOrder_Traversal(curr->left, InOrder);
    InOrder.push_back(curr->data);
    InOrder_Traversal(curr->right, InOrder);
}

int main()
{
    vector<int> vals;
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

    InOrder_Traversal(root, vals);

    cout << "The InOrder Traversal is: ";
    for (auto it: vals)
        cout << it << " ";
    cout << "\n";

    vals.clear();
    return 0;
}