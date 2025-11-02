#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#define LL long long


using namespace std;




vector<LL> get_simple(string s) {
    int sz = s.size();
    vector<LL> result(sz);

    for(int i = 0; i<sz; i++) {
        result[i] = s[i] - 'a' + 1;
    }
    return result;
}

void substrings(unordered_set<LL> &set, string s) {
    int sz = s.size();
    vector<LL> h_p(sz);
    LL p_pow = 31;
    h_p[0] = s[0] -'a' + 1;
    for(int i = 1; i<sz; i++) {
        h_p[i] = h_p[i-1] + (s[i] - 'a' + 1) * p_pow;
        p_pow *= 31;
    }

    p_pow = 31;
    for(int i = 0; i<sz; i++) {
        LL hash = 0;
        for(int j = i; j<sz; j++) {
           hash = (hash * p_pow + (s[j] - 'a' + 1));
            
            
            set.insert(hash);
        }
    }

}

int main() {
   
    unordered_set<LL> arr;
    string s;
    LL result = 0;
    cin >> s;
    substrings(arr, s);
    result = arr.size();



    cout  << result << endl;


    


    return 0;
}