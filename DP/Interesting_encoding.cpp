#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        string digits;
        cin >> digits;

        int count[digits.size() + 1];
        int n = digits.size();
        //LIKE FIBONACCI SEQ DP
        if (digits[0] == '0')
        {
            cout <<0<<endl;
            continue;
        }
        count[0] = 1, count[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            count[i] = 0;
            if (digits[i - 1] > '0')
            count[i] += count[i - 1];
            if (digits[i - 2] == '1' || (digits[i - 2] == '2' && digits[i - 2] < '7'))
            count[i] += count[i - 2];
        }

        cout << count[n] << endl;
    }
    return 0;
}