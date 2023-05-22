/*
SC = O(N)
TC = O(N)
Link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
*/

class Solution
{
public:
    /*You are required to complete this method*/

    void helper(Node *node, int height, int &mx, bool &flag)
    {
        if (!node)
            return;
        if (flag == false)
            return;

        if (!node->right && !node->left)
        {
            if (mx == -1)
                mx = height;
            else if (height != mx)
                flag = false;
            return;
        }

        helper(node->left, height + 1, mx, flag);
        helper(node->right, height + 1, mx, flag);
    }
    bool check(Node *root)
    {
        int mx = -1;
        int height = 0;
        bool flag = true;
        helper(root, height, mx, flag);
        return flag;
    }
};