#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topo(int N, vector<int> adj[])
    {
        queue<int> q;
        vector<int> discTime(N, -1);

        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
                discTime[it] =1;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                    discTime[it] = discTime[node] +1;
                }
            }
        }
        return topo;
    }
};