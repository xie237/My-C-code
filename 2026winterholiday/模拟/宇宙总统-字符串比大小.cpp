#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N=25;
string piao[N];
string piao2[N];

bool CompareBynum(string a, string b){
    // 防止递归到空字符串
    if(a.empty() || b.empty()){
        if(a.empty() && b.empty()) return false;  // 都空，相等
        return a.empty();  // a空则a更小
    }
    
    return a.size()<b.size() ? true : 
           a.size()>b.size() ? false : 
           (a[0]-'0'<b[0]-'0' ? true : 
            (a[0]-'0'>b[0]-'0' ? false : 
             CompareBynum(a.substr(1), b.substr(1))));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>piao[i];
        piao2[i]=piao[i];
    }

    
    sort(piao, piao+n, CompareBynum);
    int flag;
    for(int i=0;i<n;i++){
        if(piao2[i]==piao[n-1]) flag=i;
    }
    cout<< flag+1 <<endl<<piao[n-1];
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string maxVote = "";
    int maxIdx = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string vote;
        cin >> vote;
        if (maxVote.empty() ||
            vote.size() > maxVote.size() ||
            (vote.size() == maxVote.size() && vote > maxVote)) {
            maxVote = vote;
            maxIdx = i;
        }
    }

    cout << maxIdx << endl << maxVote << endl;
    return 0;
}
