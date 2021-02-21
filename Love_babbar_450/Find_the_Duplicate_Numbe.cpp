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
// int findDuplicate(vector<int> &nums)
// {
//     vector<int> track(nums.size(), -1);
//     int ans;
//     for (int i = 0; i < nums.size();i++){
//         if(track[nums[i]]==-1){
//             track[nums[i]]++;
//         }
//         else{
//             ans =  nums[i];
//             break;
//         }
//     }
//     return ans;
// }

//good solution here is

int findDuplicate(vector<int> &nums)
{
    int hare = nums[0];
    int tortoise = nums[0];


    do{
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
    }
    while(hare!=tortoise);
    hare = nums[0];

    while(hare!=tortoise){
        hare = nums[hare];
        tortoise = nums[tortoise];
    }

    return hare;
}


void solve()
{
    int i, j, n, m;
    cin>>n;
    vi nums;
    fo(i, n){
        cin>>m;
        nums.push_back(m);
    }
    cout<<findDuplicate(nums)<<endl;
}