#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

const int Q=1e8+10;
vector<int>primes;
bitset<Q>notPrime;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin>>n>>q;

    //0和1不是素数
    notPrime[0] = notPrime[1] = true;

    //欧拉筛
    for(int i=2;i<=n;i++){
        if(!notPrime[i]) {
            primes.push_back(i);
        }

        for(int p : primes){
            if(i * p > n) break;
            notPrime[i * p] = true;
            if(i % p == 0) break; //灵魂代码
        }
    }

    while(q--){
        int k;
        cin>>k;
        cout<<primes[k-1]<<'\n';
    }
    return 0;
}