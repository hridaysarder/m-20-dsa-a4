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

Node *input_tree(int &count)
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
    {
        root = new Node(val);
        count++;
    }
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
        {
            q.push(myLeft);
            count++;
        }

        if (myRight)
        {
            q.push(myRight);
            count++;
        }
    }
    return root;
}

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
}

int main()
{
    int count = 0;
    Node *root = input_tree(count);
    int depth = maxDepth(root);
    int nodes = pow(2, depth) - 1;
    if (count == nodes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}