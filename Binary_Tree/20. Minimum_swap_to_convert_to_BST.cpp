/*
SC = O(N)
Link: https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0?page=1&sortBy=newest&query=page1sortBynewest
*/

class Solution
{
public:
    void inorder(vector<int> A, vector<int> &in, int index)
    {
        if (index >= A.size())
            return;
        inorder(A, in, 2 * index + 1);
        in.push_back(A[index]);
        inorder(A, in, 2 * index + 2);
    }

    int minSwaps(vector<int> &A, int n)
    {

        // Convert A(levelOrder) to inOrder
        vector<int> in;
        inorder(A, in, 0);

        // for(auto it : in) cout<<it<<" ";

        vector<int> sorted = in;
        int ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[in[i]] = i;

        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < n; i++)
        {
            if (in[i] != sorted[i])
            {
                int temp = mp[sorted[i]];
                swap(in[i], in[mp[sorted[i]]]);
                mp[sorted[i]] = i;
                mp[in[temp]] = temp;
                ans++;
            }
        }
        return ans;
    }
};