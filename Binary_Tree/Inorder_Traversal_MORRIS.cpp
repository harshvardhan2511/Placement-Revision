/*
TC = O(N)
    SC = O(1)
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> inorder;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                inorder.push_back(cur->val);
                cur = cur->right;
            }

            else
            {

                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                { // until no thread has been made
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = cur; // making a thread back to the parent
                    cur = cur->left;   // cur moves forward and replaces prev
                }

                else
                { // if thread OR node already exists
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};