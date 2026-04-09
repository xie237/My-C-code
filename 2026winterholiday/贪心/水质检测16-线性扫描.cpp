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


/*

思考过程（怎么想到要这些变量）
第1步：确定要扫描什么

    题目是线性的（从左到右）

    所以肯定是一列一列扫描

    需要记录“上一个有 # 的列”的信息

第2步：问自己：上一列的什么信息会影响当前决策？

核心问题：当前列和上一列，它们的 # 能不能直接连上？

要回答这个问题，需要知道：

    上一列在哪 → 需要 lst（列号）

    上一列的 # 分布（上行有？下行有？）→ 需要 state

第3步：state 需要几种取值？

问：上一列 # 的分布，有几种本质不同的情况？

    只有上行有

    只有下行有

    两行都有

为什么“两行都有”是单独的？
因为一旦两行都有，这一列就已经上下连通了，后续任何列都能直接连上，不需要额外垂直代价。

所以 state 需要 3 种状态。
第4步：还需要别的吗？

    当前列的信息？不需要存，正在处理，用完就扔

    总答案？需要 ans

    遍历索引？i 就是

够了：lst, state, ans, 再加一个 cur 临时变量
通用方法论

当你需要从左到右扫描解决问题时，问自己：

    我需要记住“上一个”的什么信息？

        位置？→ 需要 last_pos

        状态？→ 需要 last_state

    这个状态有几种本质不同的取值？

        枚举所有可能，去重合并

        比如这题：{只有上, 只有下, 上下都有} = 3 种

    当前信息需要存吗？

        通常不需要，正在处理

        处理完变成“上一个”，更新 last_xxx

*/
