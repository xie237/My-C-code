#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 125;
int matrix[N][N];
int prefix[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    memset(prefix, 0, sizeof(prefix));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];

            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
        }
    }
    
    int max_matrix = -1e9;
    for(int x1 = 1;x1 <= n;x1++){
        for(int y1 = 1;y1 <= n;y1++){
            for(int x2 = x1;x2 <= n;x2++){
                for(int y2 = y1;y2 <= n;y2++){
                    int sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
                    max_matrix = max(max_matrix, sum);
                }
            }
        }
    }

    cout<<max_matrix;
    return 0;
}


//3重循环-deepseek

#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

const int N = 125;
int matrix[N][N];
int colSum[N];  // 存储当前上下边界之间，每一列的和

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    
    int max_sum = -1e9;
    
    // 枚举上边界
    for(int top = 1; top <= n; top++){
        memset(colSum, 0, sizeof(colSum));  // 重置列和数组
        
        // 枚举下边界（从上边界开始往下扩展）
        for(int bottom = top; bottom <= n; bottom++){
            // 将当前行加到列和中
            for(int col = 1; col <= n; col++){
                colSum[col] += matrix[bottom][col];
            }
            
            // 对 colSum 数组求最大子段和（Kadane算法）
            int current_sum = 0;
            int best_sum = INT_MIN;
            
            for(int col = 1; col <= n; col++){
                current_sum = max(colSum[col], current_sum + colSum[col]);
                best_sum = max(best_sum, current_sum);
            }
            
            max_sum = max(max_sum, best_sum);
        }
    }
    
    cout << max_sum << endl;
    return 0;
}
