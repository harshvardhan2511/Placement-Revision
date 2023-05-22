/*
SC = O(1)
TC = O(N)
Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
*/

class Solution
{
public:
    Node *prev = NULL;
    Node *head = NULL;

    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        if (root == NULL)
            return NULL;

        bToDLL(root->left);

        if (prev == NULL)
            head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        bToDLL(root->right);

        return head;
    }
};
