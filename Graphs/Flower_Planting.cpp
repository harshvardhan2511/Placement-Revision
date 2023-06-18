/*
TC: O(N*M)
SC: O(N*M)
Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/
*/

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<int> colorOfNode(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for (auto it : paths)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 1; i < adj.size(); i++)
        {
            if (colorOfNode[i] != 0)
                continue;

            unordered_set<int> color({1, 2, 3, 4});
            for (auto x : adj[i])
            {
                if (color.find(colorOfNode[x]) != color.end())
                {
                    auto toBeErased = color.find(colorOfNode[x]);
                    color.erase(toBeErased);
                }
            }

            colorOfNode[i] = *color.begin();
        }

        colorOfNode.erase(colorOfNode.begin());
        return colorOfNode;
    }
};