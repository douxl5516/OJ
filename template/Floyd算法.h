/*
    |Floyd�㷨|
    |���������·�㷨|
    |��ͼ�������������̾�����㷨|
*/

for (int i = 0; i < n; i++) {   //  ��ʼ��Ϊ0
    for (int j = 0; j < n; j++)
        scanf("%lf", &dis[i][j]);
}
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
