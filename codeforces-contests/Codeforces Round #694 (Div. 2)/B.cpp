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
    int i, j, n, m,x,sum=0,k;
    cin>>n>>x;
    vi a;
    fo(i,n){
        cin>>m;
        a.push_back(m);
    }


    int firstunafterN=INT_MAX;
    bool dis=false;
    i=0;
    m=n;
    while(i!=firstunafterN&&i<a.size()&&a[i]%x==0){
        k=a[i]/x;

        if(k%x!=0){
            firstunafterN=a.size()+1;
            dis=true;
        }
        if(!dis){
            fo(j,x) {
               a.push_back(k);
            }
        }

        sum=sum + k*x;

        if(i<m) sum = sum+a[i];

        i++;
    }
    Fo(j,i,m){
        sum = sum+a[i];
    }

    // fo(i,n){
    //     if(a[i]%x==0){
    //         if(i<m) sum =sum+a[i];

    //         k=a[i]/x;
    //         // deb2(sum,i);
            
    //         sum = sum + k*x;

    //         fo(j,x){
    //         a.push_back(k);
    //         n++;
    //         // sum = sum+k;
    //         }
    //         // deb2(sum,i);
    //         a.erase(a.begin());
    //         i--;
    //         n--;
    //     }
    //     else break;
    // }
    // deb(m);

    // for(int x:a){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    cout<<sum<<endl;
}