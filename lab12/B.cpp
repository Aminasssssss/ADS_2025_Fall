#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



using ll = long long;
const ll INF = 1e18;
vector<ll> dijkstra(int s, const vector<vector<pair<int, int>>> &g, int n) {
    vector<ll> d(n, INF);
    vector<char> used(n, false);

    d[s] = 0;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto[len, v] = pq.top();
        pq.pop();

        if (used[v])
            continue;

        used[v] = true;

        for (auto[to, len] : g[v]) {
            if (!used[to] && d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }

    return d;
}
// ---------------------------------------------------------------------------

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected
    }

    int s, t1, t2, g;
    cin >> s >> t1 >> t2 >> g;
    s--; t1--; t2--; g--;

    vector<ll> dist_s  = dijkstra(s, graph, n);
    vector<ll> dist_t1 = dijkstra(t1, graph, n);
    vector<ll> dist_t2 = dijkstra(t2, graph, n);

    ll ans = INF;

    if (dist_s[t1] < INF && dist_t1[t2] < INF) {
        vector<ll> d2 = dijkstra(t2, graph, n);
        if (d2[g] < INF)
            ans = min(ans, dist_s[t1] + dist_t1[t2] + d2[g]);
    }

    // s -> t2 -> t1 -> g
    if (dist_s[t2] < INF && dist_t2[t1] < INF) {
        vector<ll> d1 = dijkstra(t1, graph, n);
        if (d1[g] < INF)
            ans = min(ans, dist_s[t2] + dist_t2[t1] + d1[g]);
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
