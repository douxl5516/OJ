/*
    |�����������|
    |״̬ת��|
    |16/11/05ztx|
*/

/*
    ״̬ת��dp[i] = max{ 1.dp[j] + 1 };  j<i; a[j]<a[i];
    d[i]����i��β�������������
    ��i֮ǰ�� ÿ��a[j]<a[i]�� j��λ�õ������������+1���ֵ�Ƚ�
*/

void solve(){   // �ο���ս����������ž���;
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            } } }
}

/*
    �Ż�������
    dp[i]��ʾ����Ϊi+1�����������е���ĩβԪ��
    �ҵ���һ����dpĩβ���������
*/

    void solve() {
        for (int i = 0; i < n; ++i){
            dp[i] = INF;
        }
        for (int i = 0; i < n; ++i) {
            *lower_bound(dp, dp + n, a[i]) = a[i];  //  ����һ��ָ��
        }
        printf("%d\n", *lower_bound(dp, dp + n, INF) - dp;
    }

/*
    ����lower_bound()����һ�� iterator ��ָ����[first,last)��ǵ����������п��Բ���value���������ƻ�����˳��ĵ�һ��λ�ã������λ�ñ����һ����С��value��ֵ��
*/
