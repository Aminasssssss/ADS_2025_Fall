#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quick_sort(vector<pair<string,string>> &list, int l, int r) {
    if(l>=r) return;

    int i = l;
    int j = r;
    string med = list[(l+r)/2].first;

    while(i<j) {
        while(list[i].first < med) i++;
        while(list[j].first > med) j--;

        if(i <= j) {
            swap(list[i], list[j]);

            i++;
            j--;
        }
    }

    quick_sort(list, l, j);
    quick_sort(list, i, r);
}

class Node{
    public:
    string key, val;
    Node *next;

    Node(string key, string val) {
        this->next = NULL;
        this->key = key;
        this->val = val;
    }
};

class linked_list{
    public:
    int sz;
    Node *front, *back;

    linked_list() {
        front = NULL;
        back = NULL;
        sz = 0;
    }

    void push_back(string key, string val) {
        Node *n = new Node(key, val);
        if(sz == 0) {
            front = back = n;
            sz++;
            return;
        }

       
        back->next = n;
        back = n;
        sz++;       
    }

    bool hasVal(string key) {
        Node *cur = front;
        while(cur) {
            if (cur->val == key) return true;
            cur = cur->next;
        }

        return false;
    }

    string findByKey(string key) {
        Node *cur = front;
        while(cur) {
            if (cur->val == key) return cur->key;
            cur = cur->next;
        }
    }

    void delByVal(string val) {
        Node *cur = front;

        if(cur->val == val) {
            Node *tmp = cur;
            cur = cur->next;
            front = cur;
            delete tmp;
        }


        while(cur->next) {
            if (cur->next->val == val) {
                Node *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                sz--;

            }
            cur = cur->next;
        }


    }

    void print() {
        Node *cur = front;
        while(cur) {
            cout << cur->key << " " << cur->val << endl;
            cur = cur->next;
        }
    }

    vector<pair<string,string>> makeVector() {
        Node *cur = front;
        vector<pair<string,string>> result;
        while(cur) {
            result.push_back(make_pair(cur->key, cur->val));
            cur = cur->next;
        }

        return result;
    }

};


int main() {
    int n;
    linked_list nicknames;
    vector<pair<string,string>> changes;
    string w1, w2;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> w1 >> w2;
        if(!nicknames.hasVal(w1)) {
            nicknames.push_back(w1, w2);
        }

        else {
            string tmp = w1;
            string w1 = nicknames.findByKey(tmp);
            nicknames.push_back(w1, w2);
            nicknames.delByVal(tmp);
            
        }
    }

    changes = nicknames.makeVector();
    quick_sort(changes, 0, changes.size() - 1);


    cout << changes.size() << endl;
    for(int i = 0; i<changes.size(); i++) {
        cout << changes[i].first << " " << changes[i].second << endl;
    }



   
}