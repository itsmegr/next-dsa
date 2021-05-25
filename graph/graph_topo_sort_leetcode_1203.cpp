#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsTopo(int u, vector<int> &clr, stack<int> &st, int grp, vector<int> &group, vector<vector<int>> adjList)
    {
        clr[u] = 1;

        for (int x : adjList[u])
        {
            if (clr[x] == 2)
                continue;

            if (clr[x] == 0&&group[x]==grp)
            {
                if (dfsTopo(x, clr,st,grp, group, adjList));
                    return true;
            }
            else if (clr[x] == 1)
                return true;
        }
        clr[u] = 2;
        st.push(u);
        return false;

        
    }
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        //creating adjList
        vector<vector<int>> al(n);
        vector<int> ans;

        for(int i=0;i<n;i++){
            for(auto x : beforeItems[i]){
                al[x].push_back(i);
            }
        }

        vector<int> clr(n, 0);
        stack<int> st;

        for(int j=-1;j<m;j++){
            for (int i = 0; i < n; i++)
            {
                if (clr[i]==0&&group[i]==j)
                {
                    if(dfsTopo(i, clr, st,j, group, al)) return vector<int>();
                    while(!st.empty()){
                        ans.push_back(st.top());
                        st.pop();
                    }

                }
            }
        }
        return ans;
    }
};