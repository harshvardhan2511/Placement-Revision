/*
TC = O(N)
SC = O(N)
Link: https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
*/

class Solution
{
public:
    bool isHeap(struct Node *tree)
    {
        queue<Node *> q;

        if (!tree)
            return true;
        q.push(tree);
        bool seen = false; // marks whether we have already seen an empty child on a particular level

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            // for left
            if (node->left)
            {
                if (seen || node->left->data > node->data)
                    return false;
                q.push(node->left);
            }
            else
                seen = true;
            // for right
            if (node->right)
            {
                if (seen || node->right->data > node->data)
                    return false;
                q.push(node->right);
            }
            else
                seen = true;
        }

        return true;
    }
};