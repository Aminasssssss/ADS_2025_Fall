#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long

void quick_sort(vector<LL> &list, int l, int r) {
    if(l >= r) {
        return;
    }
    LL med = list[(l+r)/2];
    int i = l;
    int j = r;

    while(i<j) {
        while(list[i] < med) {
            i++;
        }

        while(list[j] > med) {
            j--;
        }

        if(i<=j) {
            swap(list[i], list[j]);
            i++;
            j--;
        }
        
    }

    quick_sort(list, l, j);
    quick_sort(list, i, r);





}

//10-01-2006
LL str2int(string a) {
    LL day = 0, month = 0, year = 0;
    for(int i = 0; i<2; i++) {
        day = day*10 + (int(a[i]) - 48);
    }

    for(int i = 3; i<5; i++) {
        month = month*10 + (int(a[i]) - 48);
    }

    for(int i = 6; i<10; i++) {
        year = year*10 + (int(a[i]) - 48);
    }

    LL res = year*10000 + month*100 + day;
    return res;





}


string int2str(LL a) {
    string day = "", month = "", year = "";
    char c;
    for(int i = 0; i<2; i++) {
        if(a%10 == 0) {
            c = '0';
        }
        else {
            c = char(a%10 + 48);
        }
        a/=10;
        day = c + day;
    }

    for(int i = 0; i<2; i++) {
        if(a%10 == 0) {
            c = '0';
        }
        else {
            c = char(a%10 + 48);
        }
        a/=10;
        month = c + month;
    }

    for(int i = 0; i<4; i++) {
        if(a%10 == 0) {
            c = '0';
        }
        else {
            c = char(a%10 + 48);
        }
        a/=10;
        year = c + year;
    }

    return day + '-' + month + '-' + year;



    

}


int main() {
    vector<LL> dateF;
    string date;
    LL dateN = 0, d, m, y;
    int n;

    cin >> n;
  


    for(int i = 0; i<n; i++) {
        cin >> date;

        dateF.push_back(str2int(date));
    }

    quick_sort(dateF, 0, n-1);

    
    for(int i = 0; i<dateF.size(); i++) {
        cout << int2str(dateF[i]) << endl;
    }






    return 0;
}