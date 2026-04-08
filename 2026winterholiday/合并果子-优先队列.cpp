#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>>heap;//小顶堆
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        heap.push(a);
    }

    int ans=0;
    while(heap.size()>1){
        int a=heap.top(); heap.pop();
        int b=heap.top(); heap.pop();
        int sum = a+b;
        ans += sum;
        heap.push(sum);
    }

    cout<<ans;
    return 0;
}

/*
堆的操作	priority_queue的操作
建堆	priority_queue<int> pq;
插入元素	pq.push(x);
取堆顶（最小/最大）	pq.top();
删除堆顶	pq.pop();
堆大小	pq.size();
判空	pq.empty();
*/
