/*
    |����ģ��׳�|
    |������ģ��|
    |16/12/02ztx|
*/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int maxn = 100010;

int num[maxn], len;

/*
    ��mult�����У��ββ��֣�lenÿ�ε��ú������ᷢ���ı䣬n��ʾÿ��Ҫ���Ե��������շ��ص��ǽ���ĳ���
    tip: �׳˶�������֮ǰ��(n-1)!����n!
    ��ʼ��Init��������Ҫ����Ҫ����
*/

void Init() {
    len = 1;
    num[0] = 1;
}

int mult(int num[], int len, int n) {
    LL tmp = 0;
    for(LL i = 0; i < len; ++i) {
         tmp = tmp + num[i] * n;    //�����λ��ʼ���Ⱥ���ߵ�tmp��ʾ��ǰλ���ұߵ�tmp��ʾ��λ��֮ǰ����λ��
         num[i] = tmp % 10; //  �����ڶ�Ӧ������λ�ã���ȥ����λ���һλ��
         tmp = tmp / 10;    //  ȡ�������ٴ�ѭ��,��n����һ��λ�õĳ˻����
    }
    while(tmp) {    //  ֮��Ľ�λ����
         num[len++] = tmp % 10;
         tmp = tmp / 10;
    }
    return len;
}

int main() {
    Init();
    int n;
    n = 1977; // ��Ľ׳���
    for(int i = 2; i <= n; ++i) {
        len = mult(num, len, i);
    }
    for(int i = len - 1; i >= 0; --i)
        printf("%d",num[i]);    //  �����λ�������,���ݱȽ϶����printf���
    printf("\n");
    return 0;
}
