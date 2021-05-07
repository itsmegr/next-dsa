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

int findLongestConseqSubseq(int arr[], int N)
{
    map<int, int> ans;

    map<int, int>::iterator it2;
    for (int i = 0; i < N; i++)
    {
        ans[arr[i]] = 1;
    }
    int maxCon = 0, curr = 0;
    for (auto it = ans.begin(); it != ans.end() && N > 1; it++)
    {
        N--;
        it2 = ++it;
        it--;
        if (it->first + 1 == it2->first)
        {
            curr++;
            maxCon = max(maxCon, curr);
        }
        else
            curr = 0;
        //    cout<<it->first<<" "<<it2->first<<endl;;
    }
    //    cout<<endl;

    return maxCon + 1;
}

void solve()
{
    int i, j, n, m;
    cin >> n;
    int a[n];
    takeArrayInput(a, n);
    cout << findLongestConseqSubseq(a, n) << endl;
}