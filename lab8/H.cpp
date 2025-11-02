#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define LL long long
using namespace std;

/*
1) get the smallest string ( min ), pop it from vector of all strings - 
2) compute all substrings of min --duplicates, map each hash to pair(l, r) - 
3) for each remaining string, check if each of substrings is in it, map[substring]++; (need p_prefix for max length string)
4) get all substrings for which map[substring] == n-1 (array: preRes)
5) sort preRes desc;
6) take l,r from map[preRes[0]], rebuild the string
*/

// O(n*logn)
void qsStr(vector<string> &arr, int l, int r) {
    if(l>=r) return;
    int i = l, j = r;
    string med = arr[l+(r-l)/2];

    while(i<j) {
        while(arr[i] > med) i++;
        while(arr[j] < med) j--;

        if(i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    qsStr(arr, l, j);
    qsStr(arr, i, r);
}

// O(n*logn)
void qsLL(vector<pair<LL, LL>> &arr, int l, int r) {
    if(l>=r) return;
    int i = l, j = r;
    LL med = arr[l+(r-l)/2].second;

    while(i<j) {
        while(arr[i].second > med) i++;
        while(arr[j].second < med) j--;

        if(i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    qsLL(arr, l, j);
    qsLL(arr, i, r);
}

//O(n2)
unordered_set<LL> s_h(string s, unordered_map<LL, pair<pair<int, int>, LL>> &ranges) {   
    unordered_set<LL> result;
    int sz = s.size();
    for(int i = 0; i<sz; i++) {
        LL h = 0;
        LL p_pow = 1;
        for(int j = i; j<sz; j++) {
            h+= (s[j] - 'a' + 1)*p_pow;
            p_pow *= 31;

            result.insert(h);
            ranges[h] = make_pair(make_pair(i, j), j-i+1);
        }

    }

    return result;

}

// O(n)
vector<LL> get_h(string s) {
    int sz= s.size();
    vector<LL> result(sz);
    result[0] = s[0]-'a'+1;
    LL p_pow = 31;
    for(int i = 1; i<sz; i++) {
        result[i] = result[i-1] + (s[i]-'a'+1)*p_pow;
        p_pow*=31;
    }

    return result;
}

// O(n)
bool exists(LL x, vector<LL> h_p, vector<LL> p_prefix, LL length) {
    LL szh = h_p.size();
  
    for(int i = 0; i<=szh - length; i++) {
    
            LL h_i_j = h_p[i + length - 1];
            if(i>0) h_i_j -= h_p[i-1];

            if(h_i_j == x * p_prefix[i]) return true;
        
    }

    return false;
}


int main() {
    int n;
    string s;
    vector<string> sarr;
    
    unordered_set<LL> ss_h;
    unordered_map<LL, pair<pair<int, int>, LL>> ranges;
    unordered_map<LL, LL> counts;
    cin >> n;
    vector<vector<LL>> h_rest(n-1);
    for(int i = 0; i<n; i++) {
        cin >> s;
        sarr.push_back(s);
    }

// 0)


// 1)
    qsStr(sarr, 0, n-1);
    string min = sarr[n-1];
    sarr.pop_back();

    LL szm = sarr[0].size();
    vector<LL> p_prefix(szm);
    p_prefix[0] = 1;
    for(int i = 1; i<szm; i++) {
        p_prefix[i] = p_prefix[i-1] * 31;
    }


// 1.1)
    for(int i = 0; i<n-1; i++) {
        h_rest[i] = get_h(sarr[i]);
    }




// 2) O(n)
    ss_h = s_h(min, ranges);
    vector<pair<LL, LL>> ss_h1;
    for(LL x : ss_h) {
        ss_h1.push_back(make_pair(x, ranges[x].second));
    }
    LL szssh = ss_h1.size();
    qsLL(ss_h1, 0, szssh-1);

    LL longest;

// 3) O(n*m)
    for(auto x : ss_h1) {
        int cnt = 0;
        for(vector<LL> n_s_h : h_rest) {
            if(exists(x.first, n_s_h, p_prefix, x.second)) {
                cnt++;
            }
            
            else {
                break;
            }
        }
        if(cnt == n-1) {
            longest = x.first;
            break;
        }



    }


// 6)


    //LL longest = preRes[0].first;
    int l = ranges[longest].first.first, r = ranges[longest].first.second;
    string result = "";
    for(int i = l; i<=r; i++) {
        result += min[i];
    }

    
    cout << result;


    return 0;
}