/*
TC: O(N)
SC: O(N)
Link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
*/

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n < 3)
            return false;

        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                if (s[i] == 'a')
                    st.push(s[i]);
                else
                    return false;

            else if (s[i] == 'b' && st.top() == 'a')
            {
                st.pop();
                st.push(s[i]);
            }
            else if (s[i] == 'c' && st.top() == 'b')
                st.pop();
            else if (s[i] == 'a')
                st.push(s[i]);
            else
                return false;
        }
        cout << st.size();
        return st.size() == 0;
    }
};

/*
ab handled
bc handled

ca
ba These are valid because new string will always start from a
aa

Other than these all are invalid.
*/