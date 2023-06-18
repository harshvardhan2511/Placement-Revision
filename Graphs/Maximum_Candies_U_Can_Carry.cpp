/*
TC: O(N)
SC: O(N)
Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
*/

class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        queue<int> q;          // boxes (with key) ready to be processed
        unordered_set<int> st; // boxes (without key) we got

        int count = 0; // candies

        for (int i = 0; i < initialBoxes.size(); i++)
            if (status[initialBoxes[i]])
                q.push(initialBoxes[i]);
            else
                st.insert(initialBoxes[i]);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto it : containedBoxes[curr])
            {
                if (status[it])
                    q.push(it);
                else
                    st.insert(it);
            }

            for (auto it : keys[curr])
            {
                if (st.find(it) != st.end())
                {
                    st.erase(it);
                    q.push(it);
                }
                else
                    status[it] = 1;
            }
            count += candies[curr];
        }

        return count;
    }
};