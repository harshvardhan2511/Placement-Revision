/*
TC: O(V+E)
SC: O(V+E)
Link: https://leetcode.com/problems/network-delay-time/
*/

class Solution
{
public:
    // Since there is zero indexing i will ignore the values at zero-th index.
    // To tackle cyclic dependency i will use a min heap.

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1); // vector of {node, edge-weight}
        vector<int> distance(n + 1, INT_MAX);
        vector<int> vis(n + 1, 0);

        distance[k] = 0;

        for (auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // node, distance
        q.push({k, 0});                                                                    // push start node first

        while (!q.empty())
        {
            auto [node, dist] = q.top();
            q.pop();

            for (auto it : adj[node])
            {
                auto [x, y] = it; // node, distance
                if (y + dist < distance[x])
                {
                    q.push({x, y + dist});
                    distance[x] = y + dist;
                }
            }
        }

        int ans = 0;

        for (int i = 1; i < n + 1; i++)
        {
            if (distance[i] == INT_MAX)
                return -1;
            ans = max(distance[i], ans);
        }
        return ans;
    }
};