#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    
    vector<int> num(n);
    unordered_map<int, int> cnt;
    
    for(int i = 0; i < n; i++){
        cin >> num[i];
        cnt[num[i]]++;
    }
    
    long long ans = 0;  // 用long long，可能很大
    
    if(c == 0){
        // 特殊处理C=0
        for(auto& [num, count] : cnt){
            ans += (long long)count * (count - 1);
        }
    } else {
        // 正常情况
        for(int i = 0; i < n; i++){
            int current = num[i];
            long long target = (long long)current + c;  // 防止溢出
            
            if(cnt.count(target)){
                ans += cnt[target];
            }
        }
    }
    
    cout << ans;
    
    return 0;
}