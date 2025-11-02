#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    
    int n,m, e1, e2, c1, c2;
    cin >> n >> m;
    vector<int> used(n, 0);
    bool cool = true;
    vector<int> dist(n, 0);
    queue<int> qu;
    vector<vector<int> > graph(n);

    for(int i = 0; i<m; i++) {
        cin >> e1 >> e2;
        graph[e1-1].push_back(e2-1);
    }
    cin >> c1 >> c2;
    c1--;
    c2--;

    for(int i = 0; i<n; i++) {
        if(used[i]) continue;
        qu.push(i);
        dist[i] = 0;
        used[i] = 1;
        while(!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            for(int x : graph[cur]) {
                if(!used[x]) {
                    used[x] = 1;
                    dist[x] = dist[cur] + 1;
                    qu.push(x);
                }
                
            }
        }
    }


    for(int i = c1+1; i<=c2; i++) {
        if(dist[i] == 0) {
            cool = false;
            break;
        }
    }

    if(cool) cout << "YES";
    else cout << "NO";
    cout << endl;

 




    return 0;
}