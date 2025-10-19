#include <iostream>
#include <vector>
using namespace std;

int vSum(vector<int> arr) {
    int sum = 0;
    for(int x : arr) {
        sum += x;
    }

    return sum;
}

bool lexi(vector<int> a, vector<int> b) {
    int p1 = 0, p2 = 0;
    while(p1 < a.size() && p2 < b.size()) {
        if(a[p1] < b[p2]) return true;
        else if (a[p1] > b[p2]) return false;
        else {
            p1++;
            p2++;
        }
    }

    return false;

}

void merge(vector<pair<vector<int>, int>> &arr, int l, int mid, int r, string order) {
   
    int sL = mid - l + 1;
    int sR = r - mid;

    vector<pair<vector<int>, int>> L(sL), R(sR);
   
    

    for(int i = 0; i<sL; i++) {
        L[i] = arr[i + l];
    }

    for(int i = 0; i<sR; i++) {
        R[i] = arr[i + mid + 1];
    }

    
    

    int i = 0, j = 0, k = l;
    while(i < sL && j < sR){
        if(order == "sum") {
            if(L[i].second > R[j].second) {
                arr[k] = L[i];
                i++;
            }

            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        else if(order == "lexi") {
            if(lexi(L[i].first, R[j].first)) {
                arr[k] = L[i];
                i++;
            }

            else {
                arr[k] = R[j];
                j++;
            }
            k++;

        }

       
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

void quick_sort(vector<int> &arr, int l, int r) {
    if(l>=r) return;

    int pivot = arr[l + (r-l)/2];
    int i = l, j = r;
    while(i<j) {
        while(arr[i] > pivot) i++;
        while(arr[j] < pivot) j--;

        if(i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, l, j);
    quick_sort(arr, i, r);
}


void merge_sort(vector<pair<vector<int>, int>> &arr, int l, int r, string order) {
    if(l>=r) return;

    int mid = l + (r-l)/2;

    merge_sort(arr, l, mid, order);
    merge_sort(arr, mid+1, r, order);

    merge(arr, l, mid, r, order);
}

void sortByLexi(vector<pair<vector<int>, int>> &arr) {
    int l = 0, r = 0;
    for(int i = 0; i<arr.size(); i++) {
        if(i + 1 < arr.size() && arr[i].second == arr[i+1].second) {
            r++;
        }
        
        else {
            if(l != r) merge_sort(arr, l, r, "lexi");
            l = i+1;
            r = i+1;
        }


    }





}


int main() {
    vector<pair<vector<int>, int>> arr;

    int n, m, num;
    cin >> n >> m;

    for(int i = 0; i<n;i++) {
        vector<int> tmp;
        for(int j = 0; j<m; j++) {
            cin >> num;
            tmp.push_back(num);
        }
        arr.push_back(make_pair(tmp, vSum(tmp)));
    }



    merge_sort(arr, 0, n-1, "sum");
    //quick_sort(sums, 0, n-1);

    sortByLexi(arr);

  
    

    for(pair<vector<int>, int> x : arr) {
        for(int y : x.first) {
            cout << y << " ";
        }

        cout << endl;
    }

   
    

    



    return 0;
}