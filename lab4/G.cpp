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

class BST {
public:
    Node *root;
    int maxDist;

    BST() {
        root = NULL;
        maxDist = 0;
    }

    Node* insert(Node *n, int data) {
        if(n == NULL) {
            return new Node(data);
        }
        if(data < n->data) {
            n->left = insert(n->left, data);
        }
        else if(data > n->data) {
            n->right = insert(n->right, data);
        }
        return n;
    }

    int deepest(Node *n) {
        if(n == NULL) {
            return 0;
        }
        int l_d = deepest(n->left);
        int r_d = deepest(n->right);
        maxDist = max(maxDist, l_d + r_d);
        return 1 + max(l_d, r_d);
    }

    int getDiameter() {
        maxDist = 0;
        deepest(root);
        return maxDist + 1;
    }
};

int main() {
    int n, x;
    BST *tree = new BST();
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }

    cout << tree->getDiameter() << endl;

    return 0;
}