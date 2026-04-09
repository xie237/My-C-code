#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int a, b, c, k;
        cin>>a>>b>>c>>k;

        for(int i=0;i<k;i++){
            int aa = (b + c) / 2;
            int bb = (a + c) / 2;
            int cc = (a + b) / 2;

            a = aa, b = bb, c = cc;
            if(a == b && b == c) break;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}
