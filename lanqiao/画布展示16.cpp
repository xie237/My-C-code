#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
long long value[N];

long long calculate(long long a, long long b){
    return abs(a * a - b * b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }

    sort(value, value+n);
    
    long long current_sum = 0;
    for(int i = 0; i < m - 1; i++){
        current_sum += calculate(value[i], value[i + 1]);
    }
    
    long long min_l = current_sum;

    for(int i = 1; i <= n - m; i++){
        current_sum -= calculate(value[i-1], value[i]);
        current_sum += calculate(value[i+m-2], value[i+m-1]);
        
        if(current_sum < min_l){
            min_l = current_sum;
        }
    }

    cout<<min_l;
    return 0;
}
