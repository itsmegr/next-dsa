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

void merge(int a[], int l, int h)
{
    int mid = (l + h) / 2;
    int i = l, j = mid + 1;
    int mergedArray[h - l + 1], k = 0;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            mergedArray[k] = a[i];
            k++;
            i++;
        }
        else
        {
            mergedArray[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        mergedArray[k] = a[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        mergedArray[k] = a[j];
        k++;
        j++;
    }
    k = l;
    while (k <= h)
    {
        a[k] = mergedArray[k - l];
        k++;
    }
}

void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, h);
    }
}

void solve()
{
    int i, j, n, m;
    cin >> n;
    int a[n];
    takeArrayInput(a, n);
    mergeSort(a, 0, n-1);
    fo(i, n) cout << a[i] << " ";
    cout << endl;
}