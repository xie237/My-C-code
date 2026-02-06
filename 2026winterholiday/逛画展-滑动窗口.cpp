#include<iostream>
#include<vector>
using namespace std;

const int M = 2005;
int cnt[M] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int left = 0, right = 0;
    int type=0, ansL=0,ansR=0;
    int minLen = n+1 ;
    for(right=0;right<n;right++){
        if(cnt[a[right]] == 0) type++;
        cnt[a[right]]++;
        
        while(type==m){
            if(right - left + 1 < minLen){
                minLen = right - left + 1;
                ansL = left;
                ansR = right;
            }

            cnt[a[left]]--;
            if(cnt[a[left]] == 0){
                type--;
            }
            left++;
        }
    }
    cout<<ansL+1<<" "<<ansR+1;
    
    return 0;
}


//在解答记录看到一位大佬的，虽然看不懂，还是留着备用吧，很牛逼

#include<bits/stdc++.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
using namespace std;
#define int long long
#define inline inline __attribute__((always_inline))
#define putchar putchar_unlocked
char*pc;
inline int read() {
	int ret = 0, sgn = 0, ch = *pc++;
	while (!isdigit(ch))sgn |= ch == '-', ch = *pc++;
	while (isdigit(ch))ret = ret * 10 + ch - '0', ch = *pc++;
	return sgn ? -ret : ret;
}
inline void write(int x) {
	bool neg = false;
	if (x < 0)neg = true, putchar('-');
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10;
	while (x);
	if (neg)while (top)putchar('0' - sta[--top]);
	else while (top)putchar('0' + sta[--top]);
}
int n, m, l, r, sum[2005], a[10000010], ans, ansl, ansr, num;
signed main() {
	struct stat state;
	fstat(0, &state);
	pc = (char*)mmap(0, state.st_size, 1, 2, 0, 0);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	l = 1;
	r = 1;
	num = 0;
	ans = n + 1;
	while (l <= r && r <= n + 1) {
		if (num < m) {
			r++;
			sum[a[r - 1]]++;
			if (sum[a[r - 1]] == 1) num++;
		} else {
			if (ans > (r - 1) - l + 1) {
				ans = (r - 1) - l + 1;
				ansl = l;
				ansr = r - 1;
			}
			sum[a[l]]--;
			if (sum[a[l]] == 0) num--;
			l++;
		}
	}
	write(ansl), putchar(' '), write(ansr);
	return 0;
}