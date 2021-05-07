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
void check(string s1, string s2, int changes, int &ans)
{
    int l1 = s1.length();
    int l2 = s2.length();
    if (l1 == 0 && l2 == 0)
        return;
    if (s1 == s2)
    {
        ans = min(ans, changes);
        return;
    }
    deb2(s1, s2);
    if (l1 > 0)
    {

        check(s1.substr(1, l1 - 1), s2, changes + 1, ans);
    }
    if (l1 > 0)
    {
        check(s1.substr(0, l1 - 1), s2, changes + 1, ans);
    }
    if (l2 > 0)
    {
        check(s1, s2.substr(1, l2 - 1), changes + 1, ans);
    }
    if (l2 > 0)
    {
        check(s1, s2.substr(0, l2 - 1), changes + 1, ans);
    }
}

void solve()
{
    int i, j, n, m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int ans = 0;
    for (int len = 1; len <= min(s1.length(), s2.length()); len++)
    {
        for (int i = 0; i <= s1.length() - len; i++)
        {
            for (int j = 0; j <= s2.length() - len; j++)
            {
                if(s1.substr(i, len)==s2.substr(j, len)){
                    ans= max(len, ans);
                }
            }
        }
    }
    cout<<s1.length()-ans + s2.length()-ans<<endl;
}