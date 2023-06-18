/*
YC: O(N)
SC: O(N)
Link: https://leetcode.com/problems/number-of-islands/submissions/
*/

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int m, int n, int i, int j)
    {

        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '0' || vis[i][j] == 1)
            return;

        vis[i][j] = 1;

        dfs(grid, vis, m, n, i, j - 1);
        dfs(grid, vis, m, n, i, j + 1);
        dfs(grid, vis, m, n, i - 1, j);
        dfs(grid, vis, m, n, i + 1, j);

        return;
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int m = grid[0].size();
        int n = grid.size();
        int total = 0;

        vector<vector<int>> vis(n, vector<int>(m, -1));
        // memset(vis, -1, sizeof(vis));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 1 && grid[i][j] == '1')
                {
                    dfs(grid, vis, m, n, i, j);
                    total++;
                }
            }
        }

        return total;
    }
};