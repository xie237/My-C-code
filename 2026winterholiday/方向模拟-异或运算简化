#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct person{
    int face;
    string job;
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<person>number(n);
    
    for(int i=0;i<n;i++){
        cin>>number[i].face>>number[i].job;
    }

    int current = 0;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(number[current].face ^ a == 0){
            current = (current-b)%n;
            if(current<0) current+=n;
        }else{
            current = (current+b)%n;
        }
    }

    cout<<number[current].job;
    
    return 0;
}