#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int32_t main()
{
	int n;
	cin >> n;
	int a[n+1];
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int s, e;
	cin >> s >> e;
	if (s > e)
	    swap(s, e);
	int clck = 0;
	
	for (int i = s - 1;i < e -1;i++) 
	    clck += a[i];
	cout << min(clck, sum - clck) << endl;
}