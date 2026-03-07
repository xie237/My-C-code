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
