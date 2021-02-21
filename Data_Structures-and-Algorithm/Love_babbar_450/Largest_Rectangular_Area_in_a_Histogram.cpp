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
long long getMaxArea(long long nums[], int n){
    
    long long ans = INT_MIN;
    vector<long long> rse(n, n);
    vector<long long> lse(n, -1);

    stack<long long> st;
    long long i = 0;
    while (i < n)
    {
        if (st.empty() || nums[i] >= nums[st.top()])
            st.push(i++);
        else
            rse[st.top()] = i, st.pop();
    }
    // for (long long x : rse)
    //     cout << x << " ";
    // cout << endl;

    while (!st.empty())
        st.pop();

    i = n;
    while (i >= 0)
    {
        if (st.empty() || nums[i] >= nums[st.top()])
            st.push(i--);
        else
            lse[st.top()] = i, st.pop();
    }
    // for (long long x : lse)
    //     cout << x << " ";

    for (i = 0; i < n; i++)
    {
        ans = max(ans, (rse[i]-lse[i]-1)*nums[i]);
    }

    // deb(ans);

    return ans;
    
}

int nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    vector<int> rse(n, n);
    vector<int> lse(n, -1);

    stack<int> st;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || nums[i] >= nums[st.top()])
            st.push(i++);
        else
            rse[st.top()] = i, st.pop();
    }
    // for (int x : rse)
    //     cout << x << " ";
    // cout << endl;

    while (!st.empty())
        st.pop();

    i = n;
    while (i >= 0)
    {
        if (st.empty() || nums[i] >= nums[st.top()])
            st.push(i--);
        else
            lse[st.top()] = i, st.pop();
    }
    // for (int x : lse)
    //     cout << x << " ";

    for (i = 0; i < n; i++)
    {
        ans = max(ans, (rse[i]-lse[i]-1)*nums[i]);
    }

    // deb(ans);

    return ans;
}

void solve()
{
    long long i, j, n, m;
    cin >> n;
    long long nums[n];
    fo(i, n) cin >> nums[i];
    // for(int x:nums) cout<<x<<" ";
    // nextGreaterElements(nums)
    cout<<getMaxArea(nums, n)<<endl;
}