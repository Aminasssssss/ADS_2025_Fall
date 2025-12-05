#include <iostream>
#include <vector>
using namespace std;
#define LL long long

class min_heap {
    public:
    vector<pair<int,int>> tree;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return i*2+1;
    }

    int right(int i) {
        return i*2+2;
    }

    pair<int,int> getMin() {
        return tree[0];
    }

    void insert(pair<int,int> x) {
        tree.push_back(x);
        int i = tree.size() - 1;

        while(parent(i) >= 0 && tree[i].first < tree[parent(i)].first) {
            swap(tree[i], tree[parent(i)]);
            i = parent(i);
        }
    }

    pair<int, int> extractMin() {
        pair<int, int> mn = getMin();
        swap(tree[0], tree[tree.size() - 1]);
        tree.pop_back();

        if(tree.size() > 0) {
            heapify(0);
        }

        return mn;
    }

    void heapify(int i) {
        if(left(i) > tree.size() - 1) return;
        int j = left(i);

        if(right(i) < tree.size() && tree[right(i)].first < tree[j].first) {
            j = right(i);
        }

        if(tree[i].first > tree[j].first) {
            swap(tree[i], tree[j]);
            heapify(j);
        }
    }

    bool empty() {
        return tree.size() == 0;
    }

    void pop() {
        pair<int, int> mn = getMin();
        swap(tree[0], tree[tree.size() - 1]);
        tree.pop_back();

        if(tree.size() > 0) {
            heapify(0);
        }
    }

    




};


int main() {
    int n, m, l, r, c;
    LL cost = 0;

    cin >> n >> m;
    vector<pair<int, int> > start[n];

    for(int i = 0; i<m; i++) {
        cin >> l >> r >> c;
        l--; r--;
        start[l].push_back({r, c});
    }

    min_heap heap;
    for(int i = 0; i < n-1; i++) {
        for(auto[r, c] : start[i]) {
            heap.insert({c, r});
        }

        while(!heap.empty() && heap.getMin().second <= i) {
            heap.pop();
        }

    
        cost += heap.getMin().first;



    }

    cout << cost;

    return 0;







}