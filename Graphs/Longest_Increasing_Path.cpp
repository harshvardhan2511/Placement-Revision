/*
TC = O(MxN)
SC = O(MxN)
Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

class Solution
{
public:
    int DP(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
    {

        if (i < 0 or i >= n or j < 0 or j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = 0;
        int right = 0;
        int down = 0;
        int left = 0;

        if (i - 1 >= 0 and matrix[i - 1][j] > matrix[i][j])
            up = 1 + DP(i - 1, j, matrix, n, m, dp);

        if (j + 1 < m and matrix[i][j + 1] > matrix[i][j])
            right = 1 + DP(i, j + 1, matrix, n, m, dp);

        if (i + 1 < n and matrix[i + 1][j] > matrix[i][j])
            down = 1 + DP(i + 1, j, matrix, n, m, dp);

        if (j - 1 >= 0 and matrix[i][j - 1] > matrix[i][j])
            left = 1 + DP(i, j - 1, matrix, n, m, dp);

        return dp[i][j] = max({up, right, down, left});
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, DP(i, j, matrix, n, m, dp));
            }
        }
        return ans + 1;
    }
};