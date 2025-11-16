#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




vector<int> pref_f(string s) {
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
    string s;
    cin >> s;
    int sz = s.size();
    vector<int> p_f = pref_f(s);
    int res = sz - p_f[sz-1];

    cout << res;



    return 0;
}