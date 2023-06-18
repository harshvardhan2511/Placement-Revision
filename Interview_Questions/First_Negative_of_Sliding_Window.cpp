/*
TC: O(N)
SC: O(N)
Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    stack<int> st;
    for (int i = N; i > -1; i--)
        if (A[i] < 0)
            st.push(i);

    int i = 0, j = K - 1;
    vector<long long> ans;

    while (j < N)
    {
        if (!st.empty() && st.top() <= j)
        {
            ans.push_back(A[st.top()]);
            if (i == st.top())
                st.pop();
        }
        else
            ans.push_back(0);

        i++;
        j++;
    }

    return ans;
}