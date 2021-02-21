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
    int arr[n];
    takeArrayInput(arr, n);
    i=-1;j=0;
    while(j<n){
        if(arr[j]<0){
            i++;
            swap(arr[i], arr[j]);
            if(i==j)j++;
        }
        else j++;
    }
    //second approach two pointer approach
    // int l=0, h= n-1;
    // while(l<h){
    //     if(arr[l]<0){
    //         l++;
    //     }
    //     else{
    //         if(arr[h]<0){
    //             swap(arr[l], arr[h]);
    //             l++,h--;
    //         }
    //         else h--;
    //     }
    // }
    fo(i,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}