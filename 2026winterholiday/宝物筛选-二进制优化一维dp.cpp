#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct treasure{
    int v,w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,W;
    cin>>n>>W;
    int length=0;
    vector<treasure>items;
    for(int i=0;i<n;i++){
        int v,w,m;
        cin>>v>>w>>m;

        int k=1;
        while(m>=k){
            items.push_back({v*k, w*k});
            length++;
            m-=k;
            k*=2;
        }
        if(m>0){
            items.push_back({v*m, w*m});
            length++;
        }
    }

    vector<int>dp(W+1);
    for(int i=0;i<length;i++){
        for(int j=W;j>=items[i].w;j--){
            dp[j]=max(dp[j], dp[j-items[i].w]+items[i].v);
        }
    }

    cout<<dp[W];
    return 0;
}