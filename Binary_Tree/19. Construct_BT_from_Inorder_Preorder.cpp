/*
Does not work for duplicate values in Inorder array
TC = O(N)
SC = O(N)
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
*/

class Solution
{
public:
    TreeNode *build(vector<int> preorder, vector<int> inorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int, int> mp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inroot = mp[root->val]; // index of root in inorder
        int num = inroot - inStart; // number of elements in new inorder

        root->left = build(preorder, inorder, inStart, inroot - 1, preStart + 1, preStart + num, mp);
        root->right = build(preorder, inorder, inroot + 1, inEnd, preStart + num + 1, preEnd, mp);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i; // value -> index

        TreeNode *root = build(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1, mp);

        return root;
    }
};