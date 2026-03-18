#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[8]={1,-1,0,0,-1,1,1,-1};
int dy[8]={0,0,1,-1,-1,1,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<bool>>matrix(n, vector<bool>(m, false));//true代表干地， false代表水
    vector<vector<bool>>visited(n,vector<bool>(m, false));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='.') matrix[i][j]=true;
        }
    }

    int ans=0;
    
    queue<pair<int, int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && !matrix[i][j]){
                visited[i][j]=true;
                q.push({i,j});

                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();

                    for(int i=0;i<8;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];

                        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && !matrix[nx][ny]){
                            visited[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
                
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}



//手敲第二次dfs和bfs

#include<iostream>
#include<cstring>
using namespace std;

const int N = 105;
const int M=105;
char matrix[N][M];
bool visited[N][M];
int dx[8]={0,0,1,-1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};
int count=0;
int n,m;

void dfs(int x, int y){

    visited[x][y]=true;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]=='W' && !visited[nx][ny]){
            visited[nx][ny]=true;
            dfs(nx, ny);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(matrix[i][j]=='W' && !visited[i][j]) {dfs(i, j); count++;}
        }
    }
    cout<<count;
    return 0;
}

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=105;
const int M=105;
char matrix[N][M];
bool visited[N][M];
int dx[8]={0,0,1,-1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    memset(visited, false, sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    int count=0;
    queue<pair<int, int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && matrix[i][j]=='W'){
                q.push({i,j});
                count++;
            }

            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int k=0;k<8;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && matrix[nx][ny]=='W'){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

    cout<<count;
    return 0;
}