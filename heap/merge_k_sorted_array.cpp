// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to merge k sorted arrays.
    vector<pair<int, pair<int, int>>> ar;
    int size = 0;
    void insert(pair<int, pair<int, int>> key)
    {
        size++;
        ar.push_back(key);
        percolateUp(size - 1);
    }
    pair<int, pair<int, int>> removeE()
    {
        if (size == 0)
            return {-1, {-1, -1}};
        pair<int, pair<int, int>> ans = ar[0];
        swap(ar[0], ar[size - 1]);
        ar.pop_back();
        size--;
        percolateDown(0);
        return ans;
    }
    void percolateUp(int start)
    {
        int parent = (start - 1) / 2;
        if (parent >= 0 && ar[start].first < ar[parent].first)
        {
            swap(ar[start], ar[parent]);
            percolateUp(parent);
        }
    }
    void percolateDown(int start)
    {
        int l = 2 * start + 1;
        int r = 2 * start + 2;
        int largest = start;
        if (l < size && ar[l].first < ar[largest].first)
        {
            largest = l;
        }
        if (r < size && ar[r].first < ar[largest].first)
        {
            largest = r;
        }
        if (largest != start)
        {
            swap(ar[start], ar[largest]);
            percolateDown(largest);
        }
    }

    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            insert({arr[i][0], {i, 0}});
        }

        // pair<int, pair<int, int>> x = removeE();
        while (size > 0)
        {
            // for (auto x : ar)
            // {
            //     cout << x.first << " " << x.second.first << " " << x.second.second << endl;
            // }
            // cout<<endl;
            ans.push_back(ar[0].first);
            if (ar[0].second.second < k - 1)
            {
                ar[0].first = arr[ar[0].second.first][ar[0].second.second + 1];
                ar[0].second.second++;
                percolateDown(0);
            }
            else
            {
                removeE();
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends