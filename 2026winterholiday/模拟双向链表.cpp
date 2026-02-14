#include<iostream>
using namespace std;

const int N = 100005;
int leftt[N],rightt[N];
bool exist[N];

int main(){
    int n;
    cin>>n;
    leftt[1]=0;//0表示空
    rightt[1]=0;
    exist[1]=true;
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        exist[i]=true;
        //记住左右分别要改四个指针
        if(p==0){
            leftt[i] = leftt[k];
            rightt[i]=k;
            if(leftt[i]!=0){
                rightt[leftt[k]] = i;
            }
            leftt[k] = i;
        }else{
            leftt[i]=k;
            rightt[i]=rightt[k];
            if(rightt[k]!=0){
                leftt[rightt[k]]=i;
            }
            rightt[k] = i;
        }
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(exist[x]){
            exist[x]=false;
            if(leftt[x]!=0){
                rightt[leftt[x]]=rightt[x];
            }
            if(rightt[x]!=0){
                leftt[rightt[x]]=leftt[x];
            }
        }
    }

    //找到头节点
    int head=1;
    while(leftt[head]!=0){
        head=leftt[head];
    }

    bool first = true;
    for (int i = head; i != 0; i = rightt[i]) {
        if (exist[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;
    return 0;
}