#include <bits/stdc++.h>
using namespace std;

//coloring method

class Solution
{
public:
    //0 white, 1 gray, 2 black
    bool dfs(int u, vector<int> &clr, vector<vector<int>> adjList)
    {
        clr[u] = 1;

        for(int x : adjList[u]){
            if(clr[x]==2) continue;

            if(clr[x]==0){
                if(dfs(x, clr, adjList)) return true;
            }
            else if(clr[x]==1) return true;
        }
        clr[u ] =2;
        return false;
    }
};