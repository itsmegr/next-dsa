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


void solve()
{
    int i, j, n, m,x, max=0, sum, min = 0;
    cin>>n>>x;
    vi ar;

    fo(i,n){
        cin>>m;
        ar.push_back(m);
    }

    for(int i:ar){
        // cout<<i<<" ";
        if(i%x==0){
            max = max+(i/x);
        }
        else{
            max = max+(i/x)+1;
        }
    }

    fo(i,n){
        if(i%x==0){
            min = min+(ar[i]/x);
            // deb(min);
        }
        else{
            if(i+1<n){
                if((ar[i]+ar[i+1])%x==0){
                    min = min+(ar[i]+ar[i+1])/x;
                    i++;
                }
                else{
                    min = min+(ar[i]/x)+1;
                }
            }
            else{
                if(i%x==0){
                    min = min+(ar[i]/x);
                }
                else{
                    min = min+(ar[i]/x)+1;
                }
            }
        }
    }
    cout<<min<<" "<<max<<endl;



}