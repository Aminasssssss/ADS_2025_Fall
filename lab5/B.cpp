#include <iostream>
#include <vector>
using namespace std;

vector<long long> len;
long long sum = 0;

class heap {
    public:
    vector<long long> tree;

    long long parent(long long i) {
        return (i-1)/2;
    }

    long long left(long long i) {
        return i*2 + 1;
    }

    long long right(long long i) {
        return i*2  +  2;
    }

    long long getMax() {
        return tree[0];
    }

    void insert(long long a) {
        tree.push_back(a);
        long long i = tree.size() - 1;
        
        while(parent(i) >= 0 && tree[parent(i)] < tree[i]) {
            swap(tree[parent(i)], tree[i]);
            i = parent(i);
        }

    }

    void heapify(long long i) {
        if(left(i) > tree.size() - 1) {
            return;
        }

        long long j = left(i);
        if(right(i) < tree.size() && tree[right(i)] > tree[left(i)]) {
            j = right(i);
        }
        
        if(tree[i] < tree[j]) {
            swap(tree[i], tree[j]);
            heapify(j);
        }

    }

    long long extractMax() {

        long long max = getMax();
        swap(tree[0], tree[tree.size() - 1]);
        tree.pop_back();

        if(tree.size() > 0) {
           heapify(0); 
        }
        
        return max;


    }

    void EDmax() {
        long long m1 = extractMax();
        long long m2 = extractMax();
        if(m1 > m2) {
            swap(m1, m2);
        }

        if(m1 == m2) {
            if(tree.size() == 0) {
                insert(0);
            }
            return;
        }

        else {
            m2 -= m1;
        }

        insert(m2);

        
    }

    bool empty() {
        return tree.size() == 0;
    }

    long long sz() {
        return tree.size();
    }




};


int main() {
    heap *tree = new heap();
    long long n, x;
    cin >> n;

    for(long long i = 0; i<n; i++) {
        cin >> x;
        tree->insert(x);
    }

    while(tree->sz() > 1) {
        tree->EDmax();
    }


    cout << tree->tree[0];










    return 0;
}