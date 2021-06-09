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
	// cin >> t;
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
int miniMize(int n, vi a) {
	if (n == 0) return 0;
	if (dp[n] != -1) {
		return dp[n];
	}
	int ans = 1e9;
	for (int x : a) {

		if (x <= n) {
			int temp = miniMize(n - x, a);
			if (temp == 1e9) continue;
			ans = min(ans, temp + 1);
		}
	}
	// deb(ans);
	return dp[n] = ans;
}
void solve() {
	int n, i, sum;
	cin >> n >> sum;
	vi a;
	inp(a, n);
	fo(i, sum + 1) dp[i] = 1e9;
	dp[0] = 0;
	//think like topological sort
	for (int i = 1; i <= sum; i++) {
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0) {
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
			}
		}
	}
	// cout << INT_MAX << endl;
	int ans = dp[sum] == 1e9 ? -1 : dp[sum];
	cout << ans << endl;
}