//Zig-Zag Traversal of Binary Tree
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

vector<vector<int>> zigZag(Node *root)
{
    vector<vector<int>> result;

    if (root == NULL)
    {
        return result;
    }

    bool leftToRight = true;
    queue<Node*> queueNodes;
    queueNodes.push(root);

    while(!(queueNodes.empty()))
    {
        int size = queueNodes.size();
        vector<int> row(size);

        for (int i = 0; i < size; ++i)
        {
            Node *n = queueNodes.front();
            queueNodes.pop();

            int index = (leftToRight) ? i : (size - i - 1);
            row[index] = n->data;

            if (n->left)
            {
                queueNodes.push(n->left);
            }

            if (n->right)
            {
                queueNodes.push(n->right);
            }
        }

        result.push_back(row);
        row.clear();
        leftToRight = !leftToRight;
    }

    return result;
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

    vector<vector<int>> ans = zigZag(root);

    cout << "Zig-Zag Traversal of Tree:\n";
    for (int i = 0, n = ans.size(); i < n; ++i)
    {
        for (int j = 0, m = ans[i].size(); j < m; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    ans.clear();
    return 0;
}