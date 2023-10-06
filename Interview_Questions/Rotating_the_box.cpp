/*
TC = O(m x n)
SC = O(m x n)
Link: https://leetcode.com/problems/rotating-the-box/
*/
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < m; i++)
        {
            int base = n - 1, ptr = n - 1;
            while (ptr >= 0)
            {
                if (box[i][ptr] == '.')
                {
                    ptr--;
                }
                else if (box[i][ptr] == '#')
                {

                    if (base != ptr)
                    {
                        box[i][base] = '#';
                        box[i][ptr] = '.';
                    }
                    ptr--;
                    base--;
                }
                else if (box[i][ptr] == '*')
                {
                    ptr--;
                    base = ptr;
                }
            }
        }

        // rotate
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][m - 1 - i] = box[i][j];
            }
        }

        return ans;
    }
};

/*
# . #
# . #
*/