#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 3e6 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n + 1);     // 原数组，下标从1开始
    vector<int> f(n + 1, 0);  // 结果数组，初始化为0
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    stack<int> stk;  // 单调栈，存储下标，栈顶到栈底单调递减
    
    // 正序遍历
    for (int i = 1; i <= n; i++) {
        // 当前元素a[i]比栈顶元素大时，说明找到了栈顶元素的右边第一个更大值
        while (!stk.empty() && a[i] > a[stk.top()]) {
            f[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    
    // 输出结果
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }
    
    return 0;
}
