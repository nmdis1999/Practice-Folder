#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--)
    {
       double n, x;
       cin >> n >> x;
       vector<double> a(n+1);
       double sum = 0, index = 1;
       for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
       sort(a.begin(), a.end());
       double div = sum / n;
       if (div >= x)
        cout << n << endl;
       else
       {
           //cout <<"entered\n";
           while (div < x)
           {
               sum -= a[index];
               div = (sum / (n - index));
                // cout <<"sum "<<sum<<endl;
                // cout <<"div "<<div<<endl;
                // cout <<"index "<<index<<endl;
               index++;
           }
        //   cout << "index" << index <<endl;
           cout <<n - index + 1<< endl;
       }
    }

    return 0;
}