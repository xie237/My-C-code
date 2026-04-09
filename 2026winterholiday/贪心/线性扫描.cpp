#include <iostream>
#include <string>
using namespace std;

int main() {
    string row1, row2;
    cin >> row1 >> row2;

    int n = row1.size();
    
    int ans = 0;
    int lst = -1;      // 上一个有#的列
    int state = -1;    // 上一列的状态: 1=只有上, 2=只有下, 3=上下都有
    
    for (int i = 0; i < n; i++) {
        // 判断当前列是什么情况
        bool up = (row1[i] == '#');
        bool down = (row2[i] == '#');
        
        if (!up && !down) continue;  // 这一列全是空地，跳过
        
        int cur;  // 当前列的状态
        if (up && down) cur = 3;
        else if (up && !down) cur = 1;
        else cur = 2;
        
        // 不是第一列，处理水平距离
        if (lst != -1) {
            ans += (i - lst - 1);  // 中间空列，每列放一个
        }
        
        // 处理垂直冲突
        if (lst != -1) {
            if ((state == 1 && cur == 2) || (state == 2 && cur == 1)) {
                ans++;      // 行对不上，加1个
                state = 3;  // 连上之后变成上下都有
            } else {
                // 更新状态
                if (cur == 3) state = 3;
                else state = cur;
            }
        } else {
            // 第一列，直接记录状态
            state = cur;
        }
        
        lst = i;
    }
    
    cout << ans << endl;
    return 0;
}
