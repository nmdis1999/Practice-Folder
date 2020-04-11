//Calculuate frequency array from given array
//then f(i) = max(f(i-1), f(i-2) + cnt[i].i)
//f(1) = cnt[1], f(0) = 0;
//return f(n)
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int arr[N];
map<int, int> freq;
int32_t main()
{
    int n;
    cin >> n;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        mx = max(mx, arr[i]);
    }

    int dp[mx+1];
    dp[1] = freq[1]; dp[0] = 0;
    for (int i = 2; i <= mx; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]*i);
    }

    cout <<dp[mx]<<endl;
}