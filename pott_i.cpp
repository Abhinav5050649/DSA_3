//PostOrder Tree Traversal(Iterative)
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

vector<int> postOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> s1, s2;

    s1.push(root);

    while (!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();

        s2.push(temp);
        if (temp->left != NULL)
        {
            s1.push(temp->left);
        }

        if (temp->right != NULL)
        {
            s1.push(temp->right);
        }
    }

    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
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

    vector<int> postOr = postOrder(root);

    cout << "PostOrder Traversal: ";
    for (auto it: postOr)
        cout << it << " ";
    cout << "\n";

    postOr.clear();
    return 0;
}