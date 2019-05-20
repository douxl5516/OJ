/*
    |Prim�㷨|
    |������ ����ͼ ����С������|
    |���Ż��棬ʱ�临�Ӷȣ�O(elgn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {
    int v, len;
    node(int v = 0, int len = 0) :v(v), len(len) {}
    bool operator < (const node &a)const {  // ������е�Ԫ���Զ��������С��������
        return len> a.len;
    }
};

vector<node> G[maxn];
int vis[maxn];
int dis[maxn];

void init() {
    for (int i = 0; i<maxn; i++) {
        G[i].clear();
        dis[i] = INF;
        vis[i] = false;
    }
}
int Prim(int s) {
    priority_queue<node>Q; // �������ȶ���
    int ans = 0;
    Q.push(node(s,0));  // ���������
    while (!Q.empty()) {
        node now = Q.top(); Q.pop();  // ȡ��������С�ĵ�
        int v = now.v;
        if (vis[v]) continue;  // ͬһ���ڵ㣬���ܻ�����2�λ�2�����϶��У�������һ������Ǻ�ʣ�µ���Ҫֱ��������
        vis[v] = true;  // ���һ��
        ans += now.len;
        for (int i = 0; i<G[v].size(); i++) {  // ��ʼ����
            int v2 = G[v][i].v;
            int len = G[v][i].len;
            if (!vis[v2] && dis[v2] > len) {
                dis[v2] = len;
                Q.push(node(v2, dis[v2]));  // ���µĵ������в�����
            }
        }
    }
    return ans;
}
