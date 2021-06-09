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
bool solveGraphProblem();
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
            dfsUtil(x, adj, visited);
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

//find without compression
//finding the absParent
// int find(int i, vi parent){
//     if(parent[i]==i) return i;
//     return find(parent[i], parent);
// }
//find with compression
//means if the parent of current node is not
//equal to the absParent make its parent direct absParent
//becuase order doesnt matter we need only parent
// {
//     parent
//     rank
// }
int find(int i, vpii &data) {
    if (data[i].first == i)
        return i;
    else
    {
        return data[i].first = find(data[i].first, data);
    }
}

//union normal
// bool Union(int x, int y, vi parent){
//     int i = find(x, parent);
//     int j = find(y, parent);
//     if(i==j) return false; //union not possible already in same set

// //now j is absParent
//     parent[i] = j;

//     return true;

// }

//union by rank
bool Union(int x, int y, vpii &data)
{
    int i = find(x, data);
    int j = find(y, data);
    if (i == j)
        return false; //union not possible already in same set

    //push smaller under bigger(smaller small in rank)
    if (data[i].second < data[j].second) {
        data[i].first = j;
    }
    else if (data[i].second > data[j].second)
        data[j].first = i;
    else {
        data[i].first = j;
        data[j].second++;
    }

    return true;
}

bool solveGraphProblem()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    //put initail rank==0(every node in another set) and parent = i
    vpii data(V, { -1, 0});
    for (int i = 0; i < V; i++) {
        data[i].first = i;
    }
    bool isCycle = false;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (!isCycle) {
            if (!Union(u, v, data)) isCycle = true;
        }

    }
    return isCycle;

}

void solve()
{
    //if it is graph problrm call
    cout << "isCycle = " << solveGraphProblem();
}