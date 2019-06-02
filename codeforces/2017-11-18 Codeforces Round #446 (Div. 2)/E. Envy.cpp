#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from, to, weight, id;
    edge() {}
    edge(int a, int b, int c, int d) { from = a, to = b, weight = c, id = d; }
};

struct query {
    int id;
    vector <int> vals;
    query() {}
    query(int x) { id = x; vals.clear(); }
};

int n, m, q;
edge edges[500005];
vector <int> bucket[500005];
vector <int> queries[500005];
vector <query> toAnswer[500005];
int ans[500005];

inline int get_w(int x) { return edges[x].weight; }
bool cmp_edge(int a, int b) { return edges[a].weight < edges[b].weight; }

int dad[500005];
map <int, int> changed;

int anc(int u) {
    if (dad[u] == u) return u;
    if (changed.find(u) == changed.end()) changed[u] = dad[u];
    dad[u] = anc(dad[u]);
    return dad[u];
}
bool join(int u, int v) {
    u = anc(u), v = anc(v);
    if (u == v) return 0;
    if (changed.find(u) == changed.end()) changed[u] = dad[u];
    dad[u] = v;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = edge(u, v, w, i);
        bucket[w].push_back(i);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int sz; cin >> sz;
        queries[i].assign(sz, 0);
        for (int j = 0; j < sz; ++j) {
            cin >> queries[i][j];
            --queries[i][j];
        }
        sort(queries[i].begin(), queries[i].end(), cmp_edge);
        for (int j = 0; j < sz; ++j) {
            if (j == 0 || get_w(queries[i][j]) != get_w(queries[i][j-1])) toAnswer[get_w(queries[i][j])].push_back(query(i));
            toAnswer[get_w(queries[i][j])].back().vals.push_back(queries[i][j]);
        }
        ans[i] = 1;
    }

    for (int i = 1; i <= n; ++i) dad[i] = i;
    for (int w = 1; w <= 500000; ++w) {
        for (auto X: toAnswer[w]) if (ans[X.id]) {
            changed.clear();
            for (auto e: X.vals) if (!join(edges[e].from, edges[e].to)) {
                ans[X.id] = 0;
                break;
            }
            for (auto e: changed) dad[e.first] = e.second;
        }
        for (auto e: bucket[w]) join(edges[e].from, edges[e].to);
    }
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "YES" : "NO") << '\n';
}
