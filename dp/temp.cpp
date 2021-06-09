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
int dp[1000001];
long long modulo  = 1000000007;
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
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
void solve() {
	int n, ans;
	cin >> n;
	vi ar;
	inp(ar, n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			int a, b;
			a = ar[i], b = 2 * ar[j];


			a = ar[j], b = 2 * ar[i];

		}
	}
}