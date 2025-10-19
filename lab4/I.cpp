#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data, reps;
    Node *left,*right;

    Node(int data) {
        this->data = data;
        reps = 1;
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
            return n;
        }

        else if (n->data == data) {
            n->reps++;
            return n;
        }

        else if (n->data > data) {
            n->left = insert(n->left, data);
        }

        else {
            n->right = insert(n->right, data);
        }

        return n;
    }

    Node *findMax(Node *tmp) {
        if(tmp == NULL) {
            return NULL;
        }

        while(tmp->right != NULL) {
            tmp = tmp->right;
        }
        return tmp;
    }

    Node *findMin(Node *tmp) {
        if(tmp == NULL) {
            return NULL;
        }

        while(tmp->left != NULL) {
            tmp = tmp->left;
        }
        return tmp;
    }

    int count(int tar) {
        Node *n = root;
        while(true) {
            if(n == NULL) {
                return 0;
            }

            else if (n->data == tar) {
                return n->reps;
            }

            else if(n->data > tar) {
                n = n->left;
            }
            
            else {
                n = n->right;
            }
        }



        
    }


    Node *del(Node *n, int data) {
    if(n == NULL) {
        return NULL;
    }

    if(n->data > data) {
        n->left = del(n->left, data);
    }
    else if(n->data < data) {
        n->right = del(n->right, data);
    }
    else {
        
        if(n->reps > 1) {
            n->reps--;  
        }
        else {
           
            if(n->left == NULL && n->right == NULL) {
                delete n;
                return NULL;
            }
            else if(n->left == NULL) {
                Node *tmp = n->right;
                delete n;
                return tmp;
            }
            else if(n->right == NULL) {
                Node *tmp = n->left;
                delete n;
                return tmp;
            }
            else {
              
                Node *pred = findMax(n->left);
                
                
                n->data = pred->data;
                n->reps = pred->reps;
                
                
                n->left = del(n->left, pred->data);
            }
        }
    }
    return n;
}

    



        


}
;


int main() {
    vector<int> result;
    bst *tree = new bst();
    int n, x;
    string word;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> word >> x;

        if ( word == "insert") {
            tree->root = tree->insert(tree->root, x);
        }

        else if (word == "cnt") {
            result.push_back(tree->count(x));
        }

        else if (word == "delete") {
            tree->root = tree->del(tree->root, x);
        }
    }


    for(int x : result) {
        cout << x << endl;
    }














    return 0;

}
