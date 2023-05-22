/*
SC = O(N)
Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
*/

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    int sum = 0;

    int BuildSumTree(Node *node)
    {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
        {
            int temp = node->data;
            node->data = 0;
            return temp;
        }

        int lh = BuildSumTree(node->left);
        int rh = BuildSumTree(node->right);

        sum = lh + rh;
        int rem = node->data;
        node->data = sum;

        return rem + sum;
    }

    void toSumTree(Node *node)
    {
        int x = BuildSumTree(node);
        return;
    }
};