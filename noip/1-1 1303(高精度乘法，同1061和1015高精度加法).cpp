#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // 处理其中一个为0的情况
    if (a == "0" || b == "0") {
        cout << "0" << endl;
        return 0;
    }

    // 反转字符串，从低位开始计算
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int len1 = a.size();
    int len2 = b.size();
    // 结果数组，长度足够存储最大可能位数（len1 + len2 + 1）
    vector<int> res(len1 + len2 + 1, 0);

    // 双重循环计算乘积
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            res[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    // 处理进位
    for (int i = 0; i < len1 + len2; i++) {
        if (res[i] >= 10) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }

    // 从最高位开始寻找第一个非零数字
    int idx = len1 + len2;
    while (idx >= 0 && res[idx] == 0) {
        idx--;
    }

    // 输出结果
    for (int i = idx; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}
