#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    int sz = s.size();
   
    vector<int> p(sz);
    p[0] = 0;

    for(int i = 1; i<sz; i++) {
        int j = p[i-1];

        while(j>0 && s[i] != s[j]) {
            j = p[j-1];
        }

        if(s[i] == s[j]) {
            j++;
        }

        p[i] = j;
    }

    return p;
}





int main() {
    string s1, s2, new_string;
    bool done;
    cin >> s1 >> s2;
    int ss2 = s2.size();
    int res = -1;
    new_string = s1 + '#' + s2 + s2;
    vector<int> pref_f = prefix_function(new_string);
    int psz = pref_f.size();
    for(int i = 0; i<psz; i++) {
        if(pref_f[i] == ss2) {
            res = i-ss2-ss2;
            break;
        }
    }

    cout << res;






    




    return 0;
}