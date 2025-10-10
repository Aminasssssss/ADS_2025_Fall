#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





class heap {
    public:
    vector<long long> tree;
    vector<long long> result;
    int lim;

    heap(int limit) {
        lim = limit;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return i*2 + 1;
    }

    int right(int i) {
        return i*2 + 2;
    }

    long long getMin() {
        return tree[0];
    }

    void slide() {
        result.push_back(sum());
    }

    long long sum() {
        long long s = 0;
        
        if(tree.size() == 0) {
            return s;
        }

        int sz = tree.size();
        int tmp = min(lim, sz);

        for(int i = 0; i<tmp; i++) {
            s+=tree[i];
        }

        return s;
    }


    void insert(long long a) {
        if(tree.size() > 0 && getMin() > a && tree.size() >= lim) {
            return;
        }

        else if( tree.size() >= lim ) {
            tree[0] = a;
            heapify(0);
            return;

        }

        tree.push_back(a);
        int i = tree.size()-1;
        while(parent(i) >= 0 && tree[parent(i)] > tree[i]) {
            swap(tree[parent(i)], tree[i]);
            i = parent(i);
        }

    }

    void print() {
        for(long long x : result) {
            cout << x << endl;
        }


    }

    void heapify(int i) {
        if(left(i) > tree.size() - 1) {
            return;
        }

        int j = left(i);
        if(right(i) < tree.size() && tree[right(i)] < tree[left(i)]) {
            j = right(i);
        }
        
        if(tree[i] > tree[j]) {
            swap(tree[i], tree[j]);
            heapify(j);
        }

    }

    
    

    bool empty() {
        return tree.size() == 0;
    }

    long long sz() {
        return tree.size();
    }




};


int main() {
    int n, x;
    long long num;
    string cmd;
    cin >> n >> x;
    heap *tree = new heap(x);
    

    for(int i = 0; i<n; i++) {
        cin >> cmd;
        if(cmd == "print") {
            tree->slide();
    
        }
        else {
            cin >> num;
            tree->insert(num);
        }
        
    }

    tree->print();


    return 0;
}