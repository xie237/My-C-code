#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    stack<int> sta;
    string s;
    cin >> s;
    
    int num = 0;
    for(char ch : s){
        if(ch == '@') break;
        
        if(ch >= '0' && ch <= '9'){
            num = num * 10 + (ch - '0');
        }
        else if(ch == '.'){
            sta.push(num);
            num = 0;
        }
        else {
            int b = sta.top(); sta.pop();
            int a = sta.top(); sta.pop();
            
            if(ch == '+') sta.push(a + b);
            else if(ch == '-') sta.push(a - b);
            else if(ch == '*') sta.push(a * b);
            else if(ch == '/') sta.push(a / b);
        }
    }
    
    cout << sta.top() << endl;
    return 0;
}