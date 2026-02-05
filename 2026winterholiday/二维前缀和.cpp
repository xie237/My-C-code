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