#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void sum_optimized(const string& a, const string& b) {
    string s;
    // 预分配内存
    s.reserve(max(a.length(), b.length()) + 1);
    
    int i = a.length() - 1;
    int j = b.length() - 1;
    int complement = 0;
    
    while (i >= 0 || j >= 0 || complement) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;
        
        int summ = digitA + digitB + complement;
        complement = summ / 10;
        s.push_back(summ % 10 + '0');
        
        i--; j--;
    }
    
    reverse(s.begin(), s.end());
    cout << s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    sum_optimized(a, b);
    return 0;
}