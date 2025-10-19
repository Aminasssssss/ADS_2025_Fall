#include <iostream>
#include <vector>
using namespace std;

#define LL long long

class heap{
    public:
    vector<LL> tree;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return i*2 + 1;
    }

    int right(int i) {
        return i*2 + 2;
    }

    int getMin() {
        return tree[0];
    }

    void insert(LL data) {
        tree.push_back(data);
        int i = tree.size() - 1;

        while(parent(i) >= 0 && tree[parent(i)] > tree[i]) {
            swap(tree[parent(i)], tree[i]);
            i = parent(i);
        }

    }

    LL extMin() {
        LL min = tree[0];
        swap(tree[0], tree[tree.size() - 1]);
        tree.pop_back();

        if(tree.size() > 0) {
            heapify(0);
        }

        return min;

    }

    void heapify(int i) {
        if(left(i) >= tree.size()) {
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

    void newMix() {
        
        LL n_m = extMin();
        
        n_m += 2 * extMin();

        
        insert(n_m);
    
    }

    int trials(LL tar) {
        int count = 0;

        while(tree.size() > 1) {
            
            if(getMin() >= tar) {
                return count;
            }
           
            count++;
            newMix();
           
        }

        return -1;
        

    }

};


int main() {
    heap *tree = new heap();
    int n, num;
    LL m;
    cin >> n >> m;

    for(int i = 0; i<n; i++) {
        cin >> num;
        tree->insert(num);
    }

    cout << tree->trials(m) << endl;

    







    return 0;
}