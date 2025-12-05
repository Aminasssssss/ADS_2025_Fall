#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        int w;
        cin >> w;
        arr[i] = w;
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            g[i].push_back({j, arr[i]+arr[j]});
        }
    }




    const int INF = 1e9;
    vector<int> key(n, INF), parent(n, -1), used(n, 0);

    key[0] = 0;
    for(int i = 0; i<n; i++) {
        int v = -1;
        for(int j = 0; j<n; j++) {
            if(!used[j] && (v == -1 || key[j] < key[v])) {
                v = j;
            }
        }
        used[v] = 1;
        for(auto [to, w] : g[v]) {
            if(!used[to] && w < key[to]) {
                key[to] = w;
                parent[to] = v;
            }

        }
    }

    int total = 0;
    for(int w : key) total += w;

    cout << total;




    return 0;
}
