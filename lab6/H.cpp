#include <iostream>
using namespace std;

int main() {
    int n;
    char c, tar, res;
    cin >> n;
    char arr[n];
    for(int i = 0; i<n; i++) {
        cin >> c;
        arr[i] = c;
    }
    cin >> tar;

    res = arr[0];

    for(int i = 0; i<n; i++) {
        if(int(arr[i]) > int(tar)) {
            res = arr[i];
            break;
        }
    }

    cout << res;






    return 0;
}