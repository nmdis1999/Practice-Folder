#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MOD 1000000007
using namespace std;

int countSub(string str)
{
	vector<int> last(MAX_CHAR, -1);
	int n = str.size();
	int dp[n+1];

	//empty string will have 1 subsequence
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 2*dp[i-1];
		if (last[str[i - 1]] != -1)
		dp[i] = dp[i] - dp[last[str[i-1]]]; //if current char occured be#include <bits/stdc++.h>
		last[str[i-1]] = i - 1;
	}

	return dp[n];
}


int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int ans = countSub(str);
		cout << ans % MOD << endl;
	}
	return 0;
}