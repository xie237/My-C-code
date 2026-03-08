#include<iostream>
#include<cmath>
using namespace std;

const int V=20005;
const int N=35;
int weight[N];//价值和重量相等
int dp[V];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, n;
    cin>>v>>n;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    for(int i=0;i<n;i++){
        for(int j=v;j>=0;j--){
            if(j-weight[i]>=0){
                dp[j]=max(dp[j], dp[j-weight[i]]+weight[i]);
            }
        }
    }

    cout<<v-dp[v];
    return 0;
}