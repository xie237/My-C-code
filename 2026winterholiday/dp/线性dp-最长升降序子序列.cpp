#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=105;
int height[N];
int dp_up[N];
int dp_down[N];

// 计算以每个位置结尾的最长上升子序列长度
void calculate_lis1(int n) {
    for(int i=0; i<n; i++) {
        dp_up[i] = 1;  // 至少自己
        for(int j=0; j<i; j++) {
            if(height[j] < height[i]) {  // 严格递增
                dp_up[i] = max(dp_up[i], dp_up[j] + 1);
            }
        }
    }
}

// 计算以每个位置开头的最长下降子序列长度
void calculate_lds1(int n) {
    for(int i=n-1; i>=0; i--) {
        dp_down[i] = 1;  // 至少自己
        for(int j=i+1; j<n; j++) {
            if(height[j] < height[i]) {  // 严格递减
                dp_down[i] = max(dp_down[i], dp_down[j] + 1);
            }
        }
    }
}

// 计算以每个位置结尾的最长上升子序列长度 O(n log n)
void calculate_lis(int n) {
    vector<int> d;  // d[i]表示长度为i+1的LIS的最小末尾
    
    for(int i=0; i<n; i++) {
        // 找第一个 >= height[i] 的位置（严格递增用 lower_bound）
        auto it = lower_bound(d.begin(), d.end(), height[i]);
        
        // 当前i的LIS长度 = 位置 + 1
        dp_up[i] = (it - d.begin()) + 1;
        
        if(it == d.end()) {
            d.push_back(height[i]);
        } else {
            *it = height[i];
        }
    }
}

// 计算以每个位置开头的最长下降子序列长度 O(n log n)
void calculate_lds(int n) {
    vector<int> d;  // 用于贪心+二分
    
    for(int i=n-1; i>=0; i--) {
        // 下降序列反过来就是上升序列
        // 找第一个 >= height[i] 的位置
        auto it = lower_bound(d.begin(), d.end(), height[i]);
        
        dp_down[i] = (it - d.begin()) + 1;
        
        if(it == d.end()) {
            d.push_back(height[i]);
        } else {
            *it = height[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>height[i];
    }

    calculate_lis(n);
    calculate_lds(n);
    
    // 找最优的峰顶
    int ans = 0;
    for(int i=0; i<n; i++) {
        // 以i为峰顶，能保留的人数 = 左边上升 + 右边下降 - 1
        ans = max(ans, dp_up[i] + dp_down[i] - 1);
    }
    
    cout << n - ans << endl;
    
    return 0;
}