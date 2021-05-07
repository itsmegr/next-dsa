#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve();
int *dp;
void takeArrayInput(int arr[], int n){
    int i;
    fo(i,n){
        cin>>arr[i];
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
    while(t--) {
      solve();
    }
    return 0;
}

void dfs(vector<vector<char>> &board, int i, int j, int n)
{
    if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
        return;
    if (board[i][j] == 'X')
        return;

    if ((board[i][j + 1] == '0' && j + 1 == n - 1) || (board[i][j - 1] == '0' && j - 1 == 0) || (board[i + 1][j] == '0' && i + 1 == n - 1) || (board[i - 1][j] == '0' && i - 1 == 0))
    {
    }
    else
    {
        board[i][j] = 'X';
    }
    dfs(board, i + 1, j, n);
    dfs(board, i - 1, j, n);
    dfs(board, i, j + 1, n);
    dfs(board, i, j - 1, n);
}
void solve2(vector<vector<char>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0 && i != 0 && i != n - 1 && j != n - 1 && board[i][j] == '0')
            {
                // deb2(i,j);
                dfs(board, i, j, n);
                
            }
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<char>> ar(n, vector<char>(n, '0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
        }
    }
    solve2(ar);
    for(auto x : ar){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}