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

void solve()
{
    int n, m, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int l = -1, h = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            l = i;
            ans++;
            s[i] = 'x';
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            h = i;
            // ans++;
            // s[i] = 'x';
            break;
        }
    }
    if (h == n)
    {
        cout << ans << endl;
        return;
    }
    vector<int> hold;
    hold.push_back(l);
    l = l + 1;
    while (l <= h && l < n)
    {
        // deb(l);
        if (s[l] == '*')
        {
            s[l] = 'x';
            hold.push_back(l);
            ans++;
        }
        if (hold.size() == 3)
        {
            // for (int x : hold)
            //     cout << x << " ";
            // cout << endl;
            // deb2(hold[2], hold[0]);
            // deb(k);
            if (hold[2] - hold[0] > k)
            {
                hold.erase(hold.begin() + 0);
            }
            else
            {
                s[hold[1]] = '*';
                hold.erase(hold.begin() + 1);
                ans--;
            }
            // for (int x : hold)
            //     cout << x << " ";
            // cout << endl;
        }
        l++;
    }
    // cout << s << endl;
    cout << ans << endl;
    return;
}