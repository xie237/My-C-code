#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=310;
char matrix[N][N];
pair<int, int> door[26][2];  // 26个字母，每个字母存两个点
int door_cnt[26]={0};        // 记录每个字母找到了几个
int dist[N][N];              // 记录最短距离
bool vis[N][N];              // 访问标记
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n,m;

struct point{
    int x,y;
};

int bfs(point start){
    memset(dist, -1, sizeof(dist));
    memset(vis, false, sizeof(vis));
    
    queue<point> q;
    dist[start.x][start.y] = 0;
    vis[start.x][start.y] = true;
    q.push(start);
    
    while(!q.empty()){
        point cur = q.front();
        q.pop();
        
        // 检查是否到达出口
        if(matrix[cur.x][cur.y] == '='){
            return dist[cur.x][cur.y];
        }
        
        // 遍历四个方向
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            // 边界检查
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(matrix[nx][ny] == '#') continue;
            
            // 如果是传送门
            if(matrix[nx][ny] >= 'A' && matrix[nx][ny] <= 'Z'){
                int idx = matrix[nx][ny] - 'A';
                
                // 找到传送门的另一端
                int tx, ty;
                if(nx == door[idx][0].first && ny == door[idx][0].second){
                    tx = door[idx][1].first;
                    ty = door[idx][1].second;
                } else {
                    tx = door[idx][0].first;
                    ty = door[idx][0].second;
                }
                
                // 传送到另一端（注意：这里不标记另一端为已访问）
                // 只记录距离，因为传送器可以多次使用
                if(dist[tx][ty] == -1 || dist[tx][ty] > dist[cur.x][cur.y] + 1){
                    dist[tx][ty] = dist[cur.x][cur.y] + 1;
                    q.push({tx, ty});
                }
            }
            // 如果是普通格子（包括起点、草地、出口）
            else {
                if(dist[nx][ny] == -1 || dist[nx][ny] > dist[cur.x][cur.y] + 1){
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    point start;
    
    // 初始化
    memset(door_cnt, 0, sizeof(door_cnt));
    
    // 读取迷宫
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            
            if(matrix[i][j] == '@') {
                start.x = i;
                start.y = j;
                matrix[i][j] = '.';  // 将起点标记为可通行的草地
            }
            else if(matrix[i][j] >= 'A' && matrix[i][j] <= 'Z'){
                int idx = matrix[i][j] - 'A';
                door[idx][door_cnt[idx]++] = {i, j};
            }
        }
    }
    
    int result = bfs(start);
    cout << result << endl;
    
    return 0;
}