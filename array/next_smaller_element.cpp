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
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    vector<int> rge(n, -1);
    vector<int> lge(n, -1);

    stack<int> st;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || nums[i] <= nums[st.top()])
            st.push(i++);
        else
            rge[st.top()] = nums[i], st.pop();
    }
    // for (int x : rge)
    //     cout << x << " ";
    //     cout<<endl;

    while(!st.empty()) st.pop();

     i = n;
    while (i >=0)
    {
        if (st.empty() || nums[i] <= nums[st.top()])
            st.push(i--);
        else
            lge[st.top()] = nums[i], st.pop();
    }
    // for (int x : lge)
    //     cout << x << " ";
    
    for(i=0;i<n;i++){
        if(rge[i]!=-1)  ans[i] = rge[i];
        else ans[i] = lge[i];
    }
    for(int x:ans) cout << x << " ";

    return ans;
}

void solve()
{
    int i, j, n, m;
    cin >> n;
    vi nums(n, -1);
    fo(i, n) cin >> nums[i];
    // for(int x:nums) cout<<x<<" ";
    nextGreaterElements(nums);
}