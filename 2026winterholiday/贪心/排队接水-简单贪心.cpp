#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct timee{
    int time,num;
};

const int N=1e6+5;
timee t[N];

bool compareByTime(timee a,timee b){
    if (a.time == b.time) return a.num < b.num;
    return a.time < b.time;
}

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i].time;
        t[i].num=i;
    }

    sort(t,t+n,compareByTime);

    for(int i=0;i<n;i++){
        cout<<t[i].num+1<<" ";
    }
    cout<<endl;
    
    long long totalWait = 0;
    long long currentWait = 0;
    
    for(int i=1;i<n;i++){
        currentWait += t[i-1].time;
        totalWait += currentWait;
    }
    
    double avgWait = (double)totalWait / n;
    printf("%.2f", avgWait);
    
    return 0;
}
