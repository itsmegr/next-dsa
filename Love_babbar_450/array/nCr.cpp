// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Templatec for C++

class Solution
{
public:
    int **dp;
    int M = 1e9 + 7;
    ;
    long long int sol(int n, int r)
    {
        if (n < r)
            return 0;
        if (n == r)
            return 1;
        if (r == 0)
            return 1;

        if (dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] = nCr(n - 1, r) % M + nCr(n - 1, r - 1) % M;
    }

    int nCr(int n, int r)
    {
        dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[r + 1];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                dp[i][j] = -1;
            }
        }
        // Your code here
        return sol(n, r);
    }
    int nCr(int n, int r)
    {
        int M = 1e9 + 7;
        int t[n + 1][r + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                if (i == j || j == 0)
                    t[i][j] = 1;
                if (i < j)
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= r; j++)
            {
                t[i][j] = (t[i-1][j] + t[i-1][j-1])%M;
            }
        }
        return t[n][r];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends