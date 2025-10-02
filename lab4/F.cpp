#include <iostream>
using namespace std;

int cnt = 0;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }

};

class bst{
    public:
    Node *root;

    bst(){
        root = NULL;
    }

    Node *insert(Node *n, int data) {
        if(n == NULL) {
            n = new Node(data);
            return n;
        }

        else if (n->data > data) {
            n->left = insert(n->left, data);
        }

        else if (n->data < data) {
            n->right = insert(n->right, data);
        }

        return n;
    }

    bool hasTr(Node *n) {
        if(n->left != NULL && n->right != NULL) {
            return true;
        }

        return false;
    }

    void trngl(Node *n) {
        if (n == NULL) {
            return;
        }

        trngl(n->left);
        if(hasTr(n)){
            cnt++;
        } 
        trngl(n->right);


    }



};



int main() {
    bst *tree = new bst();
    int n, x;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }

    tree->trngl(tree->root);
    cout << cnt;

}