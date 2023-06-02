/*
TC = O(NlogN)
SC = O(N)
Link: https://leetcode.com/problems/merge-k-sorted-lists/submissions/
*/
class Solution
{
public:
    struct ListNode *newNode(int data)
    {
        ListNode *node = new ListNode;
        node->val = data;
        node->next = NULL;
        return node;
    }
    void insertNewNode(ListNode **root, int data)
    {
        ListNode *node = newNode(data);
        ListNode *ptr;
        if (*root == NULL)
        {
            *root = node;
        }
        else
        {
            ptr = *root;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = node;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        ListNode *node = NULL;
        priority_queue<int> pq;

        for (auto it : lists)
        {
            node = it;

            while (node != NULL)
            {
                pq.push(node->val);
                node = node->next;
            }
        }

        vector<int> ans(pq.size());

        for (int i = pq.size() - 1; i > -1; i--)
        {
            ans[i] = pq.top();
            pq.pop();
        }

        ListNode *root = NULL;
        for (int i = 0; i < ans.size(); i++)
        {
            insertNewNode(&root, ans[i]);
        }
        return root;
    }
};