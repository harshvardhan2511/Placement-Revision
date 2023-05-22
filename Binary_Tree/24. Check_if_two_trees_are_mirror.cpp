/*
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/symmetric-tree/
*/

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return recurse(root->left, root->right);
    }

    bool recurse(TreeNode *l, TreeNode *r)
    {
        if (!l || !r)
            return (l == r);
        return (l->val == r->val) && recurse(l->left, r->right) && recurse(l->right, r->left);
    }
};