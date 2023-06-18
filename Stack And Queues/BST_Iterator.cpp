/*
TC: O(1)
SC: O(H)
Link: https://leetcode.com/problems/binary-search-tree-iterator/
*/

class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *t1 = st.top();
        st.pop();
        int res = t1->val;
        t1 = t1->right;
        while (t1)
        {
            st.push(t1);
            t1 = t1->left;
        }
        return res;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};