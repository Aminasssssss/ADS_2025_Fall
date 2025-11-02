#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long get_hash(string s) {
    long long sum = 0;
    int p = 29;
    long long p_pow = 1;

    for(char c : s) {
        sum += (c - 'a' + 1) * p_pow;
        p_pow *= p;
    }

    return sum;
}

vector<long long> get_h(string s) {
    int sz = s.size();
    vector<long long> result(sz);
    int p = 29;
    long long p_pow = 29;
    result[0] = (s[0] - 'a' + 1) * 1;

    for(int i = 1; i<sz; i++) {
        result[i] = result[i-1] + (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }

    return result;

}

vector<long long> get_p_prefix(int sz) {
    vector<long long> result(sz);
    result[0] = 1;
    for(int i = 1; i < sz; i++) {
        result[i] = result[i-1] * 29;
    }

    return result;
    
}

vector<int> occurences(string s, string target, vector<long long> p_prefix) {
    int sz = s.size(), m = target.size();

    if(m > sz) return vector<int>();

    vector<long long> hash_prefix = get_h(s);
    long long t_hash = get_hash(target);
    
    vector<int> r1;


     for(int i = 0; i <= sz - m; i++) {
        long long hash_i_j = hash_prefix[i + m - 1];
        if(i > 0) {
            hash_i_j = hash_i_j - hash_prefix[i - 1];
        }

        if(hash_i_j == t_hash * p_prefix[i]) {
            r1.push_back(i);
        }

    }

    return r1;
}



int main() {
    
    string s1, s2, par;
    cin >> s1 >> s2 >> par;
    int sz1 = s1.size(), sz2 = s2.size(), psz = par.size();
    int ms = max(sz1, sz2);
  
 


    long long t_hash = get_hash(par);
    vector<long long> h1_prefix = get_h(s1);
    vector<long long> h2_prefix = get_h(s2);
    vector<long long> p_prefix = get_p_prefix(ms);
    vector<int> r1 = occurences(s1, par, p_prefix);
    vector<int> r2 = occurences(s2, par, p_prefix);
    unordered_map<int, bool> valid;
    for(int x : r2) {
        valid[x] = true;
    }

    int c = 0;
     sz1 = r1.size();
     sz2 = r2.size();
    for(int x : r1) {
        if(valid[x]) c++;
    }

    cout << c;
    

   



    return 0;
}