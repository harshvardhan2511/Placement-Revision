/*
TC: O(N logN)
SC: O(1)
Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        sort(a.begin(), a.end());
        long long start = 0, end = m - 1;

        long long mn = INT_MAX;

        while (end < n)
        {
            mn = min(a[end] - a[start], mn);
            start++;
            end++;
        }

        return mn;
    }
};