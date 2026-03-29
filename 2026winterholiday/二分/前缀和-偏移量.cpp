#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
const int OFFSET = 1e5;  // 偏移量，处理负数下标

int per[N];
int prefix[N];
int fir[2*N];//每个前缀和第一次出现的地方,因为前缀和范围是[-n, n]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    memset(fir, -1, sizeof(fir));
    fir[0 + OFFSET] = 0;
    int max_count = 0;
    for(int i=1;i<=n;i++){
        cin>>per[i];//男生+1， 女生-1
        if(per[i]){
            prefix[i] = prefix[i-1] + 1;
        }else {
            prefix[i] = prefix[i-1] - 1;
        }

        int idx = prefix[i] + OFFSET;

        if(fir[idx] == -1){
            fir[idx] = i;
        }else {
            max_count = max(max_count, i - fir[idx]);
        }
    }

    cout<<max_count;
    return 0;
}
