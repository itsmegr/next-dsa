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
    void createUndirectGraph(int e)
    {
        edges = e;
        cout << "enter edegs" << endl;
        while (e > 0)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
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
    //coloring method
    bool isBipartile(int u, vector<int> &clr, int curClr, int preClr){
        clr[u]  = curClr;
        bool ans  = true;
        for(auto x : adjList[u]){
            if(clr[x]==-1){
                if(!isBipartile(x, clr, preClr, curClr)) return false;
            }
            else{
                if(clr[x]!=preClr) return false;
            }
        }
        return true;
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
    while(t--) {
      solve();
    }
    return 0;
}


void solve()
{
    int i, j, n, m;
}