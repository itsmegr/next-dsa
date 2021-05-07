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

int getPairsCount(int arr[], int n, int k)
{
   map<int , int> rept;
   int ans=0;

   for(int i=0;i<n;i++){
       rept[arr[i]]++;
   }
   for(int i=0;i<n;i++){
       if(k-arr[i]>0){
           if(k-arr[i]==arr[i]&&rept[k-arr[i]]>0){
              ans = ans + rept[k-arr[i]]-1;
              continue;
           }
           ans = ans + rept[k-arr[i]];
       }
   }
   return ans/2;

}

void solve()
{
    int i, j, n, m, k;
    cin >> n >> k;
    int arr[n];
    takeArrayInput(arr, n);
    cout<<getPairsCount(arr, n, k)<<endl;
}