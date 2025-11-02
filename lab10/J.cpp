#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, e1, e2;
    cin >> n >> m;
    vector<vector<int> > graph(n);
    vector<bool> used(n, false);
    
    for(int i = 0; i < m; i++) {
        cin >> e1 >> e2;
        graph[e1-1].push_back(e2-1);
        graph[e2-1].push_back(e1-1);
    }

    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        
        queue<int> qu;
        vector<int> component;
        qu.push(i);
        used[i] = true;
        component.push_back(i);
        
        while(!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            for(int x : graph[cur]) {
                if(!used[x]) {
                    used[x] = true;
                    qu.push(x);
                    component.push_back(x);
                }
            }
        }
        
        int root = i;
        for(int node : component) {
            if(node < root) root = node;
        }
        
        vector<int> children_count(n, 0);
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        
        queue<int> q2;
        q2.push(root);
        visited[root] = true;
        
        while(!q2.empty()) {
            int cur = q2.front();
            q2.pop();
            for(int x : graph[cur]) {
                if(!visited[x]) {
                    visited[x] = true;
                    parent[x] = cur;
                    children_count[cur]++;
                    q2.push(x);
                }
            }
        }
        
        cnt++;
        for(int node : component) {
            if(node != root && parent[node] != -1) {
                if(children_count[node] > children_count[parent[node]]) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}