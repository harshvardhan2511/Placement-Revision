#include <bits/stdc++.h>
using namespace std;

// TC = O(N logN)
// SC = O(N)
// Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;           // line -> node(value)
        queue<pair<Node *, int>> q; // node, line
        vector<int> ans;

        if (root == NULL)
            return ans;
        q.push({root, 0});

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                Node *node = q.front().first;
                int level = q.front().second;

                if (mp.find(level) == mp.end())
                    mp[level] = node->data;

                if (node->left)
                    q.push({node->left, level - 1});
                if (node->right)
                    q.push({node->right, level + 1});

                q.pop();
            }
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};