#include <iostream>
#define int long long 
using namespace std;

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
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (tot + a < 500)
        {
            tot += a;
            cout <<"A";
        }
        else
        {
            tot -= b;
            cout <<"G";
        }
    }
    return 0;
}