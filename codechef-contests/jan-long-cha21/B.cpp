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

// void decode(string s, int l, int h, string &ans, int i){
//     if(l==h)
//     {
//         ans = ans+char(96+l);
//         decode(s,1,16,ans,i);
//         return;
//     }

//     if(i>=s.length())
//     return;


//    int mid = (l+h)/2;
// //    deb(mid);
//    if(s[i]=='0'){
//        decode(s,l,mid,ans, i+1);
//    }
//    else if(s[i]=='1'){
//        decode(s,mid+1,h,ans,i+1);
//    }
// }

void solve()
{
    int i, j, n, m;
    cin>>n;
    string s, ans;
    cin>>s;
    i=0;
    int l=1,h=16, mid;
    while(i<s.length()){
        mid = (l+h)/2;
        if(s[i]=='0'){
           
            l= l;
            h = mid;
            
            i++;
        }
        else if(s[i]=='1'){
           
            l= mid+1;
            h = h;
            
            i++;
        }
        if(l==h)
        {
            
            cout<<char(96+l);
            l=1,h=16;
            
            continue;
        }

    }
    cout<<endl;
    
}
