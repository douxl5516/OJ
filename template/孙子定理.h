/*
    |16/11/06ztx|
*/

int CRT(int a[],int m[],int n)  {
    int M = 1;
    int ans = 0;
    for(int i=1; i<=n; i++)
        M *= m[i];
    for(int i=1; i<=n; i++)  {
        int x, y;
        int Mi = M / m[i];
        extend_Euclid(Mi, m[i], x, y);
        ans = (ans + Mi * x * a[i]) % M;
    }
    if(ans < 0) ans += M;
    return ans;
}

void extend_Euclid(int a, int b, int &x, int &y)  {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
