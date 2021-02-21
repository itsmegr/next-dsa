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

void nextPermutation(vector<int> &nums)
{
    int i;
    for(i=nums.size();i>0;i--){
        if(nums[i]>nums[i-1]){
            break;
        }
    }
    if(i==0){
        reverse(nums.begin(), nums.end());
        return ;
    }
    for(int j=nums.size();j>=i;j--){
        if(nums[j]>nums[i-1]){
            swap(nums[j], nums[i-1]);
            reverse(nums.begin() + i, nums.end());
            return ;
        }
    }

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
    nextPermutation(nums);
    for(int x:nums){
        cout<<x<<" ";
    }
    cout<<endl;
}