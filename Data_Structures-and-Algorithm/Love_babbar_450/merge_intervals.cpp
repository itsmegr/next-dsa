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

bool compareInterval(vector<int> i1, vector<int> i2)
{
    return (i1[0] < i2[0]);
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    vector<int> intAns;
    sort(intervals.begin(), intervals.end(),compareInterval);
    int start = intervals[0][0], end = intervals[0][1], j = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > end)
        {
            intAns.push_back(start);
            intAns.push_back(end);
            ans.push_back(intAns);
            intAns.clear();
            start = -1, end = -1;
            if (i < intervals.size())
            {
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        else if (intervals[i][1]>end)
            end = intervals[i][1];
    }

    if (start != -1 && end != -1)
    {
        intAns.push_back(start);
        intAns.push_back(end);
        ans.push_back(intAns);
    }
    return ans;
}


void solve()
{
    int i, j, n, m;
}