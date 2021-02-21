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

void sort012(int a[], int n)
{
    int i=-1, k=n,j=0;
    // coode here 
    while(j<k){
        if(a[j]==0){
            i++;
            if(i==j) j++;
            else swap(a[i], a[j]);
        }
        else if(a[j]==2){
            k--;
            swap(a[j], a[k]);
        }
        else j++;
    }
}
void solve()
{
    int i, j, n, m;
    cin>>n;

    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    sort012(arr,n);
    fo(i,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}