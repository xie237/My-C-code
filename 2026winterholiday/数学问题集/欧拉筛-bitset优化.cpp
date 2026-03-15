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
            if(i % p == 0) break; 
/*
灵魂代码，确保了每个合数只被它的最小质因子筛掉一次
这就是欧拉筛的精妙之处：对于每个 i，只乘到它的最小质因子为止。这样保证了每个合数 n 都会在 i = n / (n的最小质因子) 时被筛掉恰好一次。
*/
        }
    }

    while(q--){
        int k;
        cin>>k;
        cout<<primes[k-1]<<'\n';
    }
    return 0;
}