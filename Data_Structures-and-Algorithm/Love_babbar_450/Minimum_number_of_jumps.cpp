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
int *dp;
void solve();
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

int minJumpsRe(int arr[], int n, int start)
{
    
    if (start >= n - 1)
    {
        return 0;
    }

    // deb(start);

    if (dp[start] != -1)
    {
        return dp[start] + 1;
    }

    int minJ=INT_MAX;
    for (int i = 1; i <= arr[start]; i++)
    {
        minJ = min(minJumpsRe(arr, n, start + i), minJ);
    }

    // cout<<"inserted in dp at "<<start<<" "<<minJ<<endl;
    dp[start] = minJ;

    return minJ + 1;
}

// int minJumps(int arr[], int n)
// {
//     int max_reachable_index_from_here = arr[0];
//     int jump_taken_till_now = 1;
//     int steps_i_can_take_without_jump = arr[0];

//     if (n == 1)
//         return 0;
//     if (arr[0] == 0)
//         return -1;

//     for (int i = 1; i < n; i++)
//     {
//         if (i == n - 1)
//             return jump_taken_till_now;

//         steps_i_can_take_without_jump--;

//         max_reachable_index_from_here = max(max_reachable_index_from_here, i + arr[i]);

//         if (steps_i_can_take_without_jump == 0)
//         {
//             jump_taken_till_now++;
//             if (i >= max_reachable_index_from_here)
//                 return -1;
//             steps_i_can_take_without_jump = max_reachable_index_from_here - i;
//         }
//     }
// }

void solve()
{
    int i, j, n, m;
    cin >> n;
    int arr[n];
    dp = new int[n];
    fo(i, n)
    {
        dp[i] = -1;
    }
    // deb(n);
    takeArrayInput(arr, n);
    // fo(i, n)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << minJumps(arr, n) << endl;
    cout << minJumpsRe(arr, n, 0) << endl;
}