#include <queue>
#include <vector>
#include <climits>
using namespace std;

int dijkstra(vector<vector<pair<int,int>>>& graph, int start, int target) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    // 优先队列：pair<距离, 节点>，小顶堆
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        // ========== 关键：跳过旧记录 ==========
        // 如果从队列里弹出来的距离，比 dist[u] 还要大
        // 说明这条记录是过期的（之前已经找到了更短的路）
        if (d > dist[u]) {
            continue;  // 直接扔掉，不处理
        }
        // ===================================
        
        if (u == target) return d;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            int newDist = d + w;
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});  // 新记录入队，旧记录还在堆里
            }
        }
    }
    return dist[target];
}

#include <queue>
#include <vector>
#include <climits>
using namespace std;

int spfa(vector<vector<pair<int,int>>>& graph, int start, int target) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> inQueue(n, false);  // 标记节点是否已在队列中
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    inQueue[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;  // ========== 关键1：出队时清除标记 ==========
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                
                // ========== 关键2：如果 v 不在队列中，就重新入队 ==========
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
                // ===================================================
            }
        }
    }
    return dist[target];
}