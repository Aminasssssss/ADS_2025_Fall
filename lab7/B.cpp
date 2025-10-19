#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    
    int sL = mid - l + 1;
    int sR = r - mid;
    vector<int> L(sL), R(sR);

    for(int i = 0; i < sL; i++) {
        L[i] = (arr[l + i]);
    }

    for(int i = 0; i < sR; i++) {
        R[i] = (arr[i + mid + 1]);
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

void merge_sort(vector<int> &arr, int l, int r) {
    if(l >= r) return;

    int mid = l + (r-l)/2;

    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
    
}

int main() {
    
    
    
    int n, m, num;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++) {
       
        cin >> num;
        arr.push_back(num);
        
        
    }

    cin >> m;
    for(int i = 0; i<m; i++) {
       
        cin >> num;
        arr.push_back(num);
        
        
    }

    
    merge_sort(arr, 0, arr.size() - 1);
    

    for(int x : arr) {
        cout << x << " ";
    }

    




    return 0;
}