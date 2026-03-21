#include<iostream>
#include<cstring>

#define ll long long
using namespace std;

const int N=1e5+10;
const int M=1e5+10;
struct city{
    int a;//第i段铁路买纸质单程票需要的钱
    int b;//ic卡之后第i段需要的钱
    int c;//第i段铁路ic卡办理费用
};
city citys[N];
ll sequence[M];//城市拜访顺序
ll cnt[N];
ll diff[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll num;cin>>num;
        sequence[i] = num-1;
    }
    for(ll i=0;i<n-1;i++){
        cin>>citys[i].a>>citys[i].b>>citys[i].c;
    }

    //首先我来想一下，最优，不买ic最优是a元，买ic最优是b+c元 ，那么我要比较二者。
    ll sum=0;
    memset(cnt, 0, sizeof(cnt));
    for(ll i=0;i<m-1;i++){//m-1是铁路条数
        ll start = sequence[i];
        ll end = sequence[i+1];
        if( start > end ){ ll temp = start; start = end; end = temp; }
        diff[start]++; diff[end]--;
    }

    for(int i=0;i<n-1;i++){
        cnt[i] += cnt[i-1] + diff[i];
    }
    
    for(ll i=0;i<n-1;i++){
            if(citys[i].a * cnt[i] < citys[i].b * cnt[i] + citys[i].c){
                sum += ( cnt[i] * citys[i].a );
            }else {
                sum += ( citys[i].b * cnt[i] + citys[i].c ) ;
            }
    }
    
    cout<<sum;
    
    return 0;
}


//暴力解法
#include<iostream>
#include<cstring>

#define ll long long
using namespace std;

const int N=1e5+10;
const int M=1e5+10;
struct city{
    int a;//第i段铁路买纸质单程票需要的钱
    int b;//ic卡之后第i段需要的钱
    int c;//第i段铁路ic卡办理费用
};
city citys[N];
ll sequence[M];//城市拜访顺序
ll cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll num;cin>>num;
        sequence[i] = num-1;
    }
    for(ll i=0;i<n-1;i++){
        cin>>citys[i].a>>citys[i].b>>citys[i].c;
    }

    //首先我来想一下，最优，不买ic最优是a元，买ic最优是b+c元 ，那么我要比较二者。
    ll sum=0;
    memset(cnt, 0, sizeof(cnt));
    for(ll i=0;i<m-1;i++){//m-1是铁路条数
        ll start = sequence[i];
        ll end = sequence[i+1];
        if( start > end ){ ll temp = start; start = end; end = temp; }
        for(ll j=start;j<end;j++){
            cnt[j]++;
        }
    }

    for(ll i=0;i<n-1;i++){
            if(citys[i].a * cnt[i] < citys[i].b * cnt[i] + citys[i].c){
                sum += ( cnt[i] * citys[i].a );
            }else {
                sum += ( citys[i].b * cnt[i] + citys[i].c ) ;
            }
    }
    
    cout<<sum;
    
    return 0;
}