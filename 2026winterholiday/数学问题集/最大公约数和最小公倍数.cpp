#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;
    
    // 第一步：y必须能被x整除
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int M = y / x;  // 这就是 a × b
    int ans = 0;
    
    // 枚举 a 从1到sqrt(M)
    for (int a = 1; a * a <= M; a++) {
        if (M % a == 0) {  // a 是 M 的因子
            int b = M / a;
            // 检查 a 和 b 是否互质
            if (gcd(a, b) == 1) {
                if (a == b) {
                    ans += 1;  // a=b时，只有一种顺序
                } else {
                    ans += 2;  // a≠b时，(a,b)和(b,a)两组
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}

/*
第一步：先理解关系（关键公式）

有一个很重要的公式：
text

P × Q = gcd(P,Q) × lcm(P,Q)

也就是：两个数的乘积 = 它们的最大公约数 × 最小公倍数

代入题目：
text

P × Q = x × y

第二步：设未知数简化问题

因为 gcd(P,Q) = x，所以 P 和 Q 都应该是 x 的倍数。

设：
text

P = x × a
Q = x × b

其中 a 和 b 互质（因为如果 a 和 b 还有公因子，P 和 Q 的 gcd 就会大于 x）
第三步：代入公式

把 P = x×a, Q = x×b 代入 P×Q = x×y：
text

(x×a) × (x×b) = x × y
x² × a × b = x × y
a × b = y / x

第四步：关键条件

从上面得到：

    a × b = y / x（所以 y 必须能被 x 整除，否则无解）

    a 和 b 互质（因为要保证 gcd(P,Q)=x）

第五步：问题转化

现在问题变成：

    已知 M = y / x，求有多少对正整数 (a,b) 满足：

        a × b = M

        gcd(a,b) = 1（互质）

第六步：怎么数互质对？

方法：枚举 a 从 1 到 sqrt(M)，判断 a 和 M/a 是否互质

因为如果 (a,b) 是一对，那么 (b,a) 也是一对，所以枚举到 sqrt 然后乘以 2 即可（但要小心 a=b 的情况）

*/
