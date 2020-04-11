#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 100005;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char a[n+1][m+1];
        bool flag = true;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < m; j++)
            {
               {
                    if (flag)
                      a[i][j] = 'B';
                    else
                    a[i][j] = 'W';
                
                    flag = flag ? false : true;
               }
            }
            
            flag = flag ? false : true;
        }
        int i =  n-1;
        for (int j = 0; j < m - 1; j++)
        {
            if (flag)
                a[i][j] = 'B';
            else
                a[i][j] = 'W';
                
            flag = flag ? false : true;
        }
        
        a[n-1][m-1] = a[n-1][m-2] == 'B' ? 'B' : 'W';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout <<a[i][j];
            cout << endl;
        }
    }
    return 0;
}