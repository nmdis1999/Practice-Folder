#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
 
const int N = 100005;
 
void solve() {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
	int a[n], b[n], c[n];
	vector<int> temp;
	for (i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (i = 0; i < n; i++) {
		c[(i + 1) % n] = max(0ll, a[(i + 1) % n] - b[i]);
	}
	for (i = 0; i < n; i++) {
		// cout << c[i] << " ";
		sum += c[i];
	}
	ans = 1e18;
	for (i = 0; i < n; i++) {
		ans = min(ans, sum - c[i] + a[i]);
	}
	cout << ans << '\n';
	return ;
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
		solve();
	return 0;
}