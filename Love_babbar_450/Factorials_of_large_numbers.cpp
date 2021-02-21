#include <iostream>
#include <vector>
#define fo(i, n) for (i = 0; i < n; i++)
using namespace std;
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
void multiply(vector<int> &ans, int n)
{
    int hasil = 0, curr;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        curr = ans[i] * n;
        ans[i] = (curr + hasil) % 10;
        // deb(curr);
        hasil = (curr + hasil) / 10;
    }
    while (hasil > 0)
    {
        ans.insert(ans.begin(), hasil % 10);
        hasil = hasil / 10;
    }
}

void solve()
{
    int i, j, n, m;
    cin >> n;
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        multiply(ans, i);
    }
    for (int x : ans)
        cout << x;
    cout << endl;
}