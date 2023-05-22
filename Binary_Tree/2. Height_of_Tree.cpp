/*
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        int mx = 0;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                q.pop();
            }

            mx++;
        }

        return mx;
    }
};