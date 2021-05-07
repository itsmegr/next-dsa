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

bool com(int x, int y){
    return x>y;
}
void solve()
{
    int i, j, n, m, ans=0;
    cin>>n>>m;
    vi a,b;
    ll asum=0 ,bsum =0;
    fo(i,n){
        cin>>j;
        asum = asum+j;
        a.push_back(j);
    }
    fo(i,m){
        cin>>j;
        bsum = bsum+j;
        b.push_back(j);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(),com);
    int apop, bpop;
    i=0;
    while(asum<=bsum&&i<min(m,n)){
        apop = a[i];
        bpop = b[i];
        asum = asum-apop+bpop;
        bsum = bsum-bpop+apop;
        i++;
        ans++;
    }
    if(asum<=bsum)cout<<-1<<endl;
    else
    cout<<ans<<endl;

}