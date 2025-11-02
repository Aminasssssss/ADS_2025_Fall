#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define LL long long

string restore_key(vector<LL> hashes) {
    string result = "";
    for(int i = 0; i<hashes.size(); i++) {
        LL asci = hashes[i];
        if(i > 0) asci -= hashes[i-1];

        char c = char((asci/pow(2, i)) + 97);

        result += c;
    }

    return result;

}

int main() {
    int n;
    LL h;
    cin >> n;
    vector<LL> hashes(n);

    for(int i = 0; i<n; i++) {
        cin >> h;
        hashes[i] = h;
    }

    string word = restore_key(hashes);

    cout << word;




    return 0;
}