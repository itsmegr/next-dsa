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
void firstNegative(int a[], int k, int n)
{
    deque<int> di;
    int start = 0;
    int end = 0;
    while(end<n){
        // calculations
        if(a[end]<0) di.push_back(a[end]);
        if(end-start+1<k){
            end++;
        }
        else if(end-start+1==k){
            //getting the answers
            if(di.empty()) cout<<0<<" ";
            else cout<<di.front()<<" ";

            //sliding the window
            if(a[start]==di.front()) di.pop_front();
            start++;
            end++;
        }
    }
    return;
}

void solve()
{
    int i, j, n, m, k;
    cin >> n >> k;
    int a[n];
    takeArrayInput(a, n);
    firstNegative(a,k,n);
}