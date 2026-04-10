#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 80112002;
const int MAXN = 5005;

vector<int> graph[MAXN];
int inDegree[MAXN], outDegree[MAXN];
int dp[MAXN];
int n, m;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; // a 被 b 吃
        graph[a].push_back(b);
        outDegree[a]++; // a 的出度增加（指向 b）
        inDegree[b]++;  // b 的入度增加
    }
    
    queue<int> q;
    // 初始化：所有生产者（入度为0）的 dp = 1
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }
    
    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // 统计所有顶级消费者（出度为0）的路径数之和
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (outDegree[i] == 0) {
            ans = (ans + dp[i]) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
