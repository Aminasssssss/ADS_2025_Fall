#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long

vector<LL> f1, f2;

void quick_sort(vector<LL> &list, LL l, LL r) {
    if(l >= r) {
        return;
    }

    int i = l;
    int j = r;

    LL med = list[(l+r)/2];

    while(i < j) {

        while(list[i] < med) {
            i++;
        }

        while(list[j] > med) {
            j--;
        }

        if(i <= j) {
            swap(list[i], list[j]);
            i++;
            j--;
        }

    }

    quick_sort(list, l, j);
    quick_sort(list, i, r);

}


int main() {
    LL n,m, num;
    vector<LL> result;

    cin >> n >> m;

    for(LL i = 0; i<n; i++) {
        cin >> num;
        f1.push_back(num);
    }
    
    for(LL i = 0; i<m; i++) {
        cin >> num;
        f2.push_back(num);
    }

    if(n == 0 || m == 0) {
        cout << "";
    }

    else {

        quick_sort(f1, 0, f1.size() - 1);
        quick_sort(f2, 0, f2.size() - 1);


        LL sz = max(n, m);
        LL p1 = 0, p2 = 0;

        while(true) {
            if(p1 > f1.size() - 1 || p2 > f2.size() - 1) {
                break;
            }

            if(f1[p1] > f2[p2]) {
                p2++;
            }

            else if(f1[p1] < f2[p2]) {
                p1++;
            }

            else {
                result.push_back(f1[p1]);
                p1++;
                p2++;
            }

        }


        if(result.empty()) cout << "";

        else {
            for(int i = 0; i<result.size(); i++) {
                cout << result[i] << " ";
            }
        }
    }       


    









    return 0;
}
