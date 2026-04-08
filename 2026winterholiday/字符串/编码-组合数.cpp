#include <iostream>
#include <string>
using namespace std;

int C[27][27];

void initC() {
    for (int i = 0; i <= 26; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

int main() {
    initC();
    string s;
    cin >> s;
    int L = s.size();

    //合法性检查
    if (L > 6) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < L; i++) {
        if (s[i] <= s[i-1]) {
            cout << 0 << endl;
            return 0;
        }
    }

    //长度小于 L 的单词数
    int ans = 0;
    for (int i = 1; i < L; i++) {
        ans += C[26][i];
    }

    //长度等于 L 且小于 s 的单词数
    int last = 0;
    for (int i = 0; i < L; i++) {
        int cur = s[i] - 'a' + 1;
        for (int ch = last + 1; ch < cur; ch++) {
            ans += C[26 - ch][L - i - 1];
        }
        last = cur;
    }

    cout << ans + 1 << endl;

    return 0;
}
