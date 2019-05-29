/*
    |kmp算法|
    |字符串匹配|
    |17/1/21ztx|
*/

void getnext(char str[maxn], int nextt[maxn]) {
    int j = 0, k = -1;
    nextt[0] = -1;
    while (j < m) {
        if (k == -1 || str[j] == str[k]) {
            j++;
            k++;
            nextt[j] = k;
        }
        else
            k = nextt[k];
    }
}

void kmp(int a[maxn], int b[maxn]) {
    int nextt[maxm];
    int i = 0, j = 0;
    getnext(b, nextt);
    while (i < n) {
        if (j == -1 || a[i] == b[j]) { // 母串不动，子串移动
            j++;
            i++;
        }
        else {
            // i不需要回溯了
            // i = i - j + 1;
            j = nextt[j];
        }
        if (j == m) {
            printf("%d\n", i - m + 1); // 母串的位置减去子串的长度+1
            return;
        }
    }
    printf("-1\n");
}
