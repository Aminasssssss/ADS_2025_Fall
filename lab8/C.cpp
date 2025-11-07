#include <iostream>
#include <vector>
using namespace std;

long long get_hash(string s) {
    long long sum = 0;
    int p = 31;
    long long p_pow = 1;
    for(char c : s) {
        sum += (c-'a'+1) * p_pow;
        p_pow *= p;
    }

    return sum;
}

vector<long long> h_prefix(string s) {
    int sz = s.size();
    vector<long long> result(sz);
  
    long long p_pow = 31;
    result[0] = (s[0] - 'a' + 1) * 1;
    for(int i = 1; i<sz; i++) {
        result[i] = result[i-1] + (s[i]-'a'+1) * p_pow;
        p_pow *= 31;
    }

    return result;
}

vector<long long> p_prefix(int sz) {
    vector<long long> result(sz);
    
    result[0] = 1;
    for(int i= 1; i<sz; i++) {
        result[i] = result[i-1] * 31;
    }

    return result;
}

void occurences(int sz, string tape, int &count, vector<bool> &covers, vector<long long> s_h, vector<long long> p_prefix) {
    
    int m = tape.size();
    long long tape_hash = get_hash(tape);


    for(int i = 0; i <= sz-m; i++) {
        long long hash_i_j = s_h[i + m - 1];
        if(i>0) {
            hash_i_j -= s_h[i-1];
        }

        if(tape_hash * p_prefix[i] == hash_i_j) {
            for(int j = i; j<=i+m-1; j++) {
                if(!covers[j]) {
                    covers[j] = true;
                    count++;
                }
            }
            
        }
    }

    return;

}



int main() {
    vector<string> tape_h;
    vector<long long> s_h, p_pref;
    



    string s, tape;

    int n, count = 0;
    cin >> s >> n;
    int sz = s.size();
    vector<bool> covers(sz);
    p_pref = p_prefix(sz);
    s_h = h_prefix(s);
    for(int i = 0; i<n; i++) {
        cin >> tape;
       
        tape_h.push_back(tape);
    }

  

    bool done = false;
    for(string x : tape_h) {
        
        occurences(sz, x, count, covers, s_h, p_pref);
        if(count >= sz) {
            break;
        }

    }
 
    
    if(count >= sz) cout << "YES";
    else cout << "NO";
   






    return 0;
}