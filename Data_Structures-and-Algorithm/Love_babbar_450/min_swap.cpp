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
int minSwap(int *arr, int n, int k)
{
    //sliding window concept

    int total_small_ele = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k) total_small_ele++;
    }

    int bina_kam_ke_ele_in_sliding_window = 0;

    for(int i=0;i<total_small_ele;i++){
         if(arr[i]>k) bina_kam_ke_ele_in_sliding_window++;
    }

    int ans = bina_kam_ke_ele_in_sliding_window;
    for(int i=0, j=total_small_ele;j<n;j++, i++){
        if(arr[i]<=k) bina_kam_ke_ele_in_sliding_window++;
        if(arr[j]<=k) bina_kam_ke_ele_in_sliding_window--;
        ans = min(ans, bina_kam_ke_ele_in_sliding_window);
    }
    return ans;

}

void solve()
{
    int i, j, n, m, k;
    cin >> n;
    int a[n];
    takeArrayInput(a, n);
    cin>>k;
    cout<<minSwap(a, n, k)<<endl;
}