#include<iostream>
using namespace std;

const int N = 1005;
int parent[N];

void init(int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX == rootY) return;
    parent[rootX] = rootY;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0){  // 先读 n，判断是否为 0
        int m;
        cin >> m;  // 再读 m
        
        init(n);

        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            merge(a-1,b-1);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i) cnt++;
        }

        cout << cnt - 1 << endl;
    }

    return 0;
}