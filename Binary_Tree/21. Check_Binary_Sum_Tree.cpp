/*
Link: https://practice.geeksforgeeks.org/problems/sum-tree/1
*/

class Solution
{
public:
    bool flag = true;
    int sum = 0;

    int maximum(Node *node)
    {
        if (node == NULL)
            return 0;

        int lh = maximum(node->left);
        int rh = maximum(node->right);

        if (lh + rh != node->data && lh + rh != 0)
            flag = false;

        sum = lh + rh + node->data;

        return sum;
    }

    bool isSumTree(Node *node)
    {

        int mx = maximum(node);

        return flag;
    }
};