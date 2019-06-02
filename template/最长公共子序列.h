/*
    |求最长公共子序列|
    |递推形式|
    |16/11/05ztx|
*/

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            } } }
}
