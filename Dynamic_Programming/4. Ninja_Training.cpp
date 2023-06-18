/* Link: https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=1 */
// MEMOIZATION
// TC: O(N x 4) x 3
// SC: O(N x 4) + O(N)
int solve(int days, int last, vector<vector<int>> points, vector<vector<int>> &dp)
{
    if (days == 0)
    {
        int mx = 0;
        for (auto i : points[0])
            if (i != points[0][last])
                mx = max(i, mx);
        return mx;
    }

    if (dp[days][last] != -1)
        return dp[days][last];

    int mx = 0, currPoint;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            currPoint = points[days][i] + solve(days - 1, i, points, dp);
            mx = max(currPoint, mx);
        }
    }

    return dp[days][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return solve(n - 1, 3, points, dp);
}

// TABULATION
// TC: O(N x 4) x 3
// SC: O(N x 4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // Writing base cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

    // Now do bottom up
    int currPoint;
    for (int days = 1; days < n; days++)
    {
        for (int last = 0; last < 4; last++)
        {

            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    currPoint = points[days][i] + dp[days - 1][i];
                    dp[days][last] = max(currPoint, dp[days][last]);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// FURTHER SPACE OPTIMIZATION
// TC: O(N x 4) x 3
// SC: O(1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> v(4);
    // Writing base cases
    v[0] = max(points[0][1], points[0][2]);
    v[1] = max(points[0][0], points[0][2]);
    v[2] = max(points[0][0], points[0][1]);
    v[3] = max(points[0][1], max(points[0][1], points[0][2]));

    // Now do bottom up
    vector<int> temp(4);
    int currPoint;
    for (int days = 1; days < n; days++)
    {
        for (int last = 0; last < 4; last++)
        {

            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    currPoint = points[days][i] + v[i];
                    temp[last] = max(currPoint, temp[last]);
                }
            }
        }
        v = temp;
    }

    return v[3];
}