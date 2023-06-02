/*
Link: https://leetcode.com/problems/sliding-window-maximum/
*/

// TC = O((n-k)*k)
// SC = O(k)

// Optimal

// TC = O((n-k)*log k)
// SC = O(k)

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();

        multiset<int> st;
        vector<int> ans;

        for (int i = 0; i < k; i++)
            st.insert(nums[i]);

        /* adding the maximum element in vector of the multiset
        for the current window. */
        ans.push_back(*st.rbegin());

        /* window size is fixed.*/
        for (int i = k; i < n; i++)
        {

            /* adding a new element each time from given array to
            the multiset. */
            st.insert(nums[i]);

            /* deleting the first element of the window each time
            from the multiset.*/
            st.erase(st.find(nums[i - k]));

            /* adding the maximum element in vector of the multiset
            for the current window. */
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};