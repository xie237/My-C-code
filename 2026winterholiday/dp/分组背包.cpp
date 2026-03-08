#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

struct item{
    int value, weight;
};
struct group{
    vector<item>items;
};
const int M=1005;
const int K=105;
group groups[K];
bool visited[K];
int dp[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>m>>n;//最大重量m  一共n件物品
    memset(visited, false, sizeof(visited));
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        groups[c].items.push_back({a,b});
        visited[c]=true;
    }

    for(int i=0;i<K;i++){
        if(visited[i]){
            for(int k=m;k>=0;k--){
                for(int j=0;j<groups[i].items.size();j++){
                    if(k-groups[i].items[j].value>=0){
                        dp[k]=max(dp[k], dp[k-groups[i].items[j].value]+groups[i].items[j].weight);
                    }
                }
            }
        }
    }

    cout<<dp[m];
    return 0;
}

/*
背包类型	  外层循环	  中层循环	  内层循环	  核心特点
0-1背包	     物品	  容量（逆序）	无	  每个物品最多选一次
完全背包	     物品	  容量（正序）	无  	每个物品无限选
多重背包     	物品	  容量（逆序）	数量	每个物品有限次
分组背包	      组	   容量（逆序）	组内物品	每组最多选一个
二维费用	    物品 容量1（逆序）	容量2（逆序）	两种限制条件
*/