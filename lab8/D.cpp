#include <iostream>
#include <vector>
using namespace std;
#define LL long long



void quick_sort(vector<pair<pair<string, int>, int>> &arr, int l, int r, string order) {
    if(l>=r) return;
    int i = l, j = r;
    int med;
    if(order == "count") {
        med = arr[l+(r-l)/2].first.second;
    }
    if(order == "index") {
        med = arr[l+(r-l)/2].second;
    }

    
    while(i<j) {
        if(order == "count") {
            while(arr[i].first.second > med) i++;
            while(arr[j].first.second < med) j--;
        }

        if(order == "index") {
            while(arr[i].second < med) i++;
            while(arr[j].second > med) j--;
        }

        if(i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, l, j, order);
    quick_sort(arr, i, r, order);


}

LL get_hash(string s) {
    LL sum = 0;
  
    LL p_pow = 1;
    for(char c : s) {
        sum += (c-'a'+1) * p_pow;
        p_pow *= 31;
    }

    return sum;
}

vector<LL> hash_prefix(string word) {
    
    int sz = word.size();
    vector<LL> result(sz);
    LL p_pow = 31;

    result[0] = (word[0] - 'a' + 1);
    for(int i = 1; i<sz; i++) {
        result[i] = result[i-1] + (word[i] - 'a' + 1) * p_pow;
        p_pow *= 31;
    }

    return result;
}


pair<int, vector<string>> most_patterns(string word, vector<string> patts, vector<LL> p_prefix) {
    vector<LL> word_hash_prefix = hash_prefix(word);
    

    int num_patts = 0;
    int max_freq;
    vector<string> domPatts;
    vector<pair<pair<string, int>, int>> temp;
    vector<pair<pair<string, int>, int>> PattsFreq;
    int sz = word.size();
    int id = 0;
    
    
    for(string x : patts) {
        int m = x.size(), count = 0;
        LL pattHash = get_hash(x);
        
        for(int i = 0; i<=sz - m; i++) {
            LL hash_i_j = word_hash_prefix[i+m-1];
            if(i>0) {
                hash_i_j -= word_hash_prefix[i-1];
            }

            if(pattHash * p_prefix[i] == hash_i_j) {
                
                count++;
            }
        }
        PattsFreq.push_back(make_pair(make_pair(x, count), id));
        id++;
    }

   
    quick_sort(PattsFreq, 0, PattsFreq.size() - 1, "count");
    max_freq = PattsFreq[0].first.second;
    
    for(pair<pair<string, int>, int> x : PattsFreq) {
        if(x.first.second == max_freq) temp.push_back(x);
        
    }

    int sz1 = temp.size();
    quick_sort(temp, 0, temp.size() - 1, "index");
    for(int i = 0; i<sz1; i++) {
        domPatts.push_back(temp[i].first.first);
    }

    num_patts = max_freq;
    return make_pair(num_patts, domPatts);


}




int main() {
    vector<LL> p_prefix(100005);
    p_prefix[0] = 1;
    for(int i = 1; i<100005; i++) {
        p_prefix[i] = p_prefix[i-1] * 31;
    }




    int n;
    vector<pair<int, vector<string>>> dominators;
    string pattern, word;

    while(true) {
        cin >> n;
        if(n == 0) break;

        vector<string> patts;
        for(int i = 0; i<n; i++) {
            cin >> pattern;
            patts.push_back(pattern);

        }
        cin >> word;
        dominators.push_back(most_patterns(word, patts, p_prefix));



    }


    for(int i = 0; i<dominators.size(); i++) {

        cout << dominators[i].first << endl;
        for(string x : dominators[i].second) {
            cout << x << endl;
        }
       
    }



    return 0;
}