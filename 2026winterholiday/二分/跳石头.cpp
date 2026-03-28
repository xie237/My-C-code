#include<iostream>
using namespace std;

const int M = 50010;
const int N = 50010;
int distancee[N];
int l,n,m;

bool check(int mid){
    int last = 0, remove = 0;
    for(int i=0;i<n;i++){
        if(distancee[i] - last < mid){
            remove++;
        }else {
            last = distancee[i];
        }
    }
    if(l - last < mid || remove > m){
        // 如果还能移走一块，就移走
        if(remove < m) {
            return true;
        }
        return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>l>>n>>m;
    for(int i=0;i<n;i++){
        cin>>distancee[i];
    }

    int left = 0, right = l;
    int ans = 0;
    while(left <= right){
        int mid = left + (right - left) / 2;
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
