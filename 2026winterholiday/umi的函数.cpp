#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string x,y;
    cin>>n>>x>>y;
    string s;
    int i;
    for(i=0;i<x.length();i++){
        if(y[i]>x[i]) {cout<<-1;break;}
        if(x[i]>y[i])s.push_back(y[i]);
        else s.push_back('z');
    }
    if(i==x.length())cout<<s;
    return 0;
}
