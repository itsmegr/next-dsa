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

void min_max(int l, int h, int &min, int &max, vi arr){
    if(l==h){
        min = max = arr[l];
        return;
    }
    if(h-l==1){
        if(arr[l]>arr[h]){
            min = arr[h], max = arr[l];
        }
        else{
            min = arr[l], max = arr[h];
        }
        return;
    }
    int mid = (l+h)/2;
    int minl, minr, maxl, maxr;
    min_max(l, mid,min, max, arr);
    minl = min, maxl = max;
    min_max(mid+1, h , min, max, arr);
    minr = min, maxr = max;
    min = minl>minr?minr:minl;
    max = maxl>maxr?maxl:maxr;
}
void solve()
{
    int i, j, n, m, min, max;
    vi arr;
    cin>>n;
    m=n;
    while(m>0){
        cin>>i;
        arr.pb(i);
        m--;
    }
    min_max(0,n-1,min, max, arr);
    deb2(min, max);
    
    
}