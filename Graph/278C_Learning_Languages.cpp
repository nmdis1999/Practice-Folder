#include<bits/stdc++.h>
using namespace std;
// #define int long long
vector<int> par;
int findRoot(int i){
    while(par[i]!=i)i = par[i];
    return i;
}

void unionFind(int i, int j){
    int p = findRoot(i);
    int q = findRoot(j);
    par[p] = q;
}

signed main(){
    int m, n;
    cin>>n>>m;
    vector<vector<bool>> l(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        sum += k;
        l[i].resize(m+1, false);
        for(int j=0;j<k;j++){
            int lang;
            cin>>lang;
            l[i][lang] = true;
        }
    }
    if(sum==0){
        cout<<n<<endl;
        return 0;
    }
    par.resize(n);
    for(int i=0;i<n;i++)par[i] = i;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=1;k<=m;k++){
                if(l[i][k] && l[j][k]){
                    unionFind(i, j);
                    break;
                }
            }
        }
    }
    unordered_set<int> uset;
    for(int i=0;i<n;i++)uset.insert(findRoot(i));
    cout<<uset.size()-1<<endl;
    return 0;
    
    
}