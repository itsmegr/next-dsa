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


void solve()
{
    int n,k,x,y,i,j;
    bool xdir = true, ydir = true;//true = +, false = -; true = heading to n
    //fasle heading to 0;
    cin>>n>>k>>x>>y;
    i=k;
    k=4;
    vpii four_repeat;
    while(k>0){
        if(xdir&&ydir){
            if(x>y){
                y =  y + n -x, x= n;
                xdir=false;
            }
            else{
                x = x+ n -y,y=n;
                ydir=false;
            }
        }
        else if(!xdir&&ydir){
            if(x-0>n-y){
                x= x-(n-y),y=n;
                ydir=false;
            }
            else{
                y = y+x-0,x=0;
                xdir=true;
            }
        }
        else if(xdir&&!ydir){
            if(y-0>n-x){
                y = y - (n-x),x=n;
                xdir = false;
            }
            else{
                x= x+y-0,y=0;
                ydir = true;
            }
        }
        else{
            if(x<y){
                y = y - x;
                x=0;
                xdir = true;
            }
            else{
                x = x-y,y=0;
                ydir = true;
            }
        }
        four_repeat.push_back(make_pair(x,y));
        if((x==0||x==n)&&(y==0||y==n)) break;

        k--;
    }
    if(k>0){
        cout<<x<<" "<<y<<endl;
    }
    else{
        if(i%4==0){
            cout<<four_repeat[3].first<<" "<<four_repeat[3].second<<endl;
        }
        else{
            cout<<four_repeat[(i%4)-1].first<<" "<<four_repeat[(i%4)-1].second<<endl;
        }
    }
}