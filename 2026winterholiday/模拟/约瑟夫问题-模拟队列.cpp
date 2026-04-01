#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    queue<int>q;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }

    vector<int>result;
    int num=1;
    while(!q.empty()){
        if(num>m) num-=m;
        if(num==m){
            int n=q.front();
            q.pop();
            result.push_back(n);
            num++;
        }else {
            int n=q.front();
            q.pop();
            q.push(n);
            num++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}


//好理解版本

#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int>q;
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        q.push(i+1);
    }

    int count = 1;
    while(!q.empty()){
        int num = q.front();
        q.pop();

        if(count == m){
            cout<<num<<" ";
            count = 1;
        }else {
            q.push(num);
            count++;
        }
    }
    return 0;
}
