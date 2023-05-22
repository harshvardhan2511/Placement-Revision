/*
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
*/

class Solution
{
public:
    vector<int> postorder;

    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return postorder;

        if (root->left)
            postorderTraversal(root->left);
        if (root->right)
            postorderTraversal(root->right);
        postorder.push_back(root->val);

        return postorder;
    }
};