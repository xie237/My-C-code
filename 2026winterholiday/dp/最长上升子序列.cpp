#include<iostream>
#include<cmath>

using namespace std;

const int N=5010;
int arrays[N];
int dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arrays[i];
    }


    int ans=1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arrays[j]<arrays[i]){
                 dp[i]=max(dp[i], dp[j]+1);
            }
        }
        ans=max(ans, dp[i]);
    }

    cout<<ans;


    return 0;
}