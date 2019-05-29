/*
    |������|
    |16/11/05ztx|
*/

typedef long long LL;   //  �����ݴ�С���������

LL powerMod(LL x, LL n, LL m) {
        LL res = 1;
        while (n > 0) {
                if (n & 1) //  �ж��Ƿ�Ϊ������������true
                        res = (res * x) % m;
                x = (x * x) % m;
                n >>= 1;    //  �൱��n /= 2;
        }
        return res;
}
