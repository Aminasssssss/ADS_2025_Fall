#include <iostream>
using namespace std; 

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
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

    Node *insert(Node *n, int data) {
        if(n == NULL) {
            n = new Node(data);
            return n;
        }

        if(n->data > data) {
            n->left = insert(n->left, data);
        }

        else if (n->data < data) {
            n->right = insert(n->right, data);
        }

        return n;
    }


    void preorder(Node *n) {
        if(n == NULL) {
            return;
        }

        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }

    void preByVal(int x) {
        Node *tmp = root;
        while(tmp->data != x) {
            if(tmp->data > x) {
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }

        preorder(tmp);





    }

 
};


int main() {
    int n, x, tar;
    bst *tree = new bst();
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);

    }
    cin >> tar;

    tree->preByVal(tar);





    return 0;
}