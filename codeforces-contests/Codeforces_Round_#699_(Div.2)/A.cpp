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

void spaceNav(string s, int px, int py)
{
    int cx = 0, cy = 0, l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'L')
            cx--, l++;
        else if (s[i] == 'R')
            cx++, r++;
        else if (s[i] == 'D')
            cy--, d++;
        else if (s[i] == 'U')
            cy++, u++;
    }
    // deb2(cx, cy);
    // deb2(px, py);
    if (cx - px == 0 && cy - py == 0)
    {
        cout << "YES" << endl;
        return;
    }
    int reqx = cx - px, reqy = cy - py;
    // deb2(reqx, reqy);
    if (reqx > 0)
    {
        if (r < reqx)
        {
            cout << "NO" << endl;
            return;
        }
    }
    else if(reqx<0)
    {
        if (l < -1 * reqx)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (reqy > 0)
    {
        if (u < reqy)
        {
            cout << "NO" << endl;
            return;
        }
    }
    else if(reqy<0)
    {
        if (d < -1 * reqy)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

void solve()
{
    int i, j, n, m, px, py;
    string s;
    cin >> px >> py;
    cin >> s;
    spaceNav(s, px, py);
}