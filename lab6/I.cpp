#include <iostream>
#include <vector>
using namespace std;

class heap {
    public:
    vector<int> tree;

    int left(int i) {
        return (i*2) + 1;
    }

    int right(int i) {
        return(i*2) + 2;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    int getMin() {
        return tree[0];
    }

    void insert(int a) {
        tree.push_back(a);
        int i = tree.size() - 1;

        while(parent(i) >= 0 && tree[parent(i)] > tree[i]) {
            swap(tree[parent(i)], tree[i]);
            i = parent(i);
        }
    }

    int extractMin() {
        int mn = getMin();
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

    void print() {
        while(tree.size() > 0) {
            cout << char(extractMin());
        }
    }





};


int main() {
    heap *word= new heap();
    char c;
    while(cin.get(c) && c != '\n') {
       
        word->insert(int(c));
    }

    
    word->print();

    





    return 0;
}