#include<iostream>
#include<string>
using namespace std;

typedef unsigned long long ULL;
const int N = 1000010;
const int P = 131;  // 经验值，131或13331

ULL h[N];  // h[i]存前i个字符的哈希值
ULL p[N];  // p[i]存P的i次方

// 预处理字符串s的哈希值
void init(string s) {
    int n = s.size();
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        h[i] = h[i-1] * P + s[i-1];  // 计算前缀哈希
        p[i] = p[i-1] * P;            // 计算P的幂
    }
}

// 获取子串s[l..r]的哈希值（l从0开始）
ULL get(int l, int r) {
    return h[r+1] - h[l] * p[r - l + 1];
}

int main() {
    string s = "abcdefg";
    init(s);
    
    // 判断"abc"和"bcd"是否相等
    if(get(0,2) == get(1,3)) {
        cout << "相等" << endl;
    } else {
        cout << "不相等" << endl;
    }
    
    return 0;
}