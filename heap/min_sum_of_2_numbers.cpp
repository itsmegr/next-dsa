// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        int k = 0;
        int xs = 0;
        int ys = 0;
        vector<int> x, y;
        while (n > 1)
        {
            x.push_back(arr[k]);
            k++;
            y.push_back(arr[k]);
            k++;
            n -= 2;
        }
        
        if (n == 1)
        {
            int i = 0;
            while (i < xs)
            {
                if (x[i] < y[i])
                {
                    x.push_back(arr[k]);
                    xs++;
                    break;
                }
                else if (x[i] > y[i])
                {
                    y.push_back(arr[k]);
                    ys++;
                    break;
                }
            }
        }
        stack<int> ans;

        int carry = 0;
        int sum;
        for (int i = 1; i <= max(xs, ys); i++)
        {
            sum = 0;
            if (xs - i >= 0)
                sum += x[xs - i];
            if (ys - i >= 0)
                sum += y[ys - i];
            sum += carry;
            // deb(sum);
            ans.push(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0)
            ans.push(carry);
        string s;
        while (!ans.empty())
        {
            s = s + to_string(ans.top());
            // deb(s);
            ans.pop();
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends