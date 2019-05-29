/*
    |求解最大匹配问题|
    |递归实现|
    |16/11/05ztx|
*/

vector<int>G[maxn];
bool inpath[maxn];  //  标记
int match[maxn];    //  记录匹配对象
void init()
{
    memset(match, -1, sizeof(match));
    for (int i = 0; i < maxn; ++i) {
        G[i].clear();
    }
}
bool findpath(int k) {
    for (int i = 0; i < G[k].size(); ++i) {
        int v = G[k][i];
        if (!inpath[v]) {
            inpath[v] = true;
            if (match[v] == -1 || findpath(match[v])) { // 递归
                match[v] = k; // 即匹配对象是“k妹子”的
                return true;
            }
        }
    }
    return false;
}

void hungary() {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {  // m为需要匹配的“妹子”数
        memset(inpath, false, sizeof(inpath)); // 每次都要初始化
        if (findpath(i)) cnt++;
    }
    cout << cnt << endl;
}
