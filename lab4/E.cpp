#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int, string> routes;
map<int, int> res;

class Node{
    public:
    int data, lvl;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->lvl = 0;
        this->right = NULL;
        this->left = NULL;
    }
};

class bt{
    public:
    Node *root;
    int sz;
    

    bt() {
        root = NULL;
        sz = 0;
        
    }


    void insert(int x, int y, int z) {
        if(sz == 0) {
            Node *n = new Node(x);
            Node *n_n = new Node(y);


            if(z == 0) {
                n->left = n_n;
                routes[y]+='L';
            }
            else {
                n->right = n_n;
                routes[y]+='R';
            }


            res[n->lvl]++;
            root = n;
            
            routes[x] = "";
            sz++;

        }

        else {
            Node *tmp = root;
            Node *n = new Node(y);
            for(char c : routes[x]) {
                if(c == 'L') {
                    tmp = tmp->left;
                }
                else {
                    tmp = tmp->right;
                }
                n->lvl++;
            }

            res[n->lvl + 1]++;

            if(z == 0) {
                routes[y] = routes[x] + 'L';
                tmp->left = n;

            }

            else {
                routes[y] = routes[x] + 'R';
                tmp->right = n;

            }
    

        
      }

    }

};


int main() {
    bt tree;
    int n, x, y, z, mx = 0;
    cin >> n;

    for(int i = 0; i<n-1; i++) {
        cin >> x >> y >> z;
        tree.insert(x,y,z);
    }

    for(pair<int,int> x : res) {
        mx = max(mx, x.second);
    }

    cout << mx;




}