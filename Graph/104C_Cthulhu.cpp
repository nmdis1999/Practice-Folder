#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int cycle;
struct dsu
{
    vector<int> par;
    void init(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int get(int x)
    {
        return (x == par[x]) ? x : par[x] = get(par[x]);
    }

    bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x == y)
            cycle++;
        else
        par[y] = x;
        return true;
    }
}G;
int32_t main()
{
    int n, m;
    cin >> n >> m;
    G.init(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G.unite(x, y);
    }

    set<int> comp;
    for (int i = 0; i < n; i++)
        comp.insert(G.get(i));
    
    //only one cycle and only one super parent
    if (cycle == 1 && comp.size() == 1)
        cout <<"FHTAGN!";
    else
        cout <<"NO\n";
    return 0;
}