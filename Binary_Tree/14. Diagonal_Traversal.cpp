/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*
TC = O(N)
SC = O(N)
Link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
*/

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *node = q.front();

        while (node != NULL)
        {
            ans.push_back(node->data);
            if (node->left)
                q.push(node->left);
            node = node->right;
        }

        q.pop();
    }

    return ans;
}