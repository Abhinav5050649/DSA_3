//Printing Top View of Binary tree
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

vector<int> topView(Node* root)
{
    vector<int> ans;
    
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!(q.empty()))
    {
        auto it = q.front();
        q.pop();

        Node *n = it.first;
        int line = it.second;

        if (mp.find(line) == mp.end())
        {
            mp[line] = n->data;
        }

        if (n->left != NULL){
            q.push({n->left, line - 1});
        }

        if (n->right != NULL)
        {
            q.push({n->right, line + 1});
        }
    }

    for (auto it: mp)
    {
        ans.push_back(it.second);
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

    vector<int> topans = topView(root);

    cout << "Top view of Binary Tree:\n";
    for (auto it: topans)
    {
        cout << it << " ";
    }

    cout << "\n";

    topans.clear();
    return 0;
}