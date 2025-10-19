#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<string> &arr, int l, int mid, int r) {
    int sL = mid - l + 1;
    int sR = r - mid;

    vector<string> L(sL), R(sR);

    for(int i = 0; i<sL; i++) {
        L[i] = arr[l + i];
    }

    for(int i = 0; i<sR; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while(i < sL && j < sR) {
        if(L[i].size() <= R[j].size()) {
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

void mergeS(vector<string> &arr, int l, int r) {
    if(l>=r) return;
    int mid = l + (r-l)/2;

    mergeS(arr, l, mid);
    mergeS(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main() {
    int n;
    string str;
    cin >> n;
    cin.ignore();
    vector<vector<string>> arr;
    for(int i = 0; i<n; i++) {
        vector<string> tmp;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while(ss >> str) {
            tmp.push_back(str);
        }

        arr.push_back(tmp);
        
    }


   
    for(int i = 0; i<n; i++) {
        mergeS(arr[i], 0, arr[i].size() - 1);
    }
    

    for(int i = 0; i<n; i++) {
        for(string x : arr[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    





    return 0;
}