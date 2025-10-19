#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void merge(vector<pair<pair<string,string>, double>> &arr, int l, int mid, int r, string order) {
    int sL = mid - l + 1;
    int sR = r - mid;

    vector<pair<pair<string,string>,double>> L(sL), R(sR);

    for(int i = 0; i<sL; i++) {
        L[i] = arr[i + l];
    }

    for(int i = 0; i<sR; i++) {
        R[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = l;
    while(i<sL && j<sR) {
        if(order == "gpa") {
            if(L[i].second < R[j].second) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
        }

        else if(order == "last") {
            if(L[i].first.first < R[j].first.first) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
        }

        else if(order == "first") {
            if(L[i].first.second < R[j].first.second) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
        }

        k++;

    }

    while(i<sL) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<sR) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeS(vector<pair<pair<string,string>, double>> &arr, int l, int r, string order) {
    if(l>=r) return;
    int mid = l + (r-l)/2;

    mergeS(arr, l, mid, order);
    mergeS(arr, mid + 1, r, order);

    merge(arr, l, mid, r, order);
}

void sortByGpa(vector<pair<pair<string,string>, double>> &arr) {
    mergeS(arr, 0, arr.size()-1, "gpa");
}

void sortByFirst(vector<pair<pair<string,string>, double>> &arr) {

    int l = 0, r = 0;

    for(int i = 0; i<arr.size(); i++) {
        if(i+1 < arr.size() && arr[i].first.first == arr[i+1].first.first) {
            r++;
        }

        else {
            if(l != r) mergeS(arr, l, r, "first");
            l = i+1;
            r = i+1;
        }

    }

    



}

void sortByLast(vector<pair<pair<string,string>, double>> &arr) {
    int l = 0, r = 0;
    for(int i = 0; i<arr.size(); i++) {
        if(i+1 < arr.size() && arr[i].second == arr[i+1].second) {
            r++;
        }

        else {
            if(l != r) mergeS(arr, l, r, "last");
            l = i+1;
            r = i+1;
        }

    }

    



}





double cGpa(vector<pair<int, string>> &arr) {
    double cmltv = 0;
    int sumCred = 0;
    for(pair<int, string> x : arr) {
        sumCred += x.first;

        if(x.second == "A+") cmltv += 4.0 * x.first;
        if(x.second == "A") cmltv += 3.75 * x.first;
        if(x.second == "B+") cmltv += 3.5 * x.first;
        if(x.second == "B") cmltv += 3.0 * x.first;
        if(x.second == "C+") cmltv += 2.5 * x.first;
        if(x.second == "C") cmltv += 2.0 * x.first;
        if(x.second == "D+") cmltv += 1.5 * x.first;
        if(x.second == "D") cmltv += 1.0 * x.first;
        if(x.second == "F") cmltv += 0.0 * x.first;

    }

    return cmltv/sumCred;
}

int main() {
    vector<pair<pair<string,string>, double>> students;
    string frst, scnd, grade;
    int n, ects, num;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> scnd >> frst >> num;
        vector<pair<int, string>> tmp;
        for(int i = 0; i<num; i++) {
            cin >> grade >> ects;
            tmp.push_back(make_pair(ects, grade));
        }
        students.push_back(make_pair(make_pair(scnd, frst), cGpa(tmp)));
    }


    sortByGpa(students);
    sortByLast(students);
    sortByFirst(students);

    for(pair<pair<string,string>, double> x : students) {
        cout << x.first.first << " " << x.first.second << " " << fixed << setprecision(3) << x.second << endl;    
    }









    return 0;
}