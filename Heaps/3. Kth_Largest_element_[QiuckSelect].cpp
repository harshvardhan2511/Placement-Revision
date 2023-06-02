/*
TC = O(N) Average
SC = O(1)
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
Explanation: https://www.youtube.com/watch?v=ZAXSFph_L-A
*/

class Solution
{
public:
    int partition(vector<int> &A, int n, int start, int end)
    {
        int L = start;
        int R = end;

        while (L < R)
        {
            if (A[L + 1] <= A[L])
            {
                swap(A[L], A[L + 1]);
                L++;
            }
            else if (A[L] < A[R])
                R--;
            else
                swap(A[L + 1], A[R]);
        }
        cout << L << endl;
        return L;
    }

    int solve(vector<int> nums, int n, int k, int start, int end)
    {
        int p = partition(nums, nums.size(), start, end);

        if (p == k)
            return nums[k];
        else if (k < p)
            return solve(nums, p, k, start, p - 1);
        else
            return solve(nums, n - (p + 1), k, p + 1, end);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        return solve(nums, nums.size(), nums.size() - k, 0, nums.size() - 1);
    }
};