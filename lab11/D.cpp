#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int> >> g(n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            int w;
            cin >> w;
                g[i].push_back({j, w});
        }
    }

    const int INF = 1e9;
    vector<int> dist(n, INF), used(n, 0);

    dist[0] = 0;
    for(int i = 0; i<n; i++) {
        int v = -1;
        for(int j = 0; j<n; j++) {
            if(!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        used[v] = 1;
        for(auto [to, w] : g[v]) {
            if(!used[to] && w < dist[to]) {
                dist[to] = w;
            }
        }
    }

    int sum = 0;
    for(int x : dist) {
        sum += x;
    }

    cout << sum;

    




    return 0;
}