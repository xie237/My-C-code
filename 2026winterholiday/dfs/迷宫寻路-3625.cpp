#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<bool>> visited;
vector<vector<bool>> wall;
int n, m;
struct point {
    int x,y;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    visited.resize(n, vector<bool>(m, false));
    wall.resize(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='#') wall[i][j]=true;
        }
    }

    queue<pair<int,int>>q;
    if(!wall[0][0]){
        q.push({0, 0});
        visited[0][0]=true;
    }

    bool found=false;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if(x==n-1 && y==m-1){
            found=true;
            break;
        }

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && !wall[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }

    if(found) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}


//顺带练了一下dfs，但本题超时，最短路径要选bfs
#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<bool>> visited;
vector<vector<bool>> wall;
int n, m;

bool dfs(int x, int y) {
    if(x == n-1 && y == m-1) return true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < m 
           && !wall[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = true;
            if(dfs(nx, ny)) return true;
            visited[nx][ny] = false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    visited.resize(n, vector<bool>(m, false));
    wall.resize(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if(ch == '#') wall[i][j] = true;
        }
    }
    
    if(wall[0][0]) {
        cout << "No";
        return 0;
    }
    
    visited[0][0] = true;
    bool result = dfs(0, 0);
    
    if(result) cout << "Yes";
    else cout << "No";
    
    return 0;
}


