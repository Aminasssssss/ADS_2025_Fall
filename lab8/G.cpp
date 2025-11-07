#include <iostream>
#include <vector>
using namespace std;
#define LL long long

vector<LL> get_p_prefix(int sz) {
    vector<LL> result(sz);
    result[0] = 1;
    for(int i = 1; i<sz; i++) {
        result[i] = result[i-1] * 31;
    }

    return result;

}

vector<LL> get_simple(string s) {
    
    int sz = s.size();
    vector<LL> result(sz);

    for(int i = 0; i<sz; i++) {
        result[i] = s[i] - 'a' + 1;
    }

    return result;
}

LL get_hash(string s) {
    LL sum = 0;
    LL p_pow = 1;
    int sz = s.size();
    for(int i = 0; i<sz; i++) {
        sum += s[i] * p_pow;
        p_pow *= 31;
    }

    return sum;
}

vector<LL> get_h(string s) {
    int sz = s.size();
    vector<LL> result(sz);
    result[0] = s[0] - 'a' + 1;
    LL p_pow = 31;
    for(int i = 1; i<sz; i++) {
        result[i] = result[i-1] + (s[i] - 'a' + 1) * p_pow;
        p_pow *= 31;
    }

    return result;
}

LL substring(string s, int l, int r, vector<LL> h_p, vector<LL> p_prefix, vector<LL> simple) {
    LL tar_hash = 0;
    LL p_pow = 1;
    for(int i = l; i<=r; i++) {
        tar_hash += simple[i] * p_pow;
        p_pow *= 31;
    }
    
    LL m = r-l+1;
    LL sz = s.size();

    
    LL count = 0;

    for(int i = 0; i <= sz-m; i++) {
        LL h_i_j = h_p[i+m-1];
        if(i > 0) h_i_j -= h_p[i-1];

        if(h_i_j == tar_hash * p_prefix[i]) count++;
    }

    return count;


}


int main() {
    vector<LL> result;

    string s;
    int n, l, r;
    cin >> s;

    int sz = s.size();
    vector<LL> p_prefix = get_p_prefix(sz);
    vector<LL> simple = get_simple(s);

    cin >> n;
    vector<LL> h_p = get_h(s);
    for(int i = 0; i<n; i++) {
        cin >> l >> r;
        result.push_back(substring(s, l-1, r-1, h_p, p_prefix, simple));
    }

    for(LL x : result) {
        cout << x << endl;
    }




    return 0;
}