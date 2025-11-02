#include <iostream>
#include <vector>
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

int min_len(string s, int rep) {
    int sz = s.size();
    vector<int> p_f = pref_f(s);
    return sz + (rep-1) * (sz - p_f[sz-1]);
}





int main() {
    vector<int> res;
    int n, rep;
    string s;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> s >> rep;
        res.push_back(min_len(s, rep));
    }

    for(int x : res) {
        cout << x << endl;
    }




    return 0;
}
