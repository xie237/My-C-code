#include<iostream>
#include<unordered_map>
#include<string>
using namspace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        string c=a+b;
        mp[c]++;
    }

    for(int i=0;i<n;i++){
        
    }
    return 0;
}

//基本类型（int、char、string等）自带哈希，可以直接放 unordered_map；复杂类型（pair、struct等）没有默认哈希，要用 map 或手动转成字符串。
//简单类型直接放，复杂类型用 map，或者拼接字符串！
//map是有序的（红黑树），unordered_map是无序的（哈希表）
