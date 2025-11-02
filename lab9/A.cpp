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
    vector<int> pref_f;
    string s1, s2;
    int cnt = 1;
    bool done = false;
    cin >> s1 >> s2;
    string new_string = s2+'#'+s1;
    int sz1 = s1.size(), sz2 = s2.size();
    int basic = sz1;
    if(sz1 >= sz2) {
        
        pref_f = prefix_function(new_string);
        for(int x : pref_f) {
            if(x == sz2) {
                done = true;
                break;
            }
        }
    }

    else {
        while((sz1-sz2) <= basic) {
            cnt++;
            new_string += s1;
            sz1 += basic;

            if(sz1 >= sz2) {
                pref_f = prefix_function(new_string);
                
                for(int x : pref_f) {
                    if(x == sz2) {
                        done = true;
                        break;
                    }
                }
            }

            if(done) break;

        }
    }

    if(done) cout << cnt;
    else cout << -1;
    




    return 0;
}