#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cur;
    int maxx;
    cin >> cur;
    maxx = cur;
    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        cur = max(a, cur + a);
        maxx = max(maxx, cur);
    }
    cout<<maxx;
    return 0;
}