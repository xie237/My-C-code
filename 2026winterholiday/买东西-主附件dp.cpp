#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

struct Item{
    int v, p ;
};
struct MainItem{
    Item main;  //主件
    vector<Item> attachments;  //附件
};
const int M=65;
MainItem items[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> dp(n+1, 0);
    for(int i=1;i<=m;i++){
        int v,p,q;
        cin>>v>>p>>q;
        if(q==0){
            items[i].main.v=v;
            items[i].main.p=v*p;
        }else{
            items[q].attachments.push_back({v,v*p});
        }
    }

    for(int i=1;i<=m;i++){
        vector<Item>choices;

        choices.push_back(items[i].main);//主件

        //主件加附件1
        if(items[i].attachments.size()>=1){
            Item temp;
            temp.v=items[i].main.v+items[i].attachments[0].v;
            temp.p=items[i].main.p+items[i].attachments[0].p;
            choices.push_back(temp);
        }

        //主件加附件2
        if(items[i].attachments.size()>=2){
            Item temp;
            temp.v=items[i].main.v+items[i].attachments[1].v;
            temp.p=items[i].main.p+items[i].attachments[1].p;
            choices.push_back(temp);
        }

        //主件加附件1 2
        if(items[i].attachments.size()>=2){
            Item temp;
            temp.v=items[i].main.v+items[i].attachments[0].v+items[i].attachments[1].v;
            temp.p=items[i].main.p+items[i].attachments[0].p+items[i].attachments[1].p;
            choices.push_back(temp);
        }

        for(int j=n;j>=0;j--){
            for(int k=0;k<choices.size();k++){
                if(j-choices[k].v>=0){
                    dp[j]=max(dp[j], dp[j-choices[k].v]+choices[k].p);
                }
            }
        }
    }

    cout<<dp[n];
    return 0;
}