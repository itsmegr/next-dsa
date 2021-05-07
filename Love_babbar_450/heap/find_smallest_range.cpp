#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define N 1000
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
int *dp;
void takeArrayInput(vector<int> &arr, int n)
{
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
}

class MaxHeap
{
public:
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
};

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
pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    pair<int, int> ans, curr;
    ans = {INT_MAX, INT_MIN};
    int firstData;
    MaxHeap h;
    for (int i = 0; i < k; i++)
    {
        h.insert({arr[i][0], {i, 0}});
        if (arr[i][0] > ans.second)
            ans.second = arr[i][0];
    }
    ans.first = h.ar[0].first;
    curr = {ans.first, ans.second};
    while (h.size > 0)
    {


        firstData = h.ar[0].first;
        curr.first = firstData;
        if (curr.second - curr.first < ans.second - ans.first){
            ans.first = curr.first;
            ans.second = curr.second;
        }

        // for (auto x : h.ar)
        // {
        //     cout << x.first << " ";
        // }
        // cout << endl;
        // deb2(curr.first, curr.second);
        // deb2(ans.first, ans.second);
        if (h.ar[0].second.second < n - 1)
        {

            if (arr[h.ar[0].second.first][h.ar[0].second.second + 1] > curr.second)
            {
                curr.second = arr[h.ar[0].second.first][h.ar[0].second.second + 1];
            }
            h.ar[0].first = arr[h.ar[0].second.first][h.ar[0].second.second + 1];
            h.ar[0].second.second++;
            h.percolateDown(0);
        }
        else
        {
            break;
        }
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    pair<int, int> rangee;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    rangee = findSmallestRange(arr, n, k);
    cout << rangee.first << " " << rangee.second << "\n";
}