/*
SC = O(N)
TC = O(N)
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> preorder;

        if (!root)
            return preorder;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            preorder.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }

        return preorder;
    }
};