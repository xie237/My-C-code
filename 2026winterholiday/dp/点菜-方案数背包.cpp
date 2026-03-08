#include<iostream>
#include<cmath>
using namespace std;

const int M=10005;
const int N=105;
int menu[N];
int dp[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>menu[i];
    }

    dp[0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            if(j-menu[i]>=0){
                dp[j]=dp[j]+dp[j-menu[i]];
            }
        }
    }

    cout<<dp[m];
    return 0;
}