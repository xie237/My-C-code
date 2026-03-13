#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;
    cin>>r;
    vector<int>tree;
    vector<int>rowfirst;
    for(int i=0;i<r;i++){
        for(int j=0;j<i+1;j++){
            int num;
            cin>>num;
            tree.push_back(num);
        }
        rowfirst.push_back(tree.size());
    }

    for(int i=r-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            // 当前数字在一维数组中的位置
            int pos = (i == 0) ? 0 : rowfirst[i-1] + j;

            int left_down=rowfirst[i]+j;
            int right_down=left_down+1;
            tree[pos]+=max(tree[left_down], tree[right_down]);
        }
        
    }
    cout<<tree[0];
    return 0;
}