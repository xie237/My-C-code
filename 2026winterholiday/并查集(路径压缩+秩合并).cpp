#include<iostream>
using namespace std;

const int MAX_COUNT = 2e5+5;
int parent[MAX_COUNT];
int height[MAX_COUNT];

void init(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        height[i] = 1;
    }
}

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);  // 路径压缩
    }
    return parent[x];
}

// 合并操作（按秩合并）
void merge(int x, int y){
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY) return;  // 已经在同一集合
    
    // 将较矮的树合并到较高的树上
    if(height[rootX] < height[rootY]) {
        parent[rootX] = rootY;
    } 
    else if(height[rootX] > height[rootY]) {
        parent[rootY] = rootX;
    } 
    else {  // 两棵树高度相同
        parent[rootY] = rootX;
        height[rootX]++;  // 高度增加1
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;

    init(n);
    
    while(m--) {
        int z, x, y;
        cin >> z >> x >> y;
        
        if(z == 1) {
            merge(x, y);
        } 
        else {
            if(find(x) == find(y)) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
    }
    return 0;
}