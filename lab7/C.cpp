#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    int sL = mid - l + 1;
    int sR = r - mid;

    vector<int> L(sL), R(sR);

    for(int i = 0; i<sL; i++) {
        L[i] = arr[l + i];
    }

    for(int i = 0; i<sR; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while(i < sL && j < sR) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < sL) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < sR) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeS(vector<int> &arr, int l, int r) {
    if(l>=r) return;
    int mid = l + (r-l)/2;

    mergeS(arr, l, mid);
    mergeS(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main() {
    int n,m, num;

    cin >> n >> m;
    
    vector<int> fst, scnd, rslt;
    for(int i = 0; i<n; i++) {
        cin >> num;
        fst.push_back(num);
    }

    for(int i = 0; i<m; i++) {
        cin >> num;
        scnd.push_back(num);
    }

    mergeS(fst, 0, n-1);
    mergeS(scnd, 0, m - 1);

    int p1 = 0, p2 = 0;
    
    while(p1 < n && p2 < m) {
        if(fst[p1] > scnd[p2]) {
            p2++;
        }

        else if(fst[p1] < scnd[p2]) {
            p1++;
        }
        
        else {
            rslt.push_back(fst[p1]);
            p1++;
            p2++;
        }
    }

    if(rslt.size() == 0) {
        cout << "";
    }

    else {
        for(int x : rslt) {
            cout << x << " ";
        }
    }







    return 0;
}
