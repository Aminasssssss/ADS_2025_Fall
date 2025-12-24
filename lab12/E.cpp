#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long

struct Edge {int u, v, w; };

int main() {
    const LL INF = 4e18;
    int n;
    cin >> n;
    vector<Edge> edges;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            int w;
            cin >> w;
            if(w != 100000) {
                edges.push_back({i, j, w});
            }
        }
    }

    vector<LL> dist(n, INF);
    vector<int> parent(n, -1);
    int x = -1;
    dist[0] = 0;

    for(int i = 0; i< n; i++) {
        x = -1;
        for(auto [u, v, w] : edges) {
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
       
    }

    bool neg_cycle = false;
    for(auto [u, v, w] : edges) {
        if(dist[u] != INF && dist[u] + w < dist[v]) {
            neg_cycle = true;
            break;
        }
    }

    if(!neg_cycle) cout << "NO";

    else {
        int y = x;
        for(int i = 0; i<n; i++) {
            y = parent[y];
        }

        vector<int> cycle;
        int cur = y;
        do {
            cycle.push_back(cur+1);
            cur = parent[cur];
        } while(cur != y);
        cycle.push_back(y+1);
        
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl << cycle.size() << endl;
        for(int x : cycle) {
            cout << x << " ";
        }




    }







    return 0;
}