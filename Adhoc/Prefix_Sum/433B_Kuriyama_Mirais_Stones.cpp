#include <bits/stdc++.h>
#define int long long
#define endl "\n"
 
using namespace std;
 
int32_t main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> b = a;
    
    sort(b.begin(), b.end());
    vector<int> pre1(n+1,0), pre2(n+1,0);
    
    for(int i = 1; i <= n; i++)
    {
        pre1[i]=pre1[i-1]+a[i-1],
        pre2[i]=pre2[i-1]+b[i-1];
    }
        
    int m; cin >> m;
    while(m--) 
    {
        int x, l, r;
        cin >> x >> l >> r;
        if(x == 1) cout << pre1[r] - pre1[l-1] << endl;
        else cout << pre2[r] - pre2[l-1] << endl;
    }
    return 0;
}