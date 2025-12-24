#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n): parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
        return true;
    }

};

int main() {
    int n,m,x,y;

    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> res(n);
    vector<bool> on(n, false);

    DSU dsu(n);

    for(int i = 0; i<m; i++) {
        cin >> x >> y;
        x--; y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int cmp = 0;

    for(int i = n-1; i >= 1; i--) {
        on[i] = true;
        cmp++;

        for(int u : g[i]) {
            if(on[u]) {
                if(dsu.unite(i, u)) {
                    cmp--;
                }
            }
        }

        res[i-1] = cmp;

    }

    for(int x : res) {
        cout << x << endl;
    }
    
   






}
