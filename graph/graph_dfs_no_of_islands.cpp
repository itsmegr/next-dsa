#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (grid[i][j] == '0' || visited[i][j])
            return;

        visited[i][j] = true;

        helper(i + 1, j, grid, visited, m, n);
        helper(i - 1, j, grid, visited, m, n);
        helper(i, j + 1, grid, visited, m, n);
        helper(i, j - 1, grid, visited, m, n);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    ans++;
                    helper(i, j, grid, visited, m, n);
                }
            }
        }
        return ans;
    }
};

//slightly modified
class Solution2
{
public:
    void helper(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, bool &flag)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (grid[i][j] == 1 || visited[i][j])
            return;
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
        {
            flag = false;
        }

        visited[i][j] = true;

        helper(i + 1, j, grid, visited, m, n, flag);
        helper(i - 1, j, grid, visited, m, n, flag);
        helper(i, j + 1, grid, visited, m, n, flag);
        helper(i, j - 1, grid, visited, m, n, flag);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        bool flag;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    flag = true;
                    helper(i, j, grid, visited, m, n, flag);
                    if (flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};