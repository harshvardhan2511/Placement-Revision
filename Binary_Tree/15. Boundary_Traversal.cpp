/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*
TC = O(N)
SC = O(1)
*/

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left || root->right)
        {
            return false;
        }
        return true;
    }

    void addLeftBoundary(Node *root, vector<int> &v)
    {
        Node *n = root->left;
        while (n)
        {
            if (!isLeaf(n))
            {
                v.push_back(n->data);
            }
            if (n->left)
            {
                n = n->left;
            }
            else
            {
                n = n->right;
            }
        }
    }

    void addleafs(Node *root, vector<int> &v)
    {
        if (isLeaf(root))
        {
            v.push_back(root->data);
            return;
        }

        if (root->left)
            addleafs(root->left, v);
        if (root->right)
            addleafs(root->right, v);
    }

    void addRightBoundary(Node *root, vector<int> &v)
    {
        Node *n = root->right;
        vector<int> vec;
        while (n)
        {
            if (!isLeaf(n))
            {
                vec.push_back(n->data);
            }
            if (n->right)
            {
                n = n->right;
            }
            else
            {
                n = n->left;
            }
        }
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            v.push_back(vec[i]);
        }
    }

    vector<int> boundary(Node *root)
    {
        vector<int> v;
        if (root == NULL)
            return v;
        if (!isLeaf(root))
        {
            v.push_back(root->data);
        }
        addLeftBoundary(root, v);
        addleafs(root, v);
        addRightBoundary(root, v);

        return v;
    }
};