#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<vector<int> > graph;

vector<int> distance(int sz, int s) {
    vector<int> result(sz);
    vector<int> used(sz);
    for(int i = 0; i<sz; i++) {
        result[i] = -1;
    }
    result[s]=0;
    used[s] = 1;
    queue<int> qu;
    qu.push(s);

    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        for(int x : graph[cur]) {
            if(!used[x]) {
                result[x] = result[cur] + 1;
                used[x] = 1;
                qu.push(x);
            }
        }
    }

    return result;
}


int main() {
    int n, num, sz = 0, a, b;
    cin >> n;
    for(int i = 0; i<n; i++) {
        vector<int> tmp;
        for(int j = 0; j<n; j++) {
            cin >> num;
            if(num == 1) {
                sz++;
                tmp.push_back(j);
            }
        }
        graph.push_back(tmp);
    }

    cin >> a >> b;
    vector<int> dist = distance(sz, a-1);
    cout << dist[b-1];



    return 0;
}