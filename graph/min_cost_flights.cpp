#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> dp(n, INT_MAX);
        dp[src] = 0;
        for (int i = 0; i < k + 1; ++i)
        {
            //creating a copy to just consider the 
            //only edges with length i
            //means do not update the vertex that are i+1 or more 
            //distance away from source in ith iteration
            vector<int> temp = dp;
            for (vector<int> &f : flights)
            {
                int u = f[0], v = f[1], price = f[2];
                if (temp[u] == INT_MAX)
                    continue;
                dp[v] = min(dp[v], temp[u] + price);
            }
        }
        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};



