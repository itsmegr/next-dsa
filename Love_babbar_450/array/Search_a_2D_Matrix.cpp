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
void takeArrayInput(int arr[], int n)
{
    int i;
    fo(i, n)
    {
        cin >> arr[i];
    }
}

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

bool binarySearchInMatrix(vector<vector<int>> &matrix, int l, int h, int c, int target)
{
    if (l > h)
        return false;
    // deb2(l, h);
    int mid = (l + h) / 2;

    if (matrix[mid / c][mid % c] == target)
        return true;

    if (matrix[mid / c][mid % c] > target)
    return binarySearchInMatrix(matrix, l, mid-1, c, target);

    else return binarySearchInMatrix(matrix, mid+1, h, c, target);
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c= matrix[0].size();
    // deb2(r,c);
    return binarySearchInMatrix(matrix, 0, (r*c)-1, c, target);
}

void solve()
{
    int target;
    int r, c;
    cin >> r >> c >> target;
    vector<vector<int>> matrix(r);

    for (int i = 0; i < r; i++)
    {

        matrix[i].assign(c, 0);
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout<<searchMatrix(matrix, target)<<endl;
}