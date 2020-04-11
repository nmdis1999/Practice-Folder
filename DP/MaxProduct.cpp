#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int nums[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	cin >> nums[i];

	int MAX=nums[0], MIN=nums[0],res=nums[0];
		for(int i=1;i<nums.size();i++){
			int temp1=MAX, temp2=MIN;
			MAX=max(temp2*nums[i],max(temp1*nums[i],nums[i]));
			MIN=min(temp2*nums[i],min(temp1*nums[i],nums[i]));
			res=max(res,MAX);
		}

    cout << res << endl;
	return 0;
}