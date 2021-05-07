// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

class Solution
{
public:
    void travel(string s, vector<vector<int>> &m, int x, int y, int n, vector<string> &ans)
    {
        
        if (x<0||x>=n)
            return;
        if (y <0 || y >= n)
            return;
        if (m[x][y] == 0)
            return;
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(s);
            return;
        }
        // deb2(x,y);
        m[x][y]=0;
        travel(s + 'U', m, x - 1, y, n, ans);
        travel(s + 'D', m, x + 1, y, n, ans);
        travel(s + 'L', m, x, y - 1, n, ans);
        travel(s + 'R', m, x, y + 1, n, ans);
        m[x][y]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string s = "";
        travel(s, m, 0, 0, n, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}