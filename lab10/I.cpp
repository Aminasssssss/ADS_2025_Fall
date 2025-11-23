#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n,m;
vector<vector<int> > adj(100005);
bool visited[100005];
bool recStack[100005];
stack<int> result;


stack<int> res;

void DFS_topo(int v) {
    visited[v] = true;

    for(int i = 0; i<adj[v].size(); i++) {
        int u = adj[v][i];
        if(!visited[u]) DFS_topo(u);
    }

    result.push(v);
}

void topoSort() {
    for(int i = 0; i<n; i++) {
        visited[i] = 0;
    }

    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            DFS_topo(i);
        }
    }

    while(!result.empty()) {
        cout << result.top()+1 << " ";
        result.pop();
    }
    cout << endl;
}

bool DFS_cycle(int v) {
    visited[v]=true;
    recStack[v]=true;

    for(int i = 0; i<adj[v].size(); i++) {
        int u = adj[v][i];
        if(!visited[u]) {
            if(DFS_cycle(u)) return true;
        }

        else if(recStack[u]) return true;
    }

    recStack[v]=false;
    return false;

}

bool has_cycle() {
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
    int x, y;
    bool done = false;
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        cin >> x >> y;
        adj[x-1].push_back(y-1);
    }

    if(has_cycle()) {
        cout << "Impossible";
    }

    else {
        cout << "Possible" << endl;
        topoSort();
    }





    return 0;
}