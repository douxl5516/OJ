/*
    |Dijkstra�㷨|
    |�����ڱ�ȨΪ��������ͼ��������ͼ|
    |��ӵ���Դ������������нڵ�����·|
    |�Ż��棺ʱ�临�Ӷ� O(elbn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {
    int v, len;
    node(int v = 0, int len = 0) :v(v), len(len) {}
    bool operator < (const node &a)const {  //  �����С��������
        return len > a.len;
    }
};

vector<node>G[maxn];
bool vis[maxn];
int dis[maxn];

void init() {
    for (int i = 0; i<maxn; i++) {
        G[i].clear();
        vis[i] = false;
        dis[i] = INF;
    }
}
int dijkstra(int s, int e) {
    priority_queue<node>Q;
    Q.push(node(s, 0)); //  ������в�����
    dis[s] = 0;
    while (!Q.empty()) {
        node now = Q.top();     //  ȡ����ǰ��С��
        Q.pop();
        int v = now.v;
        if (vis[v]) continue;   //  �����ǹ���, ֱ��continue
        vis[v] = true;
        for (int i = 0; i<G[v].size(); i++) {   //  ����
            int v2 = G[v][i].v;
            int len = G[v][i].len;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                Q.push(node(v2, dis[v2]));
            }
        }
    }
    return dis[e];
}
