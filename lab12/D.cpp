#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define f first
#define s second
#define LL long long

int main() {
    vector<pair<int, int> > p;
    int n, res = 0;
    cin >> n;
    vector<int> xa(n), ya(n);
    for(int i = 0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        xa[i] = x, ya[i] = y;

    }


    vector<vector<pair<int, int> >> g(n);


    const LL INF = 1e10; 
    vector<bool> u(n);
    vector<LL> dist(n, INF);

    dist[0] = 0;
    for(int i = 0; i<n; i++) {
        int v = -1;
        for(int j = 0; j<n; j++) {
            if(!u[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        u[v] = true;
        for(int j = 0; j<n; j++) {
            if(u[j] || j == v) continue;
            LL w = abs(xa[v] - xa[j]) + abs(ya[v] - ya[j]);
            LL mx = max(dist[v], w);
            if(mx < dist[j]) dist[j] = mx;
        }
    }



    cout << dist[n-1];





    return 0;
}