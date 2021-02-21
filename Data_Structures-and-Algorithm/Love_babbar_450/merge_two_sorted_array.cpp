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

// void merge(int arr1[], int arr2[], int n, int m)
// {
//     int i = 0, j = 0;
//     while (i < n && j < m)
//     {
//         if (arr1[i] > arr2[j])
//         {
//             swap(arr1[i], arr2[j]);
//         }
//         int k = 0;
//         while (arr2[k] > arr2[k + 1] && k < m - 1)
//         {
//             swap(arr2[k], arr2[k + 1]);
//             k++;
//         }
//         i++;
//     }
// }

void merge(int arr1[], int arr2[], int n, int m)
{
    int i=n-1,j=0;
    while(i>=0&&j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[i--], arr2[j++]);
        }
        else break;
    }

    sort(arr1+0, arr1+n);
    sort(arr2+0, arr2+m);
}
void solve()
{
    int i, j, n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    takeArrayInput(a1, n);
    takeArrayInput(a2, m);
    merge(a1, a2, n, m);
    fo(i, n)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    fo(i, m)
    {
        cout << a2[i] << " ";
    }
    cout << endl;
}