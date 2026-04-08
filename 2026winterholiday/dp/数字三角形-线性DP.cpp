#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;
    cin>>r;
    vector<int>tree;
    vector<int>rowfirst;
    for(int i=0;i<r;i++){
        for(int j=0;j<i+1;j++){
            int num;
            cin>>num;
            tree.push_back(num);
        }
        rowfirst.push_back(tree.size());
    }

    for(int i=r-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            // 当前数字在一维数组中的位置
            int pos = (i == 0) ? 0 : rowfirst[i-1] + j;

            int left_down=rowfirst[i]+j;
            int right_down=left_down+1;
            tree[pos]+=max(tree[left_down], tree[right_down]);
        }
        
    }
    cout<<tree[0];
    return 0;
}





#include <iostream>
#include <algorithm>
using namespace std;

int a[1005][1005];  // 存储三角形
int dp[1005][1005]; // DP状态

int main() {
    int n;
    cin >> n;
    
    // 读入三角形
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    
    // 初始化顶点
    dp[1][1] = a[1][1];
    
    // DP递推
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                // 最左边：只能从正上方来
                dp[i][j] = a[i][j] + dp[i-1][j];
            } 
            else if (j == i) {
                // 最右边：只能从左上方来
                dp[i][j] = a[i][j] + dp[i-1][j-1];
            } 
            else {
                // 中间：取左上方和正上方的最大值
                dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    // 找最后一行的最大值
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        ans = max(ans, dp[n][j]);
    }
    
    cout << ans << endl;
    
    return 0;
}



#include <iostream>
#include <algorithm>
using namespace std;

int a[1005][1005];
int dp[1005];  // 一维DP

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    
    dp[1] = a[1][1];
    
    for (int i = 2; i <= n; i++) {
        // 从右往左更新（关键！避免覆盖）
        for (int j = i; j >= 1; j--) {
            if (j == 1) {
                dp[j] = a[i][j] + dp[j];
            } 
            else if (j == i) {
                dp[j] = a[i][j] + dp[j-1];
            } 
            else {
                dp[j] = a[i][j] + max(dp[j-1], dp[j]);
            }
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        ans = max(ans, dp[j]);
    }
    cout << ans << endl;
    
    return 0;
}