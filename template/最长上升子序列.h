/*
    |最长上升子序列|
    |状态转移|
    |16/11/05ztx|
*/

/*
    状态转移dp[i] = max{ 1.dp[j] + 1 };  j<i; a[j]<a[i];
    d[i]是以i结尾的最长上升子序列
    与i之前的 每个a[j]<a[i]的 j的位置的最长上升子序列+1后的值比较
*/

void solve(){   // 参考挑战程序设计入门经典;
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            } } }
}

/*
    优化方法：
    dp[i]表示长度为i+1的上升子序列的最末尾元素
    找到第一个比dp末尾大的来代替
*/

    void solve() {
        for (int i = 0; i < n; ++i){
            dp[i] = INF;
        }
        for (int i = 0; i < n; ++i) {
            *lower_bound(dp, dp + n, a[i]) = a[i];  //  返回一个指针
        }
        printf("%d\n", *lower_bound(dp, dp + n, INF) - dp;
    }

/*
    函数lower_bound()返回一个 iterator 它指向在[first,last)标记的有序序列中可以插入value，而不会破坏容器顺序的第一个位置，而这个位置标记了一个不小于value的值。
*/
