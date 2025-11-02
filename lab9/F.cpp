#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_f(string s) {
    int sz = s.size();
    vector<int> p(sz);
    p[0] = 0;

    for(int i = 1; i<sz; i++) {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]) {
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
    vector<int> res;
    string s1, s2;
    cin >> s1 >> s2;
    int tar = s2.size();
    s1 = s2+'#'+s1;
    vector<int> p_f = pref_f(s1);
    int spf = p_f.size();
    for(int i = 0; i<spf; i++) {
        if(p_f[i] == tar) {
            res.push_back(i-2*tar+1);
        }
    }

    cout << res.size() << endl;
    for(int x : res) {
        cout << x << " ";
    }
    



    return 0;
}