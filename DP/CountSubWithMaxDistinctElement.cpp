//Given an arr of size n. 
//The problem is to count all the subsequences having maximum number of distinct elements.
#include <bits/stdc++.h>
#define MAX_CHAR 256
#define int long long
#define MOD 1000000007
using namespace std;

int countSub(string str)
{
	unordered_map<char, int> um;
    for (char c : str)
        um[c]++;
    int ans = 1;
    for (auto it :um)
    ans *= it;
    return ans;
}


int32_t main() {
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
		cout << ans<< endl;
	}
	return 0;
}4
128
