/*
    |������ƥ������|
    |�ݹ�ʵ��|
    |16/11/05ztx|
*/

vector<int>G[maxn];
bool inpath[maxn];  //  ���
int match[maxn];    //  ��¼ƥ�����
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
            if (match[v] == -1 || findpath(match[v])) { // �ݹ�
                match[v] = k; // ��ƥ������ǡ�k���ӡ���
                return true;
            }
        }
    }
    return false;
}

void hungary() {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {  // mΪ��Ҫƥ��ġ����ӡ���
        memset(inpath, false, sizeof(inpath)); // ÿ�ζ�Ҫ��ʼ��
        if (findpath(i)) cnt++;
    }
    cout << cnt << endl;
}
