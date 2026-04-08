#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 105;
int matrix[N][N];
int prefix[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    memset(prefix, 0, sizeof(prefix));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
        }
    }

    int ans = 0;
    int dp[N][N];
    memset(dp, 0, sizeof(dp));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j] == 1) {
                 dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                 ans = max(ans, dp[i][j]);
            }
        }
    }

    cout<<ans;
    return 0;
}
