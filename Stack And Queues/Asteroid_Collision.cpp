/*
TC: O(N)
SC: O(N)

Link: https://leetcode.com/problems/asteroid-collision/
*/

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &nums)
    {
        stack<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.empty() or nums[i] > 0)
                s.push(nums[i]);

            else
            {
                while (true)
                {
                    if (s.top() * nums[i] > 0)
                    {
                        s.push(nums[i]);
                        break;
                    }
                    else if (s.top() > -(nums[i]))
                        break;

                    else if (s.top() == -nums[i])
                    {
                        s.pop();
                        break;
                    }

                    else if (s.top() < -(nums[i]))
                    {
                        s.pop();
                        if (s.empty())
                        {
                            s.push(nums[i]);
                            break;
                        }
                    }
                }
            }
        }

        vector<int> ans(s.size());
        for (int i = s.size() - 1; i > -1; i--)
        {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};
