#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;
    
    vector<int> a(n);
    unordered_map<int, int> cnt;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    long long ans = 0;
    
    if(c == 0){
        for(auto& p : cnt){
            long long t = p.second;
            ans += t * (t - 1);
        }
    } else {
        for(int i = 0; i < n; i++){
            ans += cnt[a[i] + c];
        }
    }
    
    cout << ans;
    return 0;
}