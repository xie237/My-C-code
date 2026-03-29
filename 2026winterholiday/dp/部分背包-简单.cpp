#include<iostream>
#include<algorithm>
using namespace std;

const int N=105;
const int T=1005;
struct coin{
    int weight, value;
};
coin coins[N];

bool Compare(coin a, coin b){
    double asingle = (double)a.value / a.weight ;
    double bsingle = (double)b.value / b.weight ;
    return asingle > bsingle;
}
int main(){

    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>coins[i].weight>>coins[i].value;
    }

    sort(coins, coins+n, Compare);
    double total_value=0;
    for(int i=0;i<n;i++){
        if(coins[i].weight <= t){
            total_value += coins[i].value;
            t -= coins[i].weight;
        }else {
            total_value += t * ((double)coins[i].value / coins[i].weight);
            break;
        }
        
    }

    printf("%.2lf", total_value);
    return 0;
}
