#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
vector<int> queens;  // queens[i] 表示第i行皇后在第几列
int cnt = 0;         // 解的总数
vector<vector<int>> solutions;  // 存储所有解（用于输出前3个）

// 检查第row行第col列是否能放皇后
bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        // 检查同一列
        if (queens[i] == col) return false;
        // 检查对角线（关键！）
        if (abs(queens[i] - col) == abs(i - row)) return false;
    }
    return true;
}

void dfs(int row) {
    // 找到一个完整解
    if (row == n) {
        cnt++;
        // 存储前3个解
        if (solutions.size() < 3) {
            solutions.push_back(queens);
        }
        return;
    }
    
    // 尝试当前行的每一列（注意：列号从1开始，符合题目要求）
    for (int col = 1; col <= n; col++) {
        if (check(row, col)) {
            queens[row] = col;  // 放置皇后
            dfs(row + 1);       // 递归下一行
            // 不需要显式回溯，queens[row]会被覆盖
        }
    }
}

int main() {
    cin >> n;
    queens.resize(n);
    
    dfs(0);
    
    // 输出前3个解
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << solutions[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    // 输出总解数
    cout << cnt << endl;
    
    return 0;
}
//固定行，遍历列

#include<iostream>
#include<cstring>
using namespace std;

const int N = 15;
bool matrix[N][N];
int n, count=0;

void printfSolution(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]) {cout<<j+1<<" "; break;}
        }
    }
    cout<<endl;
}

bool isSafe(int row, int col){
    //行不存在重复
    //列
    for(int i=0;i<row;i++) if(matrix[i][col]) return false;
    //为什么不检查下方？ 因为还没有放置皇后
    //左上对角线
    for(int i=row, j=col;i>=0 && j>=0;i--,j--) if(matrix[i][j]) return false;
    //右上对角线
    for(int i=row, j=col;i>=0 && j<n;i--,j++) if(matrix[i][j]) return false;
    return true;
}

void solveSqueen(int row){
    if(row == n){
        if(count<3) printfSolution();
        count++;
        return ;
    }

    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
            matrix[row][col]=true;
            solveSqueen(row+1);
            matrix[row][col]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    memset(matrix, false, sizeof(matrix));
    solveSqueen(0);
    cout<<count;
    return 0;
}
