#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<bool>> g;

int bfs(bool use_trains) {
    vector<int> dist(n, INF);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to = 0; to < n; ++to) {
            if (to == v) continue;

            bool ok = use_trains ? g[v][to] : !g[v][to];
            if (ok && dist[to] == INF) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return dist[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u][v] = g[v][u] = true;
    }

    int train_dist = bfs(true);
    int road_dist  = bfs(false);

    if (train_dist == INF || road_dist == INF) {
        cout << -1 << '\n';
    } else {
        cout << max(train_dist, road_dist) << '\n';
    }

    return 0;
}