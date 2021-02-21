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
int maximumGain(string s, int x, int y) {
    string s1="ab",s2="ba";
    if(y>x){ swap(x,y),swap(s1,s2);};
    int index=0,sum =0;
    while(index!=string::npos){
        index=s.find(s1);
        if(index!=string::npos){
            s.erase(index,2);
            sum = sum+x;
            continue;
        }
        index=s.find(s2);
        if(index!=string::npos){
            s.erase(index,2);
            sum = sum+y;
        }
    }
    return sum;
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


void solve()
{
    int i, j, n, m;
}