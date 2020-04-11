#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            if (v[i].first < v[i-1].first)
                return false;
            if (v[i].second < v[i-1].second)
                return false;
            if (v[i].first - v[i-1].first < v[i].second - v[i-1].second)
                return false;
        }
        if (v[i].first < v[i].second)
            return false;
    }
    return true;
}
int main()
{
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
       if (solve())
        cout <<"YES\n";
       else
        cout <<"NO\n";
    }

    return 0;
}