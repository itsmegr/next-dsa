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


void solve()
{
    ll i, j, n, m,sum=0, fir, sec;
    vector< pair<ll, pii> > edgeWithVertex;
    // edgeWithVertex.push_back(make_pair(23, make_pair(1,2)));
    //  edgeWithVertex.push_back(make_pair(3, make_pair(3,2)));
    //   edgeWithVertex.push_back(make_pair(13, make_pair(4,2)));
    //    edgeWithVertex.push_back(make_pair(20, make_pair(1,3)));

    // sort(edgeWithVertex.begin(), edgeWithVertex.end());
    // fo(i,4){
    //     cout<<edgeWithVertex[i].first<<" "<<edgeWithVertex[i].second.first<<" "<<edgeWithVertex[i].second.second<<endl;
    // }

    cin>>n;
    ll weight[n+1], degree[n+1];
    fo(i,n+1){
        degree[i]=0;
    }
    Fo(i,1,n+1){
        cin>>m;
        sum = sum+m;
        weight[i]=m;
    }
    m=n-1;
    while(m>0){
        cin>>i>>j;
        degree[i]++;
        degree[j]++;
        m--;
    }

    vector<ll> to_add;

    Fo(i,1,n+1)
    {
        Fo(j,1,degree[i])
        {
            to_add.push_back(weight[i]);
        }
    }

    sort(to_add.begin(), to_add.end());
    reverse(to_add.begin(), to_add.end());
    cout<<sum<<" ";
    for(auto itr = to_add.begin();itr<to_add.end();itr++)
    {
        sum = sum + *itr;
        cout<<sum<<" ";
    }
    cout<<endl;


}