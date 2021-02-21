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

void selectionSortRec(int a[], int n, int i, int j, int &min, int &index)
{
    if (i < n)
    {
        if (j < n)
        {
            if (a[j] < min)
                min = a[j], index = j;
            selectionSortRec(a, n, i, j + 1, min, index);
        }
        else
        {
            swap(a[i], a[index]);
            min = INT_MAX;
            selectionSortRec(a, n, i + 1, i + 1, min, index);
        }
    }
}

void selectionSort(int a[], int n)
{
    int min = INT_MAX, index, k;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] < min)
                min = a[j], index = j;
        }
        swap(a[i], a[index]);
        min = INT_MAX;
    }
}

void bubbleSort(int a[], int n, int i, int j)
{
    if (i < n - 1)
    {
        if (j < n - i - 1)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            bubbleSort(a, n, i, j + 1);
        }
        else
        {
            j = 0;
            bubbleSort(a, n, i + 1, j);
        }
    }
}

void solve()
{
    int i, j = 0, n, m;
    int min = INT_MAX, index, k;
    cin >> n;
    int arr[n];
    takeArrayInput(arr, n);
    // selectionSort(arr,n);
    // selectionSortRec(arr, 0, j, n, min, index);
    // bubbleSort(arr, n, 0, 0);
    selectionSortRec(arr, n, 0, 0, min, index);
    fo(i, n) cout << arr[i] << " ";
    // cout<<endl;
}