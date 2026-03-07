#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=35;
int matrix[N][N];
bool visited[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n;

struct point{
    int x,y;
};

void bfs(int x,int y){
    queue<point>q;
    q.push({x,y});
    visited[x][y]=true;

    while(!q.empty()){
        point p;
        p=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<n) ;
            else continue;
            
            if(matrix[nx][ny]==0 && visited[nx][ny]==false){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        if(matrix[0][i]==0 && visited[0][i]==false){
            bfs(0,i);
        }
        if(matrix[i][0]==0 && visited[i][0]==false){
            bfs(i,0);
        }
    }

    for(int i=0;i<n;i++){
        if(matrix[n-1][i]==0 && visited[n-1][i]==false){
            bfs(n-1,i);
        }
        if(matrix[i][n-1]==0 && visited[i][n-1]==false){
            bfs(i,n-1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] || matrix[i][j]==1) cout<<matrix[i][j]<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
