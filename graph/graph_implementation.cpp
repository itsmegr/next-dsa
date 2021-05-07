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
class graph{
public:
    int v;
    int edges;
    vector<int> *adjList;
    graph(int vertices){
        v = vertices;
        adjList = new vector<int>[v]; 
    }
    void addEdge(int u, int v, bool directed = 0){
        adjList[u].push_back(v);
        if(!directed){
            adjList[v].push_back(u);
        }
    }
    void createUndirectGraph(int e){
        edges=e;
        cout<<"enter edegs"<<endl;
        while(e>0){
            int u,v;
            cin>>u>>v;
            addEdge(u,v);
            e--;
        }
    }
    void showEdges(){
        for(int i=0;i<v;i++){
            cout<<i<<" -> ";
            for(auto x:adjList[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    void dfs(int u, vector<bool> &visited){
        cout<<u<<" ";
        visited[u] = 1;
        for(auto x : adjList[u]){
            if(!visited[x])
            dfs(x, visited);
        }
    }
    void dfsUtil(){
        vector<bool> visited(v,0);
        dfs(0, visited);
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
    int v,e;
    cin>>v>>e;
    graph g(v);
    g.createUndirectGraph(e);
    g.showEdges();
    g.dfsUtil();
    vector<vector<int>>v;
    
}