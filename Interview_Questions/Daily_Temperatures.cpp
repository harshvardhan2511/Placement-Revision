/*
Link: https://leetcode.com/problems/daily-temperatures/
*/

// Brute force
// TC: O(N2)
// SC: O(1)

// Optimal (using monotonic decreasing stack)
// TC: O(N)
// SC: O(N)

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        int n = temp.size();

        stack<pair<int, int>> st; // temp, index
        vector<int> ans(n, 0);

        st.push({temp[0], 0});

        for (int i = 1; i < n; i++)
        {

            while (!st.empty() && temp[i] > st.top().first)
            {
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({temp[i], i});
        }

        return ans;
    }
};