#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	string s;
	cin >> s;
	stack<int> st;
	st.push(-1);
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		st.push(i);
		else
		{
			st.pop();
			if (st.empty())
			st.push(i);
			else
			ans = max(ans, i - st.top());
		}
	}

	cout << ans << endl;
	return 0;
}