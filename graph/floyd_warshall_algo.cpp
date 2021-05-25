#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code here
        int v = matrix.size();
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
                if (matrix[i][j] == -1)
                    matrix[i][j] = INT_MAX;
        }

        for (int k = 0; k < v; k++)
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j] && (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX))
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
                if (matrix[i][j] == INT_MAX)
                    matrix[i][j] = -1;
        }
    }
};