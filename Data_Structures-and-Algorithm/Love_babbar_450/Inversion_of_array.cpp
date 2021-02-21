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
void takeArrayInput(long long int arr[], int n)
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

void merge(long long int Arr[], long long int start, long long int mid, long long int end, long long int &total_inversion)
{

	long long int temp[end - start + 1];

	long long int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end)
	{
		if (Arr[i] <= Arr[j])
		{
			temp[k] = Arr[i];
			k += 1;
			i += 1;
		}
		else
		{

			// deb2(i, mid);
			total_inversion = total_inversion + mid - i + 1;
			// deb(total_inversion);
			temp[k] = Arr[j];
			k += 1;
			j += 1;
		}
	}

	while (i <= mid)
	{
		temp[k] = Arr[i];
		k += 1;
		i += 1;
	}

	while (j <= end)
	{
		temp[k] = Arr[j];
		k += 1;
		j += 1;
	}

	for (i = start; i <= end; i += 1)
	{
		Arr[i] = temp[i - start];
	}
}

void mergeSort(long long int Arr[], long long int start, long long int end, long long int &total_inversion)
{

	if (start < end)
	{
		long long int mid = (start + end) / 2;
		mergeSort(Arr, start, mid, total_inversion);
		mergeSort(Arr, mid + 1, end, total_inversion);
		merge(Arr, start, mid, end, total_inversion);
	}
}

void solve()
{
	long long int i, j, n, m, total_inversion = 0;
	cin >> n;
	long long int arr[n];
	takeArrayInput(arr, n);
	mergeSort(arr, 0, n - 1, total_inversion);
	cout << total_inversion << endl;
}
