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
int nextNearestVertexFromAnyMstNode(vector<bool> &isMST, vector<int> &nodeDistWithNearestAdjThatIsInMST)
{
    int value = INT_MAX, index = -1;

    for(int i=0;i<isMST.size();i++){
        if(nodeDistWithNearestAdjThatIsInMST[i]<value&&!isMST[i]){
            index = i;
            value = nodeDistWithNearestAdjThatIsInMST[i];
        }
    }
    return index;
}
void primsAlgo(vector<pii> adj[], int v)
{
    vector<int> nodeDistWithNearestAdjThatIsInMST(v, INT_MAX);
    nodeDistWithNearestAdjThatIsInMST[0] = 0;

    vector<bool> isInMST(v, false);

    vi parent(v, -1);
    parent[0] = -1;

    int next;
    for(int i=0;i<v;i++){
        next = nextNearestVertexFromAnyMstNode(isInMST, nodeDistWithNearestAdjThatIsInMST);

        isInMST[next] = true;

        for(auto x : adj[next]){
            if (!isInMST[x.first] && x.second < nodeDistWithNearestAdjThatIsInMST[x.first])
            {
                nodeDistWithNearestAdjThatIsInMST[x.first] = x.second;

                parent[x.first] = next;
            }
        }
    }

    //printing the MST in form of edges
    for(int i=1;i<v;i++){
        cout<<parent[i]<<" -------> "<<i;
        for(auto x : adj[parent[i]]){
            if(x.first==i){
                cout << " ( " << x.second << " )" << endl;
                break;
            }
        }
    }





}
void solveGraphProblem()
{
    int V, E;
    cin >> V >> E;

    vector<pii> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v>>w;
        adj[u].push_back({v,w});     
        adj[v].push_back({u,w});     
    }
    primsAlgo(adj, V);
}

void solve()
{
    //if it is graph problrm call
    solveGraphProblem();
}