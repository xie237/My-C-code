#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;  // {距离, 点}
const int INF = 0x3f3f3f3f;
const int N = 100010;

vector<pii> g[N];  // 邻接表: g[u] = {v, w}
int dist[N];
bool vis[N];

void dijkstra(int start) {
    // 1. 初始化
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[start] = 0;
    
    // 2. 优先队列 (小根堆)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    // 3. 主循环
    while (!pq.empty()) {
        // 取出当前距离最小的点
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // 如果这个点已经确定过了，跳过
        if (vis[u]) continue;
        vis[u] = true;
        
        // 遍历 u 的所有邻居
        for (auto [v, w] : g[u]) {
            // 如果从 u 走能更短，就更新
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});  // 把更短的路放进队列
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});  // 有向图
        // 如果是无向图，再加一行: g[v].push_back({u, w});
    }
    
    dijkstra(start);
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    
    return 0;
}