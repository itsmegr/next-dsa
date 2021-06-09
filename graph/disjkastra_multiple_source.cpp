#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define debb(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define print(x) cout<<x<<endl;
#define printt(x, y) cout<<x<<" "<<y<<endl;
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fo(i, n) for (i = 0; i < n; i++)
#define forr(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void inp(vi &a, int n) {
	a.assign(n, 0);
	int i;
	fo(i, n) {
		cin >> a[i];
	}
}
bool com(int a, int b) {
	return a > b;
}
void solve();
void solveGraphProblem();
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
//this is for finding shortest distnace from any source node
//this can be done in o(v*e), like take each node as source and find the nearest police station and repeat
//for all the nodes
//do it for undirected unwieghted also
class Solution() {
	void DijkastraMultipleSource(vector<pii> adj[], int v, int e) {
		vi sources(n, 0);
		int i;
		for (int i = 0; i < v; i++) cin >> sources[i];

		priority_queue<pii, vector<pii>, greater<pii> > pq;
		fo(i, v) {
			if (sources[i] == 1) pq.push({0, i});
		}
		vi dist(v, INT_MAX);

		while (!q.empty()) {
			int curr = q.front().second;
			int currDis = q.front().first;
			q.pop();

			for (auto x : adj[curr]) {
				int padosi = x.first;
				int w = x.second;

				if (dist[padosi] > currDis + e) {
					dist[padosi] = currDis + e;
					pq.push({dist[padosi], padosi})
				}
			}

		}
	}
};
void solveGraphProblem()
{
	int V, E;
	cin >> V >> E;

	vector<pii> adj[V];

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
}
void solve() {

}