#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> prefix_function(string s) {
    int sz = s.size();
    vector<int> result(sz);

    result[0] = 0;

    for(int i = 1; i<sz; i++) {
        int j = result[i-1];

        while(j>0 && s[i] != s[j]) {
            j = result[j-1];
        }

        if(s[i] == s[j]) {
            j++;
        }

        result[i] = j;
    }

    return result;

}


int max_suffix(string s, string m_s) {
    string new_s = s+'#'+m_s;
    vector<int> p_f = prefix_function(new_s);


    return p_f[p_f.size()-1];
}

int main() {
    string m_s, s_s;
    vector<string> result;
    int mx = 0;
    bool exists = false;
    vector<pair<string, int>> mappings;

    int n;
    cin >> m_s >> n;
    for(int i = 0; i<n; i++) {
        cin >> s_s;
        s_s[0] = s_s[0]+32;
        int mx_suf = max_suffix(s_s, m_s);
        mappings.push_back(make_pair(s_s, mx_suf));
        mx = max(mx, mx_suf);

        if(!exists && mx_suf > 0) {
         exists = true;
        }
        
    }

    
    if(exists) {
        for(pair<string, int> x : mappings) {
            if(x.second == mx) {
                result.push_back(x.first);
            }
        }
    }

    

    cout << result.size() << endl;
    for(string x : result) {
        x[0] = x[0]-32;
        cout << x << endl;
    }




    return 0;
}