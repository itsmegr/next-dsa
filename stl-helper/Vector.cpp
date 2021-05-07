#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) #x.begin(), #x.end();
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
//comparator function for assending or desending order
bool f(int x, int y)
{
    if(x<y)
    return true;
    else 
    return false;
}

void solve()
{
    int i, j, n, m;

    vector <int> B(4,-1);

    vector <int> A = {12,45,32,2,705};


    sort(A.begin(), A.end());//sort in assending

    A.push_back(700);
    A.push_back(700);
    A.push_back(700);
    A.push_back(700);


    sort(A.begin(), A.end(), f);//sort it depending on comparator


    //traversing is super easy
    for(int x:A)
    cout<<x<<" ";
    cout<<endl;


    bool present = binary_search(A.begin(), A.end(), 2); //true
    present = binary_search(A.begin(), A.end(), 5); //false



    auto it = lower_bound(A.begin(), A.end(),700);//>=700
    auto it2 = upper_bound(A.begin(), A.end(),705)-A.begin();//>700


    // cout<<*it<<" "<<*it2<<endl;
    cout<<it2<<endl;//700 is present it2-it times
 


    


        


    // for(int &x:A)
    // {
    //     x++;
    // }
    // for(int x:A)
    // cout<<x<<" ";

}