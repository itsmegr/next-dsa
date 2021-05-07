#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
void takeArrayInput(int arr[], int n){
    int i;
    fo(i,n){
        cin>>arr[i];
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
    while(t--) {
      solve();
    }
    return 0;
}
long long maxSubarraySum(int arr[], int n){
    long long max_ending_here = arr[0];
    long long min_ending_here = arr[0];
    long long max_so_far_ans = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]<0) swap(max_ending_here, min_ending_here);

        max_ending_here = max((long long)arr[i], max_ending_here*arr[i]);
        min_ending_here = min((long long)arr[i], min_ending_here*arr[i]);

        max_so_far_ans = max(max_ending_here, max_so_far_ans);
    }
    return max_so_far_ans;
}


void solve()
{
    int i, j, n, m;
    cin>>n;
    int arr[n];
    takeArrayInput(arr, n);
    cout<<maxSubarraySum(arr, n)<<endl;

}