class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int mid = ( left + right ) / 2 ; 

            int cnt = 0 ; 
            for( int num : nums ){
                if( num <= mid ) cnt++;
            }

            if( cnt > mid ){
                right = mid ; 
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};

/*
模板1：找最小满足条件的（下界）
cpp

int l = 0, r = n - 1;  // 闭区间
while (l < r) {
    int mid = (l + r) / 2;  // 不加1
    if (check(mid)) r = mid;      // 满足条件，往左找
    else l = mid + 1;              // 不满足，往右找
}
// 结果：l 是第一个满足条件的

模板2：找最大满足条件的（上界）
cpp

int l = 0, r = n - 1;  // 闭区间
while (l < r) {
    int mid = (l + r + 1) / 2;  // 加1
    if (check(mid)) l = mid;      // 满足条件，往右找
    else r = mid - 1;              // 不满足，往左找
}
// 结果：l 是最后一个满足条件的

二、记忆口诀

找最小：mid 不加1，满足往左，不满足往右
找最大：mid 加1，满足往右，不满足往左

while (l < r) 退出时 l == r，所以返回 l 还是 r 都一样。

找左边	mid = (l+r)/2	l = mid+1 或 r = mid
找右边	mid = (l+r+1)/2	l = mid 或 r = mid-1
*/
