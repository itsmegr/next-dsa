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
int *dp;
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

void print(vector<int> ans)
{
    if(!is_sorted(ans.begin(), ans.end())) return;
    for(int x : ans)
    cout<<x<<" ";
    cout<<endl;
}

void ways(int n, vector<int> ans){
    if(n==0){
        print(ans);
        return;
    }

    for(int i=n;i>0;i--){
        // cout<<i<<" ";
        ans.push_back(i);
        ways(n-i, ans);
        ans.pop_back();
    }
}


void solve()
{
    int i, j, n, m;
    cin>>n;
    vector<int> ans;
    ways(n, ans);
}