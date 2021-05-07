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
    vector<int> ar;
    int size = 0;
    void insert(int key)
    {
        size++;
        ar.push_back(key);
        percolateUp(size - 1);
    }
    int remove()
    {
        if (size == 0)
            return -1;
        int ans = ar[0];
        swap(ar[0], ar[size - 1]);
        ar.pop_back();
        size--;
        percolateDown(0);
        return ans;
    }
    void percolateUp(int start)
    {
        int parent = (start - 1) / 2;
        if (parent >= 0 && ar[start] > ar[parent])
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
        if (l < size && ar[l] > ar[largest])
        {
            largest = l;
        }
        if (r < size && ar[r] > ar[largest])
        {
            largest = r;
        }
        if (largest != start)
        {
            swap(ar[start], ar[largest]);
            percolateDown(largest);
        }
    }
    void buildHeap()
    {
        //startIn is the index of last non-leaf node in tree
        //so last non-leaf node = parent of node at (n-1)th index
        // last non-leaf node = (n-1-1)/2;
        // = (n/2)-1;
        int startIn = (size / 2) - 1;
        for (int i = startIn; i >= 0; i--)
        {
            percolateDown(i);
        }
    }
    void sortArray()
    {
        int n = size;
        for (int i = 0; i < n; i++)
        {
            remove();
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

void solve()
{
    MaxHeap h;
    // cin >> h.size;
    h.insert((int)'a');
    h.insert('b');
    // int n;
    // cin >> n;
    // h.ar = vector<int>(h.size, 0);
    // takeArrayInput(h.ar, h.size);


    // vi heap2(n, 0);
    // takeArrayInput(heap2, n);
    // for (int i = 0; i < n; i++)
    // {
    //     h.insert(heap2[i]);
    // }
    for (int x : h.ar)
    {
        cout << (char)x << " ";
    }
    // cout<<endl;

}