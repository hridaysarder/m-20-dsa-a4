#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;
        if (myLeft)
            q.push(myLeft);
        if (myRight)
            q.push(myRight);
    }
    return root;
}

void print_outer_tree(Node *root)
{
    if (root->left)
    {
        cout << root->left->val << " ";
        print_outer_tree(root->left);
    }
    if (root->right)
    {
        print_outer_tree(root->right);
        cout << root->right->val << " ";
    }
}

int main()
{
    Node *root = input_tree();
    if (root)
    {
        print_outer_tree(root);
        cout << root->val << " ";
    }
    return 0;
}