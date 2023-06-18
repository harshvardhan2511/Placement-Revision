/*
TC: O(MxN)
SC: O(MxN)
Link: https://leetcode.com/problems/flood-fill/
*/

// BFS

class Solution
{
public:
    void colorIt(vector<vector<int>> &grid, int m, int n, int i, int j, queue<pair<int, int>> &q, int color, int prev)
    {
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == color || grid[i][j] != prev)
            return;
        grid[i][j] = color;

        colorIt(grid, m, n, i + 1, j, q, color, prev);
        q.push({i + 1, j});
        colorIt(grid, m, n, i - 1, j, q, color, prev);
        q.push({i - 1, j});
        colorIt(grid, m, n, i, j + 1, q, color, prev);
        q.push({i, j + 1});
        colorIt(grid, m, n, i, j - 1, q, color, prev);
        q.push({i, j - 1});
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> q;
        int prev = image[sr][sc];
        q.push({sr, sc});
        int m = image.size(), n = image[0].size();

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            colorIt(image, m, n, i, j, q, color, prev);
        }
        image[sr][sc] = color;
        return image;
    }
};