/*
TC: O(MxN)
SC: O(MxN)
Link: https://leetcode.com/problems/surrounded-regions/submissions/
*/

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int m, int n, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'X' || vis[i][j] == 1)
            return;
        if (grid[i][j] == 'O')
            vis[i][j] = 1;

        dfs(grid, vis, m, n, i + 1, j);
        dfs(grid, vis, m, n, i - 1, j);
        dfs(grid, vis, m, n, i, j + 1);
        dfs(grid, vis, m, n, i, j - 1);

        return;
    }

    void solve(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // first and last columns
        for (int i = 0; i < m; i++)
        {
            if (vis[i][0] != 1 && grid[i][0] == 'O')
                dfs(grid, vis, m, n, i, 0);
            if (vis[i][n - 1] != 1 && grid[i][n - 1] == 'O')
                dfs(grid, vis, m, n, i, n - 1);
        }

        // first and last rows
        for (int j = 0; j < n; j++)
        {
            if (vis[0][j] != 1 && grid[0][j] == 'O')
                dfs(grid, vis, m, n, 0, j);
            if (vis[m - 1][j] != 1 && grid[m - 1][j] == 'O')
                dfs(grid, vis, m, n, m - 1, j);
        }

        // make remaining O's = X
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 'O' && vis[i][j] == 0)
                    grid[i][j] = 'X';
            }
        }

        return;
    }
};