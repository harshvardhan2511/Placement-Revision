/*
Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
TC: O(2*nlogn) + O(2n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std

    class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 1, j = 0, platform_needed = 1, maxi = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platform_needed++;
                i++;
            }
            else if (arr[i] > dep[j])
            {
                platform_needed--;
                j++;
            }

            maxi = max(maxi, platform_needed);
        }

        return maxi;
    }
};
