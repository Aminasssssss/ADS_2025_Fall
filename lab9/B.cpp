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
    string s1, s2;
    int k;
    bool done = false;
    cin >> s1 >> k >> s2;
    string resource = s1 + '#' + s2;
    int rsz = s1.size();
    vector<int> prefix_n = prefix_function(resource);
    int c = 0;
    for(int x : prefix_n) {
        if(x == rsz) {
            c++;
        }

        if(c>=k) {
            done = true;
            break;
        }
    }

    if(done) cout << "YES";
    else cout << "NO";



    return 0;
}