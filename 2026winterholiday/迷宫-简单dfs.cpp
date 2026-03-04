#include<iostream>
#include<cstring>
using namespace std;

int count=0;
const int N=10;
const int M=10;
bool visited[N][M];
bool maze[N][M];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int sx,sy,fx,fy;
int n,m,t;

void dfs(int x,int y){
    if(x==fx && y==fy){
        count++;
        return ;
    }

    visited[x][y]=true;
    
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>0 && nx<=n && ny>0 && ny<=m && !maze[nx][ny] && !visited[nx][ny]){
            dfs(nx,ny);
        }
    }
    visited[x][y]=false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    memset(visited,false,sizeof(visited));
    memset(maze,false,sizeof(maze));

    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        maze[a][b]=true;
    }

    dfs(sx,sy);

    cout<<count;
    
    return 0;
}