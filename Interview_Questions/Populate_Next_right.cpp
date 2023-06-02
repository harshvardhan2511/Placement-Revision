/*
Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

// TC = O(N)
// SC = O(N)

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (!root)
            return NULL;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            Node *node;
            for (int i = 0; i < n; i++)
            {
                node = q.front();
                q.pop();

                node->next = q.front();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            node->next = NULL;
        }

        return root;
    }
};

/*  Optmise */
//  TC = O(N)
//  SC = O(1)

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *temp = root;

        if (!temp)
            return NULL;

        while (temp->left != NULL)
        {
            Node *node = temp;
            while (true)
            {
                node->left->next = node->right;
                if (!node->next)
                    break;
                node->right->next = node->next->left;
                node = node->next;
            }

            temp = temp->left;
        }
        return root;
    }
};