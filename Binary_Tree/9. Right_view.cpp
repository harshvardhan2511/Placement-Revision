/*
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/binary-tree-right-side-view/
*/

class Solution
{
public:
    void rightView(TreeNode *node, int level, vector<int> &ans)
    {

        if (node == NULL)
            return;

        if (level == ans.size())
            ans.push_back(node->val);

        rightView(node->right, level + 1, ans);
        rightView(node->left, level + 1, ans);

        // For left-View reverse above two lines
    }

    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> answer;

        rightView(root, 0, answer);

        return answer;
    }
};