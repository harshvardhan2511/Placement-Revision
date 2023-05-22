/*
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/diameter-of-binary-tree/
*/

class Solution
{
public:
    int maximum(TreeNode *node, int &mx)
    {

        if (node == NULL)
            return 0;

        int Lheight = maximum(node->left, mx);
        int Rheight = maximum(node->right, mx);

        mx = max(mx, Lheight + Rheight);

        return 1 + max(Lheight, Rheight);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        int mx = 0;
        int height = maximum(root, mx);

        return mx;
    }
};