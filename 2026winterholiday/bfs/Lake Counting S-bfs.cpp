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