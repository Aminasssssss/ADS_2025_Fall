#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


void quick_sort(vector<pair<pair<string, string>, double>> &students, int l, int r, string order) {
    if(l>=r) return;

    int i = l;
    int j = r;
    
    
    double med;
    string medS;
    if(order == "gpa")  med = students[(l+r)/2].second;
    else if(order == "last")  medS = students[(l+r)/2].first.first;
    else if(order == "first")  medS = students[(l+r)/2].first.second;
    
    
    while(i<j) {
        if(order == "gpa") {
            while(students[i].second < med) i++;
            while(students[j].second > med) j--;
        }

        else if(order == "last") {
            while(students[i].first.first < medS) i++;
            while(students[j].first.first > medS) j--;
        }

        else if(order == "first") {
            while(students[i].first.second < medS) i++;
            while(students[j].first.second > medS) j--;
        }

        if(i<=j) {
            swap(students[i], students[j]);
            i++;
            j--;
        }
    }

    quick_sort(students, l, j, order);
    quick_sort(students, i, r, order);

}



void sortByLast(vector<pair<pair<string, string>, double>> &students) {
    int l = 0, r = 0;

    for(int i = 0; i<students.size(); i++) {
        
        if(i < students.size() - 1 && students[i].second == students[i+1].second) {
            r++;
        }

        else {
            if(l != r) quick_sort(students, l, r, "last");

            l = i+1;
            r = i+1;
        }
    }
}


void sortByFirst(vector<pair<pair<string, string>, double>> &students) {
    int l = 0, r = 0;

    for(int i = 0; i<students.size(); i++) {
        
        if(i < students.size() - 1 && students[i].first.first == students[i+1].first.first) {
            r++;
        }

        else {
            if(l != r) quick_sort(students, l, r, "first");

            l = i+1;
            r = i+1;
        }
    }
}









double cumulative(vector<pair<string, int>> credits) {
    double cr_sum = 0;
    double weight = 0;

    for(int i = 0; i< credits.size(); i++) {
        cr_sum += credits[i].second;

        if(credits[i].first == "A+") weight += 4.0*credits[i].second;
        else if(credits[i].first == "A") weight += 3.75*credits[i].second;
        else if(credits[i].first == "B+") weight += 3.5*credits[i].second;
        else if(credits[i].first == "B") weight += 3.0*credits[i].second;
        else if(credits[i].first == "C+") weight += 2.5*credits[i].second;
        else if(credits[i].first == "C") weight += 2.0*credits[i].second;
        else if(credits[i].first == "D+") weight += 1.5*credits[i].second;
        else if(credits[i].first == "D") weight += 1.0*credits[i].second;
        else if(credits[i].first == "F") weight += 0*credits[i].second;
    }


    return weight/cr_sum;
}


int main() {
    vector<pair<pair<string, string>, double>> students;
    int n, sub, ects;
    string surname, name, grd;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> surname >> name >> sub;
        vector<pair<string, int>> credits;
        for(int i = 0; i<sub; i++) {
            cin >> grd >> ects;
            credits.push_back(make_pair(grd, ects));
              
        }
     
        students.push_back(make_pair(make_pair(surname, name), cumulative(credits)));
        
    }

    
    
    
    
    quick_sort(students, 0, n - 1, "gpa");

    
    sortByLast(students);
    sortByFirst(students);
    
    

    for(int i = 0; i<students.size(); i++) {
        cout << students[i].first.first << " " << students[i].first.second << " " << fixed << setprecision(3) << students[i].second << endl;
    }




    return 0;
}