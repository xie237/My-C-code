#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAX_SIZE=410;
int step[MAX_SIZE][MAX_SIZE];
int n,m,x,y;

int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
int dy[8]={2, 1, -1, -2, -2, -1, 1, 2};

struct point{
    int x,y;
};

void bfs(int x,int y){
    memset(step, -1, sizeof(step));
    step[x][y]=0;
    queue<point>q;
    q.push({x,y});

    while(!q.empty()){
        point cur=q.front();
        q.pop();
        
        for(int i=0;i<8;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx>=1 && nx<=n && ny>=1 && ny<=m && step[nx][ny]==-1){
                step[nx][ny]=step[cur.x][cur.y]+1;
                q.push({nx,ny});
            }
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>x>>y;
    bfs(x,y);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<step[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
