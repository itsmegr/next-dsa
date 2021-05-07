#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
void takeArrayInput(int arr[], int n)
{
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

int **dp;

int sol(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if(dp[n][W]!=-1) return dp[n][W];

    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + sol(W - wt[n - 1], wt, val, n - 1), sol(W, wt, val, n - 1));
    }
    else
        return dp[n][W] = sol(W, wt, val, n - 1);
}

int knapSack(int W, int wt[], int val[], int n)
{
    dp = new int*[n+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[W+1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    // Your code here
    return sol(W, wt, val, n);
}

int knapSack(int W, int wt[], int val[], int n)
{
    int t[n+1][W+1];
    memset(t, -1, sizeof(t));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0) t[i][j]=0;
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]>j) t[i][j] = t[i-1][j];
            else{
                t[i][j] = max(t[i-1][j-wt[i-1]]+val[i-1], t[i-1][j]);
            }
        }
    }
    return t[n][W];
}

void solve()
{
    int i, j, n, m;
}