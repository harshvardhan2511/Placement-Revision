/*
SC = O(N)
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
*/

class Solution
{
public:
    vector<int> inorder;

    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return inorder;

        if (root->left)
            inorderTraversal(root->left);
        inorder.push_back(root->val);
        if (root->right)
            inorderTraversal(root->right);

        return inorder;
    }
};