#include <iostream>
#include <vector>
using namespace std;


vector<int> result;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

class bst{
    public:
    Node *root;
    int sum;

    bst() {
        root = NULL;
    }

    Node *insert(Node *n, int data) {
        if(n == NULL) {
            n = new Node(data);
            return n;
        }

        else if(n->data  >= data) {
            n->left = insert(n->left, data);
        }

        else if(n->data <= data) {
            n->right = insert(n->right, data);
        }

        return n;
    }


    int sumSub(Node *n) {
        if(n == NULL) {
            return 0;
        }


        int rs = sumSub(n->right);
        int ls = sumSub(n->left);
        
        return n->data + ls + rs;

    }

    void inorder(Node *n) {
    
        if(n == NULL) {
            return;
        }

        inorder(n->right);
        sum+=n->data;
        
        result.push_back(sum);

        inorder(n->left);
        
        
        
        
        
      
    }

    void print(Node *n) {
        if(n == NULL) {
            return;
        }
        print(n->left);
        cout<< n->data << " ";
        print(n->right);
    }


};


int main() {
    int n, x;
    bst *tree = new bst();
    bst *res = new bst();
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }

    tree->sum = 0;
    tree->inorder(tree->root);

    for(int x : result) {
        res->root = res->insert(res->root, x);
    }

    res->print(res->root);





    return 0;
}

