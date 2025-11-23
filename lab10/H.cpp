#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<pair<int, int>, int> used;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy ={0, 0, 1, -1};



    queue<pair<int, int> > qu;
    int n, m, cnt = 0; char c;
    cin >> n >> m;
    char arr[n][m];
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> c;
            arr[i][j] = c;
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
           
            if(used[{i, j}] == 0 && arr[i][j] == '1') {
                cnt++;
                used[{i, j}] = 1;
                qu.push(make_pair(i, j));
                while(!qu.empty()) {
                    pair<int, int> cur = qu.front();
                    qu.pop();

                    for(int i = 0; i<4; i++) {
                        int x = cur.first + dx[i], y = cur.second + dy[i];
                       
                        if(used[{x, y}] == 0 && arr[x][y] == '1' && x >= 0 && x < n && y >= 0 && y < m){
                            used[{x, y}] = 1;
                            qu.push({x, y});
                        }
                    }
                }

            }
        }
    }

    cout << cnt;


    return 0;
}