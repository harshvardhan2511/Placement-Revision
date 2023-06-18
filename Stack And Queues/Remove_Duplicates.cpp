/*
TC: O(N)
SC: O(N)
Link: https://leetcode.com/problems/remove-duplicate-letters/
*/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        map<char, int> mp;
        int n = s.length();
        for (auto x : s)
            mp[x]++;

        stack<char> st;
        vector<bool> visited(26, false);
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]--;
            if (visited[s[i] - 'a'])
                continue;

            while (!st.empty() && st.top() > s[i] && mp[st.top()] > 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        string ans = "";

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};