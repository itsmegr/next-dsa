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
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int j;
    int max_index = -1;
     j = upper_bound(arr[0].begin(), arr[0].end(), 0) - arr[0].begin();
    if(j==m) max_index = -1, j=j-1;
    else max_index = 0, j=j-1;

    for(int i=1;i<n;i++){
        while(arr[i][j]==1&&j>=0) max_index = i, j--;
    }

    return max_index;
}

void solve()
{
    int i, j, n, m;
    cin >> n;
    int a[n];
    takeArrayInput(a, n);
    // cout<<rowWithMax1s(arr, n, m);
}