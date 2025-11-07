#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#define LL long long
using namespace std;

const LL mod = 1000000007;

LL get_hash(const string &s) {
    LL sum = 0;
    LL power = 1;
    for(int i = 0; i < s.size(); i++) {
        LL tmp = ((int(s[i]) - 47) * power) % mod;
        sum = (sum + tmp) % mod;
        power = (power * 11) % mod;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(2 * n);
    unordered_map<string, int> count_map;
    
    for(int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        count_map[arr[i]]++;
    }
    
    vector<pair<string, string>> hash_map;
    
    for(int i = 0; i < 2 * n; i++) {
        LL cur_h = get_hash(arr[i]);
        string hash_str = to_string(cur_h);
        
        if(count_map[hash_str] > 0) {
            hash_map.push_back({arr[i], hash_str});
        }

        if(hash_map.size() > n) break;
    }
   
    for(int i = 0; i < n; i++) {
        cout << "Hash of string \"" << hash_map[i].first << "\" is " << hash_map[i].second << endl; 
    }
    
    return 0;
}