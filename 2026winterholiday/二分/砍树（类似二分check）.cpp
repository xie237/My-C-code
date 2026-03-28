#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
const int M = 2e9;
int height[N];
int n, m;

bool check(int mid){
    long long total = 0;
    for(int i=0;i<n;i++){
        if(height[i] - mid > 0) total += height[i] - mid;
        if(total >= m){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    int max_height = 0;
    for(int i=0;i<n;i++){
        cin>>height[i];
        max_height = max(max_height, height[i]);
    }

    int left = 0, right = max_height;
    int ans;
    while(left <= right){
        int mid = left + (right - left) / 2;;
        if(check(mid)){
            ans = mid;
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    cout<<ans;
    return 0;
}
