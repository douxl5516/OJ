/*
    |求解最大匹配问题|
    |dfs实现|
    |16/11/05ztx|
*/

int v1, v2;
bool Map[501][501];
bool visit[501];
int link[501];
int result;

bool dfs(int x)  {
    for (int y = 1; y <= v2; ++y)  {
        if (Map[x][y] && !visit[y])  {
            visit[y] = true;
            if (link[y] == 0 || dfs(link[y]))  {
                link[y] = x;
                return true;
            } } }
    return false;
}


void Search()  {
    for (int x = 1; x <= v1; x++)  {
        memset(visit,false,sizeof(visit));
        if (dfs(x))
            result++;
    }
}
