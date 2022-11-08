//PreOrder Tree Traversal(Iterative)
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

vector<int> preOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> s;

    if (root == NULL)
        return ans;

    s.push(root);

    while (!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        ans.push_back(temp->data);

        if (temp->right != NULL)
            s.push(temp->right);
        
        if (temp->left != NULL)
            s.push(temp->left);
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

    vector<int> preOr = preOrder(root);

    cout << "PreOrder Traversal: ";
    for (auto it: preOr)
        cout << it << " ";
    cout << "\n";

    preOr.clear();
    return 0;
}