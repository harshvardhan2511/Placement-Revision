/*
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

class Solution
{
public:
    vector<int> preorder;

    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return preorder;

        preorder.push_back(root->val);
        if (root->left)
            preorderTraversal(root->left);
        if (root->right)
            preorderTraversal(root->right);

        return preorder;
    }
};