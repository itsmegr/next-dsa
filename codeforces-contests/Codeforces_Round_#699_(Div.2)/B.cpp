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
    int i, j = 0, n, m, k;
    cin >> n >> k;
    int a[n];
    takeArrayInput(a, n);

    // for (int i = 1; i <= k; i++)
    // {
    //     for (j = 0; j < n - 1; j++)
    //     {
    //         if (a[j] < a[j + 1])
    //         {
    //             a[j]++;
    //             break;
    //         }
    //     }
    // }

    for (i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            a[i]++;
            
            j++;
            // deb2(j, i);
            //  fo(m, n) cout << a[m] << " ";
            //  cout << endl;
            if (j == k)
                break;
            i = i-2;
           
            
        }
    }

    if (i == n - 1)
        cout << -1 << endl;
    else
        cout << i + 1 << endl;
}