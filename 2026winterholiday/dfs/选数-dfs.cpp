#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=25;
int x[N];
int countt=0;
bool visited[N];
int n,k;

bool isPrime(int num){
    if(num==2) return true;
    
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return false;
    }
    return true;
}

void dfs(int start, int cnt, int sum){
    if(cnt + (n - start) < k) return;
    
    if(cnt==k){
        if(isPrime(sum)){
            countt++;
        }
        return ;
    }

    for(int i=start;i<n;i++){
        // if(sum + x[i] > maxSum) break;
        
        visited[i]=true;
        dfs(i+1,cnt+1,sum+x[i]);
        visited[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);

    dfs(0,0,0);

    cout<<countt;
    return 0;
}
