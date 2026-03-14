#include<iostream>
using namespace std;

bool isPrime(int num){
    if(num<2) return false;
    if(num==2) return true;
    if(num%2==0) return false;
    for(int i=3;i*i<=num;i+=2){  // 可以i+=2，只检查奇数
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    // 1位回文质数（注意：1不是质数，从2开始）
    for(int i=2;i<=9;i++){  // 从2开始，1不是质数
        if(i>=a && i<=b && isPrime(i)) cout<<i<<'\n';
    }

    // 2位：只有11
    if(11>=a && 11<=b) cout<<11<<'\n';
    
    // 3位回文质数
    for(int i=1;i<=9;i+=2){  // 首位奇数
        for(int j=0;j<=9;j++){
            int p = 100*i + 10*j + i;
            if(p>=a && p<=b && isPrime(p)) {
                cout<<p<<'\n';
            }
        }
    }

    // 4、6、8位偶数位回文数都不是质数（除了11），跳过
    
    // 5位回文质数
    for(int i=1;i<=9;i+=2){  // 首位奇数
        for(int j=0;j<=9;j++){      // 第二位可以是0
            for(int k=0;k<=9;k++){  // 中间位可以是0
                int p = 10000*i + 1000*j + 100*k + 10*j + i;
                if(p>=a && p<=b && isPrime(p)) {
                    cout<<p<<'\n';
                }
            }
        }
    }

    // 7位回文质数
    for(int i=1;i<=9;i+=2){  // 首位奇数
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int h=0;h<=9;h++){
                    int p = 1000000*i + 100000*j + 10000*k + 1000*h + 100*k + 10*j + i;
                    if(p>=a && p<=b && isPrime(p)){
                        cout<<p<<'\n';
                    }
                }
            }
        }
    }
    
    return 0;
}