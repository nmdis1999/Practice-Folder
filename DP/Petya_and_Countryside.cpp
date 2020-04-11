#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vc1,vc2;
    vector<int> vc3(n,1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vc1.push_back(x);
        vc2.push_back(x);
    }
    // sort(vc2.begin(),vc2.end());
    // for(int i=0;i<vc2.size();i++) cout<<vc2[i]<<" ";
    // cout<<endl;
    int l=0;
 
    if(vc1.size()==1){
        cout<<1<<endl;
    }
    else{
        for(int i=0;i<vc2.size();i++){
            
            for(int j=i;j<vc1.size()-1;j++){
                if(vc1[j+1]<=vc1[j]) {vc3[i]++;}
                else break;
            }
            for(int j=i;j>0;j--){
                if(vc1[j-1]<=vc1[j]) {vc3[i]++;}
                else break;
            }
            // cout<<c1+c2-2<<endl;
        }
        // cout<<endl;
        // for(int i=0;i<vc3.size();i++) cout<<vc3[i]<<" ";
        // cout<<endl;
        sort(vc3.begin(),vc3.end());
        cout<<vc3[vc3.size()-1]<<endl;
        //100
        // 1 2 3 4 5 6 7 8 9 10 11 100 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 1 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
    }
    return 0;
}