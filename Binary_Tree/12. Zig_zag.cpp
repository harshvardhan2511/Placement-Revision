/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
*/

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;

        if (!root)
            return ans;

        q.push(root);
        int i = 0;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                level.push_back(q.front()->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (i++ % 2)
                reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        return ans;
    }
};