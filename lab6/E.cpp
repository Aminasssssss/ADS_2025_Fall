#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &row, int l, int r) {
    if(l>=r) {
        return;
    }

    int i = l;
    int j = r;
    int med = row[(l+r)/2];

    
    while(i<j) {
        while(row[i] > med) i++;
        while(row[j] < med) j--;

        if(i<=j) {
            swap(row[i], row[j]);
            i++;
            j--;
        }
    }

    quick_sort(row, l, j);
    quick_sort(row, i, r);

}

int main() {
    int n, m, num;
    cin >> n >> m;
    vector<vector<int>> matrix;
    vector<vector<int>> matrix2;

    for(int i = 0; i<n; i++) {
        vector<int> tmp;
        for(int j = 0; j<m; j++) {
            
            cin >> num;
            tmp.push_back(num);
        }
        matrix.push_back(tmp);
    }

   
    for(int i = 0; i<m; i++) {
        vector<int> tmp;
        for(int j = 0; j<n; j++) {
            
            tmp.push_back(matrix[j][i]);
        }
        matrix2.push_back(tmp);
    }



   int r = n-1;

    for(int i = 0; i<m; i++) {
        quick_sort(matrix2[i], 0, r);
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            
            cout << matrix2[j][i] << " ";
        }
        cout << endl;
    }

    
    

    



    return 0;
}