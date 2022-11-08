//PreOrder Tree Traversal (Recursive) -- > Root, Left, Right
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

void preOrder_Traversal(Node* curr, vector<int> &preOrder)
{
    if (curr == NULL)
        return;
    
    preOrder.push_back(curr->data);
    preOrder_Traversal(curr->left, preOrder);
    preOrder_Traversal(curr->right, preOrder);
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

    preOrder_Traversal(root, vals);

    cout << "The PreOrder Traversal is: ";
    for (auto it: vals)
        cout << it << " ";
    cout << "\n";

    vals.clear();
    return 0;
}