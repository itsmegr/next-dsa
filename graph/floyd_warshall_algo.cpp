#include <bits/stdc++.h>
using namespace std;
// We initialize the solution matrix same as the input graph matrix as a first step.
//  Then we update the solution matrix by considering all vertices as an intermediate vertex.
//  The idea is to one by one pick all vertices and updates all shortest paths which include
//  the picked vertex as an intermediate vertex in the shortest path. When we pick vertex
//  number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1}
//  as intermediate vertices. For every pair (i, j) of the source and destination vertices
//  respectively, there are two possible cases.
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