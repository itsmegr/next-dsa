#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> en;

    int go(int lo, int hi) {
        if(lo+1 == hi) return 1;
        int mid = en[lo];
        if(mid == hi) return 2*go(lo+1, hi-1);
        return go(lo, mid) + go(mid+1, hi);
    }
    int scoreOfParentheses(string S)
    {
        stack<int> st;
        int n = S.length();
        en.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (S[i] == ')')
            {
                en[st.top()] = i;
                st.pop();
            }
            else
                st.push(i);
        }

        return go(0, n-1);

    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    Solution obj;
    cout << obj.scoreOfParentheses(s) << endl;
}