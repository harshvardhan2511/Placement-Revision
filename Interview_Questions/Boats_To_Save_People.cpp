/*
TC: O{n logn}
SC: O(1)
Link: https://leetcode.com/problems/boats-to-save-people/
*/
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {

        sort(people.begin(), people.end());

        int boats = 0, start = 0, end = people.size() - 1;

        while (start < end)
        {

            // Try to carry the heaviest people first

            if (people[end] + people[start] <= limit)
            {
                start++;
                end--;
            }
            else
            {
                end--;
            }
            boats++;
        }
        if (start == end)
            boats++;
        return boats;
    }
};