#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, p;
    cin>>a>>b>>p;

/*
结果，任何数的0次方仍未1
加法单位元是0：任何数 + 0 = 本身
乘法单位元是1：任何数 × 1 = 本身
*/
    long long ans = 1; 
    long long base = a;
    long long exponent = b;

    while(exponent > 0){
        if(exponent % 2 == 1){
            ans = ans * base % p;
        }

        base = base * base % p;
        exponent /= 2;
    }

    cout<<a<<'^'<<b<<" mod "<<p<<"="<<ans;
    return 0;
}

/*
自己的理解：
首先一个原则做完任何事要取模防止溢出。然后指数为0才能停，质数为奇数，要先拿一个自己出来呈上，然剩下的组成偶数次幂，然后不断的从偶数次幂中取2，让底数平方增长
*/