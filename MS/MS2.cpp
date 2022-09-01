int solution(vector<int> &A, int M) {
    vector<int> dp(A.size());
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            dp[i] = 1;
            continue;
        }
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (abs(A[j] - A[i]) % M == 0) {
                if (dp[j] > temp)
                    temp = dp[j];
            }
        }
        if (temp == 0) {
            dp[i] = 1;
        } else {
            dp[i] = temp + 1;
        }
    }
    return dp[A.size() - 1];
}