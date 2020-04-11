#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
        int n;
        cin >> n;
        int a[n+1];
        int count = 0;
        vector<int> index;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i])
            index.pb(i);
            count += a[i] == 1;
        }

        if (n < 7 && count > 1)
        {
            cout <<"NO\n";
            return;
        }
        int s = index[0];
        // int flag = 0;
        // for (auto i :index)
        // cout <<i <<" ";
        // cout << endl;
        for (int i = 1; i < index.size() - 1; i++)
        {
            if (i - s < 6)
            {
                cout <<"NO\n";
                return;
            }
        }
        
        cout <<"YES\n";
        return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}