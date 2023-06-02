/*
Link: https://leetcode.com/problems/rotting-oranges/
*/

// TC: O(N2)
// SC: O(N2)

class Solution
{
public:
    void rotThem(vector<vector<int>> &grid, queue<pair<int, int>> &q, int m, int n, int &freshCount)
    {
        auto [i, j] = q.front();
        cout << i;
        // down
        if (i + 1 < m && grid[i + 1][j] == 1)
        {
            grid[i + 1][j] = 2;
            freshCount--;
            q.push({i + 1, j});
        }
        // up
        if (i - 1 > -1 && grid[i - 1][j] == 1)
        {
            grid[i - 1][j] = 2;
            freshCount--;
            q.push({i - 1, j});
        }
        // right
        if (j + 1 < n && grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 2;
            freshCount--;
            q.push({i, j + 1});
        }
        // left
        if (j - 1 > -1 && grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 2;
            freshCount--;
            q.push({i, j - 1});
        }
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int freshCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q; // i, j

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0)
            return 0;

        int time = -1;
        while (!q.empty())
        {

            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                rotThem(grid, q, rows, cols, freshCount);
                q.pop();
            }

            time++;
        }

        if (freshCount == 0)
            return time;

        return -1;
    }
};