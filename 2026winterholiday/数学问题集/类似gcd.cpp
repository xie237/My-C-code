#include<iostream>
using namespace std;

long long solve(long long a, long long b){
    if(a==0 || b==0) return 0;
    if(a<b){long long temp = a; a = b; b = temp;}//始终保持a大于b
    return 4 * b * (a / b) + solve(b, a % b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x, y;
    cin>>x>>y;

    cout<<solve(x, y);
    return 0;
}