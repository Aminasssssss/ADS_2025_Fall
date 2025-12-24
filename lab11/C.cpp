#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<pair<int, int> >> g(n);
    for(int i = 0; i<m; i++) {
        string type;
        int a,b,c;
        cin >> type >> a >> b >> c;
        a--; b--;
        if(type == "small") {
            c *= y;
        }

        else if (type == "big") {
            c *= x;
        }

        else {
            c = min(c*y, c*x);
        }

        g[a].push_back({b, c});
        g[b].push_back({a, c});
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