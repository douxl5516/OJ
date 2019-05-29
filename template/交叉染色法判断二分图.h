/*
    |交叉染色法判断二分图|
    |16/11/05ztx|
*/

int bipartite(int s) {
    int u, v;
    queue<int>Q;
    color[s] = 1;
    Q.push(s);
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            v = G[u][i];
            if (color[v] == 0) {
                color[v] = -color[u];
                Q.push(v);
            }
            else if (color[v] == color[u])
                return 0;
        }
    }
    return 1;
}
