/*
TC:
SC: O(1)
Link: https://leetcode.com/problems/count-operations-to-obtain-zero/
*/

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        if (num1 == 0 || num2 == 0)
            return 0;

        int a, b; // keeping a > b
        if (num1 > num2)
        {
            a = num1;
            b = num2;
        }
        else
        {
            b = num1;
            a = num2;
        }

        if (a % b == 0)
            return a / b;
        int ans = 0;
        while (a % b != 0)
        {
            ans += a / b;
            int remainder = a % b;
            a = b;
            b = remainder;
        }

        return ans + (a / b);
    }
};