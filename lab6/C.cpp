#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

class heap{
    public:
    vector<ll> tree;
    vector<ll> sorted;

    int left(int i) {
        return i*2 + 1;
    }

    int right(int i) {
        return i*2 + 2;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    void insert(ll a){
        tree.push_back(a);
        int i = tree.size() - 1;

        while(parent(i) >=0 && tree[parent(i)] > tree[i]) {
            swap(tree[parent(i)], tree[i]);
            i = parent(i);
        }
    }

    ll getMin() {
        return tree[0];
    }

    ll extractMin() {
        ll mn = getMin();
        swap(tree[0], tree[tree.size()-1]);
        tree.pop_back();

        if(tree.size() > 0) {
            heapify(0);
        }

        return mn;
    }

    void heapify(int i) {
        if(left(i) > tree.size() - 1) {
            return;
        }

        int j = left(i);
        if(right(i) < tree.size() && tree[right(i)] < tree[j]) {
            j = right(i);
        }

        if(tree[i] > tree[j]) {
            swap(tree[i], tree[j]);
            heapify(j);
        }

    }

    void sort() {
        while(!tree.empty()) {
            sorted.push_back(extractMin());
        }
    }

    

};


int main() {
    map<pair<ll, ll>, ll> pairDif;
    heap *points = new heap();
    int n;
    ll num, minDif = INFINITY;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> num;
        points->insert(num);
    }

    points->sort();

    for(int i = 0; i<points->sorted.size(); i++) {
        if(i+1 < points->sorted.size()) {
            ll f = points->sorted[i];
            ll s = points->sorted[i+1];
            pairDif[make_pair(f, s)] = abs(f-s);
            minDif = min(minDif, abs(f-s));
        }
    }

    

    for(pair<pair<ll,ll>, ll> x : pairDif) {
        if(x.second == minDif) {
            cout << x.first.first << " " << x.first.second << " ";
        }
    }




    return 0;
}