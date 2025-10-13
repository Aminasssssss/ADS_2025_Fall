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

    int l = 0, r = n-1, mid;
    while(l<=r) {
        mid = (l+r)/2;

        if(int(arr[mid]) > int(tar)) {
           
            res = arr[mid];
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }
    }

    cout << res;






    return 0;
}