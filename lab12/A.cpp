#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

int main() {
    int n;
    cin >> n;

    vector<vector<LL>> dist(n, vector<LL>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;              
    }

    vector<bool> active(n, false);
    vector<LL> ans(n);

    for (int idx = 0; idx < n; idx++) {
        int v = order[idx];
        active[v] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][v] + dist[v][j] < dist[i][j]) {
                    dist[i][j] = dist[i][v] + dist[v][j];
                }
            }
        }

        LL cur = 0;
        for (int i = 0; i < n; i++) {
            if (!active[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!active[j]) continue;
                cur = max(cur, dist[i][j]);
            }
        }

        ans[idx] = cur;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}