/*
TC = O(n+m)
SC = O(n+m)
Link: https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
*/

class Solution
{
public:
    void heapify(vector<int> &ar, int i, int size)
    {
        if (i >= size)
            return;

        int p = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;

        if (ar[l] > ar[p] && l < size)
            p = l;
        if (ar[r] > ar[p] && r < size)
            p = r;

        if (p != i)
        {
            swap(ar[p], ar[i]);
            heapify(ar, p, size);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        vector<int> ans;

        for (auto it : a)
            ans.push_back(it);
        for (auto it : b)
            ans.push_back(it);

        // first non-leaf node from back
        int i = ans.size() / 2 - 1;

        for (i; i > -1; i--)
            heapify(ans, i, ans.size());

        return ans;
    }
};