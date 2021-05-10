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
int *dp;
void takeArrayInput(int arr[], int n)
{
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
}
class graph
{
public:
    int v;
    //this is when edges starts from 1....
    //like if 10 edges it will start from 1-2-3-4.....10
    int edges;
    vector<int> *adjList;
    graph(int vertices)
    {
        v = vertices;
        adjList = new vector<int>[v]; //here if it starts from 0 make it v;
    }
    void addEdge(int u, int v, bool directed = 0)
    {
        adjList[u].push_back(v);
        if (!directed)
        {
            adjList[v].push_back(u);
        }
    }
    void createGraph(int e, int directed =0)
    {
        edges = e;
        cout << "enter edegs" << endl;
        while (e > 0)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v, directed);
            e--;
        }
    }
    void showEdges()
    {
        //here if it starts from 0 make it i=0;i<v;
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> ";
            for (auto x : adjList[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    void dfs(int u, vector<bool> &visited)
    {
        cout << u << " ";
        visited[u] = 1;
        for (auto x : adjList[u])
        {
            if (!visited[x])
                dfs(x, visited);
        }
    }
    void dfsUtil()
    {
        vector<bool> visited(v, 0);
        for (int i = 0; i < v; i++)
            if (!visited[i])
                dfs(i, visited);
    }
    void bfs(int u)
    {
        queue<int> q;
        vector<bool> visited(v + 1, 0);
        q.push(u);
        visited[u] = true;
        int curr;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int x : adjList[curr])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    void dfsIt(int u)
    {
        vector<bool> visited(v + 1, 0);
        stack<pair<int, int>> st;
        st.push({u, 1});
        int curr, child;
        while (!st.empty())
        {
            curr = st.top().first;
            child = st.top().second;
            st.pop();

            if (child > adjList[curr].size())
                continue;

            if (child == 1)
            {
                visited[curr] = true;
                cout << curr << " ";
            }
            st.push({curr, child + 1});

            if (!visited[adjList[curr][child - 1]])
            {
                st.push({adjList[curr][child - 1], 1});
            }
        }
    }
    bool cycDetectionDfs(int u, vector<bool> &visited, int par)
    {
        // cout << u << " ";
        bool ans;
        // cout << u << " ";
        visited[u] = 1;
        for (auto x : adjList[u])
        {
            if (visited[x])
            {
                if (x == par)
                    continue;
                else
                    return true;
            }

            ans = cycDetectionDfs(x, visited, u);
            if (ans)
                return true;
        }
        return false;
    }

    bool cycDetectionDfsUtil()
    {
        vector<bool> visited(v, 0);
        for (int i = 0; i < v; i++)
            if (!visited[i])
                if (cycDetectionDfs(i, visited, -1))
                    return true;

        return false;
    }
    bool cycDetectionBfs(int u, vector<bool> &visited, vector<int> adjList[])
    {
        queue<pair<int, int>> q;
        // vector<bool> visited(v, 0);
        q.push({u, -1});
        visited[u] = true;
        int curr, par;
        while (!q.empty())
        {
            curr = q.front().first;
            par = q.front().second;
            q.pop();
            // cout << curr << " ";
            for (int x : adjList[curr])
            {
                if (!visited[x])
                {
                    q.push({x, curr});
                    visited[x] = true;
                }
                else
                {
                    if (x != par)
                        return true;
                }
            }
        }
        return false;
    }
};
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

void solve()
{
    int v, e;
    cin >> v >> e;
    graph g(v);
    g.createGraph(e,0);
    g.showEdges();
    // g.dfsUtil();
    // cout << endl;
    // vector<vector<int>>v;
    // g.bfs(1);
    // g.dfsIt(1);
    // cout << g.cycDetectionDfsUtil();
}