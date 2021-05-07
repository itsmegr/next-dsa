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
int *dp;
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
int solution(vector<int> &cost, int i, int n, vector<int> &dp){
    if(i==n||i==n-1) return cost[i];
    if(dp[i]!=-1) return dp[i];
    return dp[i] = min(cost[i] + solution(cost, i+1, n,dp), cost[i] + solution(cost, i+2, n,dp));
}

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size(), -1);
    dp[0] = solution(cost, 0, cost.size()-1,dp);
    dp[1] = solution(cost, 1, cost.size()-1,dp);
    return min(dp[0],dp[1]);
}

void solve()
{
    int i, j, n, m;
    cin>>n;
    vi arr(n, 0);
    fo(i,n){
        cin>>arr[i];
    }
    cout<<minCostClimbingStairs(arr)<<endl;
}