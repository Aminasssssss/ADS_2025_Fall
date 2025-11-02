#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));
    queue<pair<int,int>> q;

    int msh = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) q.push({i,j});
            if(arr[i][j] == 1) msh++;
        }
    }

    int minutes = 0;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    while(!q.empty() && msh > 0){
        int sz = q.size();
        while(sz > 0){
            int x = q.front().first, y = q.front().second; 
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x + dx[k], ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<m && ny<n && arr[nx][ny]==1){
                    arr[nx][ny] = 2;
                    q.push({nx,ny});
                    msh--;
                }
            }
            sz--;
        }
        minutes++;
    }

    if(msh > 0) cout << -1;
    else cout << minutes;

    return 0;
}