#include<iostream>
using namespace std;

const int N = 5e5+10;
int w[N];
int n,a,b;// a自然条件， b烘干机

bool check(int mid){
    long long total_need = 0;
    for(int i=0;i<n;i++){
        long long remain = w[i] - ( 1LL * a * mid );//1LL强制进行long long运算
        if(remain > 0){
            long long need = (remain + b - 1) / b; //向上取整
            total_need += need;
        }
        if(total_need > mid){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }

    int left = 0;int right = 1e9;
    int ans;
    while(left<=right){
        int mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout<<ans;
    return 0;
}

//回来了，项目融合了推荐等算法，马上蓝桥了啊，好慌，最近没咋刷题
