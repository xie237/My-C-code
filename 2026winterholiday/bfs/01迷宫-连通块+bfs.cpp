#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N=1010;
const int M=100010;
char matrix[N][N];
int result[M];
bool visited[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int idx=0;
int ans[N][N];

void bfs(int i,int j){
    if(ans[i][j] != -1) {  // 如果已经算过
        result[idx++] = ans[i][j];
        return;
    }
    
    int count=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    visited[i][j]=true;
    vector<pair<int,int>> path;
    path.push_back({i,j});

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx>n || ny>n || nx<=0 ||ny<=0) continue;
            if(matrix[nx][ny]=='n' || visited[nx][ny]==true) continue;
            if(matrix[nx][ny]==matrix[x][y]) continue;

            count++;
            visited[nx][ny]=true;
            q.push({nx,ny});
            path.push_back({nx,ny});
        }
    }

    for(auto p : path){
        ans[p.first][p.second]=count;
    }
    
    result[idx++]=count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    memset(matrix,'n',sizeof(matrix));
    memset(ans,-1,sizeof(ans));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }

    for(int k=0;k<m;k++){
        int i,j;
        cin>>i>>j;

        bfs(i,j);
    }

    for(int i=0;i<m;i++){
        cout<<result[i]<<endl;
    }
    
    return 0;
}



//预先处理快200ms

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N=1010;
char matrix[N][N];
int ans[N][N];  // 存储每个格子的答案
bool visited[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;

void bfs(int i,int j){
    vector<pair<int,int>> path;
    queue<pair<int,int>>q;
    q.push({i,j});
    visited[i][j]=true;
    path.push_back({i,j});
    int count=1;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx<1 || nx>n || ny<1 || ny>n) continue;
            if(matrix[nx][ny]=='n' || visited[nx][ny]) continue;
            if(matrix[nx][ny]==matrix[x][y]) continue;

            visited[nx][ny]=true;
            q.push({nx,ny});
            path.push_back({nx,ny});
            count++;
        }
    }
    
    for(auto p : path){
        ans[p.first][p.second]=count;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    memset(matrix,'n',sizeof(matrix));
    memset(visited,false,sizeof(visited));
    memset(ans,0,sizeof(ans));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    
    // 预处理：一次BFS找出所有连通块
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!visited[i][j]){
                bfs(i,j);
            }
        }
    }

    // 直接回答询问
    for(int k=0;k<m;k++){
        int i,j;
        cin>>i>>j;
        cout<<ans[i][j]<<'\n';
    }
    
    return 0;

}
