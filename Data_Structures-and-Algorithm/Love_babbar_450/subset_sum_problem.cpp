// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int **dp;
    int  solve(int a[], int n, int w)
    {
        if (w == 0)
            return 1;

        if (w != 0 && n == 0)
            return 0;
    
        if(dp[n][w]!=-1) return dp[n][w];


        if (a[n - 1] > w)
            return solve(a, n - 1, w);

        return dp[n][w] =  solve(a, n-1, w-a[n-1])||solve(a, n-1, w);//both are true
    }

    int equalPartition(int N, int arr[])
    {
        int w = 0;
        for (int i = 0; i < N; i++)
            w = w + arr[i];
        if (w % 2 == 1)
            return 0;

        w = w / 2;

        dp = new int *[N + 1];
        for (int i = 0; i <= N; i++)
        {
            dp[i] = new int[w + 1];
        }

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }
        return solve(arr, N, w);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends