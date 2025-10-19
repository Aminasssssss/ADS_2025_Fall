#include <iostream>
#include <cmath>

using namespace std;


class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class bst{
    public:
    Node *root;

    bst() {
        root = NULL;
    }


    Node *insert(Node *n, int data) {
        if(n == NULL) {
            n = new Node(data);
            return  n;
        }

        else if (n->data >= data) {
            n->left = insert(n->left, data);
        }

        else {
            n->right = insert(n->right, data);
        }

        return n;
    }

    void inorder(Node *n) {
        if(n == NULL) {
            return;
        }
        
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }


    int getSize(Node *n) {
        if(n == NULL) {
            return 0;
        }

        return 1 + getSize(n->left) + getSize(n->right);
    }

    Node *getNode(Node *n, int data) {
        if (n == NULL || n->data == data) {
            return n;
        }

        else if(n->data > data) {
            return getNode(n->left, data);
        }

        else {
            return getNode(n->right, data);
        }

    }
};

int main() {
    int n, x, tar;
    cin >> n;
    
    bst *Btree = new bst();

    for(int i = 0; i<n; i++) {
        cin >> x;
        Btree->root = Btree->insert(Btree->root, x);
    }

    cin >> tar;

    cout << Btree->getSize(Btree->getNode(Btree->root, tar));










    return 0;
}
