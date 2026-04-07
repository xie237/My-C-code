#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

struct bag{
    int value, height;
};
const int M = 1e7+10;
bag bags[M];
long long dp[M];

bool compare(bag a, bag b){
    return a.value > b.value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,m;
    cin>>t>>m;
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<m;i++){
        cin>>bags[i].height>>bags[i].value;
    }

    sort(bags, bags+m,compare);

    for(int i=0;i<m;i++){
        for(int j=1;j<=t;j++){
            if(j >= bags[i].height){
                dp[j] = max(dp[j], dp[j - bags[i].height] + bags[i].value);
            }
        }
    }

    cout<<dp[t];
    return 0;
}