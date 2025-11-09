#include <iostream>
#include <string>
using namespace std;

template <typename t>
struct node {
    t key;
    node<t>* left;
    node<t>* right;
};

template <typename t>
class bst {
    node<t>* root = nullptr;
    int nodecount;

public:
    bst() {
        nodecount = 0;
    }

    void insert(t key) {
        root = inserter(root, key);
        nodecount++;
    }

    node<t>* inserter(node<t>* temp, t key) {
        if (temp == nullptr) {
            temp = new node<t>;
            temp->key = key;
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        }
        else if (key < temp->key) {
            temp->left = inserter(temp->left, key);
        }
        else {
            temp->right = inserter(temp->right, key);
        }
        return temp;
    }

    bool search(t key) {
        return searcher(root, key);
    }

    bool searcher(node<t>* temp, t key) {
        if (temp == nullptr) {
            return false;
        }
        if (temp->key == key) {
            return true;
        }
        else if (key < temp->key) {
            return searcher(temp->left, key);
        }
        else {
            return searcher(temp->right, key);
        }
    }

    void remover(t key) {
        root = remover(root, key);
        nodecount--;
    }

    node<t>* remover(node<t>* temp, t key) {
        if (temp == nullptr) {
            return temp;
        }

        if (key < temp->key) {
            temp->left = remover(temp->left, key);
        }
        else if (key > temp->key) {
            temp->right = remover(temp->right, key);
        }
        else {
            if (temp->left == nullptr) {
                node<t>* r = temp->right;
                delete temp;
                return r;
            }
            else if (temp->right == nullptr) {
                node<t>* r = temp->left;
                delete temp;
                return r;
            }
            node<t>* successor = temp->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            temp->key = successor->key;
            temp->right = remover(temp->right, successor->key);
        }
        return temp;
    }

    void printlist() {
        cout<<"(";
        printer(root);
        cout<<")"<< endl;
    }


void printer(node<t>* temp) {
    if (temp == nullptr) {
        return;
    }
    cout<<temp->key;
    if (temp->left || temp->right) {
        cout<< "(";
        printer(temp->left);
        cout<< ",";
        printer(temp->right);
        cout<< ")";
    }
}

    void pre() {
        preorder(root);
    }

    void post() {
        postorder(root);
    }

    void in() {
        inorder(root);
    }

    void preorder(node<t>* temp) {
        if (temp == nullptr) return;
        cout << temp->key << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(node<t>* temp) {
        if (temp == nullptr) return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->key << " ";
    }

    void inorder(node<t>* temp) {
        if (temp == nullptr) return;
        inorder(temp->left);
        cout << temp->key << " ";
        inorder(temp->right);
    }

    void destructor(node<t>* temp) {
        if (temp == nullptr) return;
        destructor(temp->left);
        destructor(temp->right);
        delete temp;
    }

    ~bst() {
        destructor(root);
    }
};

/*template<typename T>
void show(bst<T>& tree) {
    char choice;
    T key;
    string tc;

    while (true) {
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 'I':
            cin >> key;
            tree.insert(key);
            tree.printlist();
            break;
        case 'D':
            cin >> key;
            tree.remover(key);
            tree.printlist();
            break;
        case 'F':
            cin >> key;
            if (tree.search(key)) {
                cout<< "found"<<endl;
            } else {
                cout<< "not found"<<endl;
            }
            break;
        case 'T':
            cin >> tc;
            if (tc == "In") {
                tree.in();
                cout<< endl;
            } else if (tc == "Pre") {
                tree.pre();
                cout<< endl;
            } else if (tc == "Post") {
                tree.post();
                cout<< endl;
            } else {
                cout<< "Invalid choice.\n";
            }
            break;
        case 0:
            cout<< "Exiting...\n";
            return;
        default:
            cout<< "Invalid choice. Please try again.\n";
        }
    }
}
*/