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

void boundryTraversal(vector<vector<int>> matrix, int r, int c, int sr, int sc)
{
    int i, j;
    for (i = sc; i < c; i++)
        cout << matrix[sr][i] << " ";
    for (i = sr + 1; i < r; i++)
        cout << matrix[i][c - 1] << " ";
    for (i = c - 2; i >= sc&&r-sr-1>0; i--)
        cout << matrix[r - 1][i] << " ";
    for (i = r - 2; i >= sr + 1&&c-sc-1>0; i--)
        cout << matrix[i][sc] << " ";
    // cout<<endl;
}
vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> result;
    int i = 0, j = 0;
    while (r - i > 0 && c - j > 0)
    {
        // deb2(r, i);
        // deb2(c, j);
        boundryTraversal(matrix, r, c, i, j);
         i++, j++, r--, c--;
    }
    return result;
}
void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r);

    for (int i = 0; i < r; i++)
    {

        matrix[i].assign(c, 0);
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // boundryTraversal(matrix, r-1, c-1,1,1);
    spirallyTraverse(matrix, r, c);
}