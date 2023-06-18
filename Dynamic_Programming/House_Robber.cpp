/*
Link: https://leetcode.com/problems/house-robber/
*/

// ----TC--SC----
//  TLE (2^n) (N)

class Solution
{
public:
    int solve(vector<int> &nums, int i)
    {
        if (i == 0)
            return nums[0];
        if (i < 0)
            return 0;

        int pick = nums[i] + solve(nums, i - 2);
        int notPick = solve(nums, i - 1);

        return max(pick, notPick);
    }

    int rob(vector<int> &nums)
    {
        return solve(nums, nums.size() - 1);
    }
};

//  Memoize O(N) O(N+N)

class Solution
{
public:
    int solve(vector<int> &nums, vector<int> &dp, int i)
    {
        if (i == 0)
            return nums[0];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + solve(nums, dp, i - 2);
        int notPick = solve(nums, dp, i - 1);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums, dp, nums.size() - 1);
    }
};

//  Tabulation / DP O(N) O(N)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        // Base Case
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];

            int notPick = 0 + dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};

//  Tabulation Space-Optimization O(N) O(1)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        int n1 = 0, n2 = 0;

        for (int i = 0; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += n2;

            int notPick = 0 + n1;

            int curr = max(pick, notPick);

            n2 = n1;
            n1 = curr;
        }

        return n1;
    }
};