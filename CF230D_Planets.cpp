#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e5+5;
 
int n, m;
int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];
set<int> times[N];
 
int dijkstra(int source, int destination)
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=1e18;
		departure[i]=1e18;
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
		while(times[x.second].find(departure[x.second])!=times[x.second].end())
		{
			departure[x.second]++; //because we will depart only when we 
			//find first departing point which is not in the set
		}
		
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
		return -1;
	}
	return arrival[destination];
}
 
int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int t;
			cin>>t;
			times[i].insert(t);
		}
	}
	int ans = dijkstra(1, n);
	cout<<ans;
	return 0;
} 