//2026.4.6 21:18
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

int n;
const int N = 25;
string words[N];
int visited[N];
int ans = 0;

void dfs(string word){
    ans = max(ans, int(word.size()));

    for(int i=0;i<n;i++){
        if(visited[i] >= 2) continue;
        for(int j=1;j<min(int(word.size()),int(words[i].size()));j++){
            if(word.substr(word.size() - j) == words[i].substr(0,j)){
                visited[i]++;
                string newword = word + words[i].substr(j);
                dfs(newword);
                visited[i]--;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        cin>>words[i];
    }

    char startch;
    cin>>startch;

    for(int i=0;i<n;i++){
        if(words[i][0] == startch){
            visited[i]++;
            dfs(words[i]);
            visited[i]--;
        }
    }

    cout<<ans;
    return 0;
}

#include <iostream>
using namespace std;

const int N = 30;
int n, vis[N], ans;
string s[N];
char c;

void dfs(const string &tmp) {
    ans = max(ans, int(tmp.size()));
    for (int i = 1; i <= n; ++i) {
        if (vis[i] >= 2) continue;
        for (int j = 1; j < min(tmp.size(), s[i].size()); ++j)
            if (tmp.substr(tmp.size() - j) == s[i].substr(0, j)) {
                ++vis[i];
                dfs(tmp + s[i].substr(j));
                --vis[i];
            }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    cin >> c;
    for (int i = 1; i <= n; ++i) if (s[i][0] == c) {
        ++vis[i];
        dfs(s[i]);
        --vis[i];
    } cout << ans << '\n';
    return 0;
}



//错误
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int n;
const int N = 25;
string words[N];
int len = 0;
int used[N];
int overlap[N][N];

int getOverlap(string &a, string &b){
    int lenA = a.length();
    int lenB = b.length();

    for(int i = min(lenA, lenB) - 1; i >= 1; i--){
        if(a.substr(lenA - i) == b.substr(0, i)){
            return i;
        }
    }
    return 0;
}

void dfs(int last, int length){
    len = max(len, length);
    for(int i=0;i<n;i++){
        if(used[i] < 2 && overlap[last][i] > 0) {  // 使用次数<2 且 能接上
             used[i]++;
             dfs(i, length + words[i].size() - overlap[last][i]);
             used[i]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    memset(used, 0, sizeof(used));
    for(int i=0;i<n;i++){
        cin>>words[i];
    }

    char startch;
    cin>>startch;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            overlap[i][j] = getOverlap(words[i], words[j]);
        }
    }

    for(int i=0;i<n;i++){
        if(words[i][0] == startch){
            used[i]++;
            dfs(i, words[i].size());
            used[i]--;
        }
    }

    cout<<len;
    return 0;
}
