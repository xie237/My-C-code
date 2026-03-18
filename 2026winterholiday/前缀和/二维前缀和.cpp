#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> diff(n+2, vector<int>(n+2, 0));
    
    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        diff[x1][y1] += 1;
        diff[x1][y2+1] -= 1;
        diff[x2+1][y1] -= 1;
        diff[x2+1][y2+1] += 1;
    }
    
    vector<vector<int>> space(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            space[i][j] = space[i-1][j] + space[i][j-1] 
                         - space[i-1][j-1] + diff[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << space[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}



//原地计算
#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+2, vector<int>(n+2, 0));
    
    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++, a[x1][y2+1]--;
        a[x2+1][y1]--, a[x2+1][y2+1]++;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << (j == n ? "\n" : " ");
        }
    }
    
    return 0;
}


//原地计算加数组栈分配
#include<iostream>
using namespace std;

int a[1002][1002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++, a[x1][y2+1]--;
        a[x2+1][y1]--, a[x2+1][y2+1]++;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << " \n"[j == n];
        }
    }
    
    return 0;
}



/*
二维前缀和是一种以空间换时间的预处理技巧，用于快速计算二维数组中任意子矩阵的和。

核心原理

1. 定义
定义 prefix[i][j] 为从 (1,1) 到 (i,j) 围成的矩形中所有元素之和。通常下标从 1 开始，避免边界判断。

2. 递推公式（构建时）

```cpp
prefix[i][j] = prefix[i-1][j]          // 上面矩形
              + prefix[i][j-1]          // 左边矩形
              - prefix[i-1][j-1]         // 左上角被重复加，减掉
              + matrix[i][j];            // 加上当前格
```

理解：涂色画图法——合并两个矩形时，多出来的重叠部分要减去。

3. 查询公式（用时）
想求以 (x1, y1) 为左上角、(x2, y2) 为右下角的子矩阵和：

```cpp
sum = prefix[x2][y2]                    // 大矩形
      - prefix[x1-1][y2]                 // 去掉上面
      - prefix[x2][y1-1]                 // 去掉左边
      + prefix[x1-1][y1-1];               // 左上角被减了两次，加回
```

关键记忆点

· “加加减减”：构建时加左、加上、减左上、加当前；查询时大矩形、减上、减左、加回左上
· 下标1起：避免 i-1 或 j-1 越界，让公式统一
· 时间复杂度：构建 O(n*m)，查询 O(1)

代码模板

```cpp
int n, m;
vector<vector<int>> matrix(n+1, vector<int>(m+1, 0));
vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));

// 构建
for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) 
        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                       - prefix[i-1][j-1] + matrix[i][j];

// 查询 (x1,y1) 到 (x2,y2)
int query(int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1-1][y2] 
           - prefix[x2][y1-1] + prefix[x1-1][y1-1];
}
```

*/