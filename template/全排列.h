/*
    |��1��n��ȫ����, ������|
    |16/11/05ztx, thanks to wangqiqi|
*/

void Pern(int list[], int k, int n) {   //  k��ʾǰk�����������ƶ�����n-kλ��
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        printf("\n");
    }else {
        for (int i = k; i < n; i++) {   //  ������������ƶ���������ȫ����
            swap(list[k], list[i]);
            Pern(list, k + 1, n);
            swap(list[k], list[i]);
        }
    }
}
