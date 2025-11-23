#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, q, num, l1, l2, l3;
    cin >> n >> q;
    int arr[n][n];
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin >> num;
            arr[i][j] = num;
        }
    }

    for(int i = 0; i<q; i++) {
        cin >> l1 >> l2 >> l3;
        l1--;l2--;l3--;

        if(arr[l1][l2] == 0 || arr[l2][l3] == 0 || arr[l1][l3] == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;


    }



    return 0;
}