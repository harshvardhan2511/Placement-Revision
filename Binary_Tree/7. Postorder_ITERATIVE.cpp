/*
SC = O(N)
TC = O(N)
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
*/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> post;
        stack<TreeNode *> st;
        TreeNode *cur = root;

        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *temp;
                temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        post.push_back(temp->val);
                    }
                }

                else
                    cur = temp;
            }
        }

        return post;
    }
};