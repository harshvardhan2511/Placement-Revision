/*
TC = O(N)
SC = O(N)
Link: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
*/

class Solution
{
public:
    void helper(Node *node, int sum, int len, int &mxSum, int &mxLen)
    {

        if (!node)
        {
            if (len > mxLen)
            {
                mxLen = len;
                mxSum = sum;
            }
            if (len == mxLen)
                mxSum = max(sum, mxSum);
            return;
        }

        sum += node->data;
        helper(node->left, sum, len + 1, mxSum, mxLen);
        helper(node->right, sum, len + 1, mxSum, mxLen);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        int mxSum = 0;
        int mxLen = 0;
        if (!root)
            return 0;
        helper(root, 0, 0, mxSum, mxLen);

        return mxSum;
    }
};