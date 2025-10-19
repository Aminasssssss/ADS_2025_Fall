#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int lvlSum[5001];



class Node {
    public:
    int data;
    int lvl;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        this->lvl = 1;
        this->left = NULL;
        this->right = NULL;
    
    }
};

class bst {
    public:
    Node *root;

    bst() {
        this->root = NULL;
    }

    Node *insert(Node *n, int data) {
        if ( n == NULL ) {
            n = new Node(data);
            return n;
        }


        else if (n->data >= data) {
            n->left = insert(n->left, data);
        }

        else {
            n->right = insert(n->right, data);
        }

        return n;
    }


    int nodeLvl(int tar) {
        Node *tmp = root;
        int lvl = 1;
        while(tar != tmp->data) {
            if(tmp->data > tar) {
                tmp = tmp->left;
        
            }
            else {
                tmp = tmp->right;
            
            }
            lvl++;
        }

        return lvl;

    }

    int getHeight(Node *n) {
        if(n == NULL) {
            return 0;
        }

        return 1 + max(getHeight(n->left), getHeight(n->right));
    }

    void lvlDstr(Node *n, int lvl) {
       
        if(n == NULL) {
            return;
        }

        lvlSum[lvl - 1] += n->data;

        lvlDstr(n->left, lvl + 1);
        
        lvlDstr(n->right, lvl + 1);
        
        
    }




};

int main() {
    int n, x, tar;
    cin >> n;
    
    bst *tree = new bst();

    for(int i = 0; i<n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }
    cin >> tar;

    int arr[5001];
    int sz = tree->getHeight(tree->root);

    tree->lvlDstr(tree->root, 1);

    

    cout << sz << endl;

    for(int i = 0; i<sz; i++) {
        cout << lvlSum[i] << " ";
    }



    return 0;
}