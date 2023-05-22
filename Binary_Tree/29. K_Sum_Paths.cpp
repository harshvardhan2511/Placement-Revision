/*
TC = O(N)
SC = O(N)
Link: https://practice.geeksforgeeks.org/problems/k-sum-paths/1
*/

class Solution
{
public:
#define ll long long
    map<ll, int> mp;
    int ans = 0;
    void solve(Node *root, int targetSum, ll currSum)
    {
        if (root == NULL)
            return;
        currSum += root->data;
        ans += mp[currSum - targetSum]; // it mean between the ongoing process there is a place where targetSum is generated.
        mp[currSum]++;
        solve(root->left, targetSum, currSum);
        solve(root->right, targetSum, currSum);
        mp[currSum]--;
        currSum -= root->data;
    }
    int sumK(Node *root, int targetSum)
    {
        mp[0]++;
        ll currSum = 0;
        solve(root, targetSum, currSum);
        return ans;
    }
};