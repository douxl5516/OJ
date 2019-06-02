/*
    |16/11/06ztx|
*/

node G[maxn];
int n;

double Cross(node a, node b) { // 叉积计算
    return a.x*b.y - a.y*b.x;
}


int main()
{
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &G[i].x, &G[i].y);
        double sum = 0;
        G[n].x = G[0].x;
        G[n].y = G[0].y;
        for (int i = 0; i < n; i++) {
                sum += Cross(G[i], G[i + 1]);
        }
        // 或者
            //for (int i = 0; i < n; i++) {
                //sum += fun(G[i], G[（i + 1）% n]);
            //}
        sum = sum / 2.0;
        printf("%.1f\n", sum);
    }
    system("pause");
    return 0;
}
