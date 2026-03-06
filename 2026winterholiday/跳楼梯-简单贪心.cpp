#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 305;
int h[N];
bool visited[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    h[0]=0;
    memset(visited, false, sizeof(visited));
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    sort(h, h+n+1);
    long long result = 0;
    int left=0, right=n;
    bool flag = true; //true为向大数跳

    while(left<right){
        if(flag){
            result += (h[left]-h[right]) * (h[left]-h[right]);
            flag = false;
            left++;
        }else {
            result += (h[right]-h[left]) * (h[right]-h[left]);
            flag = true;
            right--;
        }
    }
    
    cout<<result;
    return 0;
}