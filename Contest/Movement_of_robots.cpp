class Solution
{
public:
    const int MOD = 1e9 + 7;

    // USE PREFIX SUM WHENEVER REQUIRED TO CALCULATE DISTANCE BETWEEN ALL PAIRS

    int sumDistance(vector<int> &nums, string s, int d)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
                nums[i] += d * 1;
            else
                nums[i] += d * -1;
        }

        sort(nums.begin(), nums.end());
        for (auto it : nums)
            cout << it << " ";
        long sum = 0, prefSum = 0;
        for (int i = 0; i < n; i++)
        {

            // WHILE TAKING MOD DONT USE += OR -= ETC. WRITE FULL SUM = SUM + VALUE THEN TAKE MOD OF WHOLE (SUM + VALUE)

            sum = (sum + (i * (long)nums[i] - (prefSum))) % MOD;
            prefSum += nums[i] % MOD;
        }

        return (int)sum;
    }
};