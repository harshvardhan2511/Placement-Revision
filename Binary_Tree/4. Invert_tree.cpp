/*
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/invert-binary-tree/
*/

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *Root = q.front();

            if (Root->left)
                q.push(Root->left);
            if (Root->right)
                q.push(Root->right);
            TreeNode *node = Root->left;
            Root->left = Root->right;
            Root->right = node;

            q.pop();
        }

        return root;
    }
};