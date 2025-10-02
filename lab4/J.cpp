#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> res;
vector<int> niceres;

#define LL long long

LL num, pos = 0, med;



void solve(int l, int r) {
    if(l>r) {
        return;
    }
    int mid = (l+r)/2;
    
    niceres.push_back(res[mid]);

    solve(l, mid - 1);
    solve(mid + 1, r);



}

class Node {
    public:
    LL data;
    Node *left, *right;

    Node(LL data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class bst {
    public:
    Node *root;

    bst() {
        root = NULL;
    }

    Node *insert(Node *n, LL data) {
        if (n == NULL) {
            n = new Node(data);
            return n;
        }

        else if(n->data > data) {
            n->left = insert(n->left, data);
        }

        else if(n->data < data) {
            n->right = insert(n->right, data);
        }

        return n;


        //int tar = floor((pow(2, num) - 1) / 2);
    }



    void inorder(Node *n) {
        if(n == NULL) {
            return;
        }

        inorder(n->left);
        res.push_back(n->data);
        inorder(n->right);
    }

};


int main() {
    
    bst *tree = new bst();

    LL x;
    cin >> num;
    LL sz = (pow(2, num) - 1) - 1;
    LL tar = floor(sz / 2);

    for(LL i = 0; i<=sz; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }

    tree->inorder(tree->root);

    solve(0, sz);

 //1 2 3 4 5 6 7
    for(int x : niceres) {
        cout << x << " ";
    }



    

}