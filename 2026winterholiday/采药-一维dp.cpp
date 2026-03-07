#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

struct med{
    int time,value;
};
const int M=105;
med med[M];
const int T=1005;
int dp[T];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,m; //t是时间，应该相当于背包容量 ，m是草药数，物品数目
    cin>>t>>m;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++){
        cin>>med[i].time>>med[i].value;
    }

    for(int i=0;i<m;i++){
        for(int j=t;j>=med[i].time;j--){
            dp[j]=max(dp[j],dp[j-med[i].time]+med[i].value);
        }
    }

    cout<<dp[t];
    return 0;
}