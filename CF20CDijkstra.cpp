#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5+5;
int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];
int n, m;
void dijkstra(int source, int destination)
{
	for(int i=1;i <= n;i++)
	{
		arrival[i]=1e18;
		departure[i]=1e18;
		vis[i]=0;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	if(!vis[destination])
	{
		cout<<"-1";
		return;
	}
	int v=destination;
	vector<int> ans;
	while(parent[v])
	{
		ans.push_back(v);
		v=parent[v];
	}
	ans.push_back(source);
	reverse(ans.begin(), ans.end());
	for(auto it:ans)
		cout<<it<<" ";
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x].pb({y, z});
		g[y].pb({x, z});
	}

	dijkstra(1, n);
	return 0;
}

