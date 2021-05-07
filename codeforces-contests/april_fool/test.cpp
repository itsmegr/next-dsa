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
void solve()
{
    int i, j, n, m;
    cin>>n;
    vi ar(n,0);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int ans = 1;
    int lastLevelEle = 1;
    int thisLevelEle = 1;
    for(int i=1;i<n-1;i++){

        if(ar[i]>ar[i+1]&&lastLevelEle==1){
            lastLevelEle = thisLevelEle;
            thisLevelEle = 1;
            ans++;
        } 
        else if(ar[i]>ar[i+1]){
            lastLevelEle--;
            thisLevelEle++;
        }
        else{
            thisLevelEle++;
        }

    }
    cout<<ans<<endl;
    return;
    
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

