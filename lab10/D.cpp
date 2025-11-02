#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int BIG = 1000000000;

vector<int> g[5005];
int d[5005];
bool red[5005];
queue<int> q;

void do_bfs() {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int x : g[u]) {
            if (d[x] > d[u] + 1) {
                d[x] = d[u] + 1;
                q.push(x);
            }
        }
    }
}

int main() {
    
    
    int n, m, qry;
    cin >> n >> m >> qry;
    
    for (int i = 1; i <= n; i++) {
        d[i] = BIG;
        red[i] = false;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    while (qry--) {
        int t, v;
        cin >> t >> v;
        
        if (t == 1) {
            if (!red[v]) {
                red[v] = true;
                d[v] = 0;
                q.push(v);
            }
        } else {
            do_bfs();
            if (d[v] == BIG) {
                cout << "-1\n";
            } else {
                cout << d[v] << "\n";
            }
        }
    }
    
    return 0;
}