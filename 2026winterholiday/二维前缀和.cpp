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