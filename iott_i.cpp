//InOrder Tree Traversal(Iterative)
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

vector<int> InOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> s;

    while (true)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if (s.empty())  break;
            
            root = s.top();
            ans.push_back(root->data);
            s.pop();
            root = root->right;
        }
    }

    return ans;
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

    vector<int> inOrder = InOrder(root);

    cout << "InOrder Traversal: ";
    for (auto it: inOrder)
        cout << it << " ";
    cout << "\n";

    inOrder.clear();
    return 0;
}