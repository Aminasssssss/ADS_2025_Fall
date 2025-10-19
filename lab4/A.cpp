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


class bst{
    public:
    Node *root;

    bst() {
        root = NULL;
    }

    Node *insert(Node *n, int data) {
        if (n == NULL) {
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


    bool path(string route) {
        Node *tmp = root;
        for(char c : route) {


            if(c == 'L') {
                tmp = tmp->left;
               
            }

            else if(c == 'R') {
                tmp = tmp->right;
                
            }

            if(tmp == NULL) {
                return false;
            }


        }

        return true;


    }


};


int main() {
    bst *tree = new bst();
    int n,x,s;
    string word;
    cin >> n >> s;


    string result[s];



    for(int i = 0; i<n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }

    for(int i = 0; i<s; i++) {
        cin >> word;
        if(tree->path(word)) {
            result[i] = "YES";
        }
        else {
            result[i] = "NO";
        }
    }

    for(string x : result) {
        cout << x << endl;
    }






    return 0;
}