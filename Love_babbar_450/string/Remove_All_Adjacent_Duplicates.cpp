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
string removeDuplicates(string s, int k)
{
    vector<char> ans;
    int i=0;
    int len = s.size();
    char prev = '#';
    int lagatar = 0, last;
    while(i<len){
        if(s[i]==prev){
            lagatar++;
        }
        else {
            lagatar=1;
            prev = s[i];
        }
        ans.push_back(s[i]);
        // for (char c : ans)
        // {
        //     cout << c << " ";
        // }
        // cout << endl;
        if(lagatar==k){

            for(int j=1;j<=k;j++){
                ans.pop_back();
            }
            last = ans.size()-1;
            // i=last+;
            if(last==-1){
                // cout << "continued" << endl;
                prev = '#';
                i++;
                continue;
            }
            lagatar = 1;
            prev = ans[last];
            last--;
            while(last>=0){
                if(ans[last]==prev) lagatar++;
                else break;
                last--;
            }
            // deb2(prev, lagatar);
        }
        i++;
    }

    string fin = "";
    for(char c:ans) fin =  fin +c;
    // deb(fin);
    return fin;

}

void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    removeDuplicates(s, k);
}