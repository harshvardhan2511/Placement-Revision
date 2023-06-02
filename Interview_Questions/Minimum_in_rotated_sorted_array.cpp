/*
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

// TC = O(nlogn) sort the array again
// SC = O(1)

// Optimise

// TC = O(log n) hybrid binary search
// SC = O(1)

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int mn = nums[0];
        int left = 0, right = nums.size() - 1, mid;

        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                mn = min(mn, nums[left]);
                break;
            }

            mid = (left + right) / 2;
            mn = min(mn, nums[mid]);

            if (nums[mid] >= nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return mn;
    }
};