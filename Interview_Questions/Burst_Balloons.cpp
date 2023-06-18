/*
TC: O(N logN)
SC: O(1)
Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int arrows = 1, endpoint = INT_MAX;

        sort(points.begin(), points.end());

        for (auto it : points)
        {
            int start = it[0], end = it[1];

            if (endpoint < start)
            {
                arrows++;
                endpoint = end;
            }
            else
                endpoint = min(end, endpoint);
        }

        return arrows;
    }
};