/*
TC = O(H)
SC = O(1)
Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        TreeNode *node = root;

        while (node != NULL)
        {
            if (node->val > val)
                node = node->left;
            else if (node->val < val)
                node = node->right;
            else
                break;
        }

        return node;
    }
};