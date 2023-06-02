/*
TC: O(N)
SC: O(N)
Link: https://leetcode.com/problems/reorganize-string/
*/

class Solution
{
public:
    string reorganizeString(string s)
    {
        // step 1: count the occurrences of each charcater in given string ==> O(n) Time, O(1) Space
        vector<int> chrCounts(26);
        for (auto &chr : s)
        {
            if (++chrCounts[chr - 97] > (s.size() + 1) / 2)
                return "";
        }

        // step 2: make a max_heap of pair<charCount, char>  ==> O(1) Time and Space
        priority_queue<pair<int, char>> max_heap;
        for (int i = 0; i < 26; i++)
        {
            if (chrCounts[i])
            {
                max_heap.push({chrCounts[i], 97 + i});
            }
        }

        // step 3: pop top 2 characters and put them into result string to create alteration
        int i = 0;
        pair<int, char> prev = max_heap.top();
        max_heap.pop();
        s[i++] = prev.second;
        while (not max_heap.empty())
        {
            pair<int, char> curr = max_heap.top();
            max_heap.pop();
            s[i++] = curr.second;
            if (--prev.first)
                max_heap.push(prev);
            prev = curr;
        }
        return s;
    }
};