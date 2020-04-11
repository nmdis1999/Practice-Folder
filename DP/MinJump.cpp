//https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
#include <bits/stdc++.h> 
using namespace std; 
  
int n;
const int N = 5001;
int arr[N];
int min(int x, int y) { return (x < y) ? x : y; } 
  
// Returns minimum number of jumps 
// to reach arr[n-1] from arr[0] 
int minJumps(int arr[], int n) 
{ 
    // jumps[n-1] will hold the result 
    int* jumps = new int[n]; 
    int i, j; 
  
    if (n == 0 || arr[0] == 0) 
        return INT_MAX; 
  
    jumps[0] = 0; 
  
    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for (i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
} 
int32_t main() {
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
	cin >> n;
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    int ans = minJumps(arr, n);
    cout << ans << endl;
	return 0;
}
