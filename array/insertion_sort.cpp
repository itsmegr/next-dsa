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

void insertionSortRe(int a[], int i, int j, int n){
    if(i<n){
        if(j>0){
            if(a[j]<a[j-1]) swap(a[j], a[j-1]);
            insertionSortRe(a, i, j-1, n);
        }
        else  insertionSortRe(a, i+1, i+1, n);
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(a[j]<a[j-1]) swap(a[j], a[j-1]);
            else break;
        }
    }
}

void solve()
{
    int i, j, n, m;
    cin>>n;
    int a[n];
    takeArrayInput(a, n);
    // insertionSort(a, n);
    insertionSortRe(a, 1, 1, n);
    fo(i, n) cout<<a[i]<<" ";
    cout<<endl;

}