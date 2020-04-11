#include <bits/stdc++.h>
using namespace std;


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
        int n, l, r;
        cin >> n >> l >> r;   
        if (l == r)
        {
            cout <<1<<endl;
            continue;
        }
        vector<int> a(2*n+2);
        for (int i = 0; i < 2*n+2;i++)
            a[i] = i+1;
        vector<int> b(2*n+2);
        b = a;
        const int MOD = 2*n;
        reverse(b.begin(), b.end());
        for (auto i : a)
        cout <<i<<" ";
        cout << endl;
        for (auto i : b)
        cout <<i<<" ";
        for (int i = 0; i < n; i++)
        {
            a[i] = (a[i] + 1) % MOD;
            b[i] = (b[i] + 1) % MOD;
        }
        for (auto i : a)
        cout <<i<<" ";
        cout << endl;
        for (auto i : b)
        cout <<i<<" ";
        cout << endl;
    }
    return 0;
}