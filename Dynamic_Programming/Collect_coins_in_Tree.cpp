/*
BFS from leaf nodes basically
TC: O(N)
SC: O(N)
Link: https://leetcode.com/problems/collect-coins-in-a-tree/
*/

class Solution
{
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
    {
        // Build graph
        int n = coins.size();
        int remaining_nodes = n;
        vector<unordered_set<int>> g(n);
        for (vector<int> &e : edges)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        // Step 1
        queue<int> empty_leaves;
        for (int i = 0; i < n; ++i)
        {
            if (g[i].size() == 1 && !coins[i])
            {
                empty_leaves.push(i);
            }
        }
        while (empty_leaves.size())
        {
            int i = empty_leaves.front();
            empty_leaves.pop();
            --remaining_nodes;

            for (int nb : vector<int>(g[i].begin(), g[i].end()))
            {
                g[i].erase(nb);
                g[nb].erase(i);
                if (g[nb].size() == 1 && !coins[nb])
                {
                    empty_leaves.push(nb);
                }
            }
        }

        // Step 2
        queue<int> leaves;
        for (int i = 0; i < n; ++i)
        {
            if (g[i].size() == 1)
            {
                leaves.push(i);
            }
        }
        for (int trim = 0; trim < 2; ++trim)
        {
            int size = leaves.size();
            for (int i = 0; i < size; ++i)
            {
                int cur = leaves.front();
                leaves.pop();
                --remaining_nodes;

                for (int nb : vector<int>(g[cur].begin(), g[cur].end()))
                {
                    g[cur].erase(nb);
                    g[nb].erase(cur);
                    if (g[nb].size() == 1)
                    {
                        leaves.push(nb);
                    }
                }
            }
        }

        // Step 3
        return max(0, (remaining_nodes - 1) * 2);
    }
};