#include <bits/stdc++.h>
using namespace std;

class solution {
	int dp[10001][101];

	//here i am starting from source, instead of destination
	int dfs(vector<vector<pair<int, int>>>& graph, int src, int dst, int k) {
		if (src == dst) return 0;
		if (k <= -1) return INT_MAX;

		if (dp[src][k] != -1) return dp[src][k];

		int ans = INT_MAX;
		for (auto child : graph[src]) {
			int res = dfs(graph, child.first, dst, k - 1);
			if (res != INT_MAX)
				ans = min(ans, child.second + res);
		}

		return dp[src][k] = ans;
	}
};