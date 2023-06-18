/*
TC: O(N)
SC: O(1)
Link: https://leetcode.com/problems/house-robber-ii/
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // Since its a circular matrix, we cannot take first and last element at same time
        // Leave out last element
        int n1 = 0, n2 = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += n2;

            int notPick = 0 + n1;

            int curr = max(pick, notPick);

            n2 = n1;
            n1 = curr;
        }

        int ans1 = n1;

        // Leave out first element
        n1 = 0;
        n2 = 0;

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += n2;

            int notPick = 0 + n1;

            int curr = max(pick, notPick);

            n2 = n1;
            n1 = curr;
        }

        int ans2 = n1;

        return max(ans1, ans2);
    }
};