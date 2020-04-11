#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 100005;
class DisjointSet {
	private:
	vector<int> label; //label[x] stores the root of x if x is not root, otherwise it stores -(size of x's set).
	public:
	DisjointSet(){}
	DisjointSet(int n) {
		label.assign(n+7,-1); //label should contains at least n+1 elements, as x is 1-indexed.
		//At first, each node is a seperate set of size 1.		
	}
	int find(int x) { //find the root of set which contains x.
		if (label[x]<0) return (x); //x is root iff label[x] is negative.
		label[x]=find(label[x]);
		return (label[x]); //find the root of x by recursion.
	}
	bool join(int a,int b) { // join the sets which contains a and b. Return false iff a and b are already in the same set.
		int x=find(a);
		int y=find(b);
		if (x==y) return (false); //A set contains both a and b.
		if (label[x]>label[y]) swap(x,y); //label[x]>label[y] means size(x)<size(y).
		//We speed up the disjoint set by joinning the smaller set to the bigger set		
		label[x]+=label[y];
		label[y]=x; //Update the label of x and y.		
		return (true);
	}
	int getSize(int x) { //return the size of set which contains x.
		return (-label[find(x)]);
	}
};
int32_t main()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n >> m >> k;
    int inf[n+1];
    memset(inf, 0, sizeof(inf));
    for (i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        x--;
        inf[x] = 1;
    }
	DisjointSet G(N);
	
	for (i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (inf[x] && inf[y])
            continue;
        else
        {
            //good_egde.pb({x, y});
            G.join(x, y);
        }
	}
// 	for (int i = 0; i < n; i++)
// 	cout <<inf[i]<<" ";
// 	cout << endl;
    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        max_size = max(max_size, G.getSize(i));
    }
    
    for (int i = 0; i < n; i++)
    {
        
        if (inf[i] && G.getSize(i) == max_size)
        {
            cout <<max_size-1<<" "<<i+1;
            break;
        }
    }
    cout << endl;
    return 0;
}