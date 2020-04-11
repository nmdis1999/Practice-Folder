#include <bits/stdc++.h>
#define int long long
#define fore(i, n) for (int i = 0; i < n; i++)
#define fori(i, n) for (int i = 1; i <=n; i++)
using namespace std;

const int N = 500005;
int arr[N];
int32_t main()
{
    int n, k;
    cin >> n >> k;
    fore(i, n)
    cin >> arr[i];
    int sum = 0, min_sum = 0;
    fore(i, k)
    sum += arr[i];
    min_sum = sum;
    int index = 0;
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i-k];
        if (sum < min_sum)
        {
            min_sum = sum;
            index = i-k+1; //pehle wala sum chotu tha
        }
    }

    cout <<index+1<<endl;
    return 0;
}