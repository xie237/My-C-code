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