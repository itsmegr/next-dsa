#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
void solveGraphProblem();
int *dp;
vector<int> takeArrayInput(int n);
void dfs();
void bfs();

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
    while (t--)
    {
        solve();
    }
    return 0;
}
vector<int> takeArrayInput(int n)
{
    vi arr(n, 0);
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
    return arr;
}
void dfsUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    cout << u << " ";
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
            dfsUtil(x,adj,visited);
    }
}
void dfs(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsUtil(i, adj, visited);
}
void bfs(int u, int V, vector<int> adj[])
{
    queue<int> q;
    vector<bool> visited(V, 0);
    q.push(u);
    visited[u] = true;
    int curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void solveGraphProblem()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}
bool com(int a, int b){
    return a>b;
}

// void solve()
// {
//     int n;
//     cin>>n;
//     vi a(n, 0);
//     int i;
//     int ans = 0;
//     int neg=0, pos=0, zer=0;
//     fo(i, n){
//         cin>>a[i];
//         if(a[i]<0) neg++;
//         else if(a[i]>0) pos++;
//         else zer++;
//     }
//     ans = neg+zer;
//     if(zer>1){
//         //no pos
//     }
//     else if(zer==1) {
//         if(pos>0) ans+=1;
//     }
//     else if(zer==0){
//         if (pos > 0)
//             ans += 1;
//     }
//     cout<<ans<<endl;


// }

void solve(){
    ll n;
    cin >> n;
    vl a(n);
    int i;
    fo(i, n){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    // ll mx = mod;
    ll ans = 1, ans1 = 1;
    set<ll> st;
    for (int i = 1; i < n; i++)
    {
        st.insert(abs(a[i] - a[i - 1]));
        if (*st.begin() >= a[i])
        {
            ans1++;
        }
        else
        {
            ans1 -= 1;
            st.erase(st.begin());
        }
        ans = max(ans1, ans);
    }
    cout<<ans<<endl;
}