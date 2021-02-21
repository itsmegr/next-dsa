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
    int i, j, n, m;
    cin>>n;
    int* a = new int[n];
    takeArrayInput(a, n);
    cin>>m;
    int* b = new int[m];
    takeArrayInput(b,m);
    if(a[0]>b[0]){
        swap(a,b);
        swap(m,n);
    }
    //this programme will also run for array containing duplicate elemenst
    int count = 1, intersec = 0;
    i=0;j=0;
    while(i<n-1&&j<m){
        
        if(a[i]!=a[i+1]){
            count++;
            if(b[j]>a[i]&&b[j]<a[i+1]){
                count++;
                j++;
            }
            else if(b[j]==a[i]||b[j]==a[i+1]){
                j++;
                if(b[j]!=b[j-1]) intersec++;
            }
        }
        else{
            if(b[j]==a[i]){
            j++;
            if(b[j]!=b[j-1]) intersec++;
            }
        }
        deb2(i,j);
        deb(count);
        deb(intersec);
        i++;
    }
    if(i==n-1){
        while(j<m-1){
            if(b[j]!=b[j+1]&&b[j]!=a[i]){
                count++;
            }
            j++;
        }
        count++;
    }
    if(j==m){
        i++;
        while(i<n-1){
            if(a[i]!=a[i+1]&&a[i]!=b[m-1]){
                count++;
            }
            i++;
        }
        count++;
    }
    deb(count);
    deb(intersec);

}