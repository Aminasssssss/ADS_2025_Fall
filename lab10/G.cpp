#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph(501);
bool visited[501];
bool recStack[501];
int n;

bool DFS_cycle(int v) {
    if(v == -1) return false;
    visited[v] = true;
    recStack[v] = true;

    for(int i = 0; i<graph[v].size(); i++) {
        int u = graph[v][i];

        if(!visited[u]) {
            if(DFS_cycle(u)) return true;
        }

        else if(recStack[u]) {
            return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool hasCycle() {
    for(int i = 0; i<n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            if(DFS_cycle(i)) return true;
        }
    }

    return false;
}



int main() {
    int m, x, y;
    bool done = false;
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<graph[i].size(); j++) {
            int tmp = graph[i][j];
            graph[i][j] = -1;
            if(!hasCycle()) {
                done = true;
                break;
            }
            graph[i][j] = tmp;
        }

        if(done) break;
    }

    if(done) cout << "YES";
    else cout << "NO";








    return 0;
}