//Boundary Traversal of Binary Tree
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

bool isLeaf(Node *root)
{
    return ((!root->left) && (!root->right));
}

void addLeftBoundary(Node* root, vector<int> &res)
{
    Node *cur = root->left;

    while (cur)
    {
        if (!isLeaf(cur))
        {
            res.push_back(cur->data);
        }

        if (cur->left)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }

    if (root->left) addLeaves(root->left, res);
    if (root->right)    addLeaves(root->right, res);
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *cur = root->right;
    vector<int> temp;
    while (cur)
    {
        if (!isLeaf(cur))
        {
            temp.push_back(cur->data);
        }

        if (cur->left)
        {
            cur = cur ->left;
        }
        else
        {
            cur = cur -> right;
        }
    }

    for (int i = temp.size() - 1; i >= 0; --i)
    {
        res.push_back(temp[i]);
    }
    temp.clear();
}

vector<int> printBoundary(Node* root)
{
    vector<int> res;

    if (!root)
    {
        return res;
    }

    res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

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

    vector<int> boundaryTraversal;

    boundaryTraversal = printBoundary(root);

    cout << "The boundary traversal is: ";
    for (int i = 0; i < boundaryTraversal.size(); ++i)
    {
        cout << boundaryTraversal[i] << " ";
    }
    cout << "\n";
    boundaryTraversal.clear();
    return 0;
}