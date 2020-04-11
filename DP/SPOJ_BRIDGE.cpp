#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct city
{
    int n, s; //for north and south
};

bool compare(struct city a, struct city b)
{
    if (a.s == b.s)
    return a.n < b.n;

    return a.s < b.s;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        city c[n+1];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            c[i].n = x;
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            c[i].s = x;
        }
        // calculating max bridges
        //sorting on basis of south point
        sort(c, c+n, compare);

        int lis[n+1];
        for (int i = 0; i < n; i++)
        {
            lis[i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (c[i].n >= c[j].n && lis[i] < 1 + lis[j])
                    lis[i] = 1 + lis[j];
            }
        }

        int max_lis = lis[0];
        for (int i = 1; i < n; i++)
            max_lis = max(max_lis, lis[i]);
        
        cout << max_lis<<endl;
    }
    return 0;
}