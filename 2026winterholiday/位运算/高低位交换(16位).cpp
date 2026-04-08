#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    unsigned int low = n & 0xFFFF;      // 低16位
    unsigned int high = n >> 16;        // 高16位

    unsigned int result = (low << 16) | high;

    cout << result << endl;

    return 0;
}

//不用位运算
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    // 转成 32 位二进制字符串
    bitset<32> b(n);
    string s = b.to_string();

    // 交换高低 16 位
    string high = s.substr(0, 16);
    string low  = s.substr(16, 16);
    string newBin = low + high;

    // 转回数字
    bitset<32> newBits(newBin);
    cout << newBits.to_ulong() << endl;

    return 0;
}
