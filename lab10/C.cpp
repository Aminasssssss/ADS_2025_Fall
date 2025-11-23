#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#define LL long long

int main() {
    queue<LL> ops;
    unordered_map<LL, LL> dist;
    unordered_map<LL, LL> path;

    LL a, b, res;
    cin >> a >> b;
    LL mx = max(a, b)*2 + 5;
    
    dist[a] = 0;
    path[a] = -1;
    ops.push(a);
    while(!ops.empty()) {
        int cur = ops.front();
        ops.pop();
        
        if(cur*2 < mx && dist.count(cur*2) == 0) {
            dist[cur*2] = dist[cur] + 1;
            path[cur*2] = cur;
            ops.push(cur*2); 
        }

        if(cur-1 >= 0 && dist.count(cur-1) == 0) {
            dist[cur-1] = dist[cur] + 1;
            path[cur-1] = cur;
            ops.push(cur-1);
        }
    }

    cout << dist[b] << endl;

    vector<LL> pth;
    for(LL i = b; i != -1; i = path[i]) {
        pth.push_back(i);
    }
    

    for(int i = pth.size()-2; i>=0; i--) {
        cout << pth[i] << " ";
    }






    return 0;
}