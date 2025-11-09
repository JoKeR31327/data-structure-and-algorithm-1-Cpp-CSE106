#include<iostream>
#include<string>
#include <fstream>
using namespace std;
template<typename t>
struct node{
    t key;
    node<t>* left;
    node<t>* right;
};
template<typename t>
class bst{
    node<t>*root=new node<t>;
    int nodecount;
    public:
        bst(){
            root=NULL;
            nodecount=0;
            }

        void insert(t key){
            root=inserter(root,key);
            nodecount++;
        }
        node<t>* inserter(node<t>* temp,t key){
            if(temp==NULL){
            temp= new node<t>;
            temp->key = key;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
            }
            else if(key< temp->key){
                temp->left=inserter(temp->left,key);
            }
            else {
                temp->right=inserter(temp->right,key);
            }
            return temp;
        }


        bool search(t key) {
        return searcher(root, key);
     }   

        bool searcher(node<t>* temp,t key) {    
        if (temp == NULL) {
            return false;
        }
        if (temp->key == key) {
            return true;
        } else if (key < temp->key) {
            return searcher(temp->left, key);
        } else {
            return searcher(temp->right, key);
        }
    }
    void remover(t key){
        root=remover(root,key);
        nodecount--;
    }
    
    node<t>* remover(node<t>*temp,t key){
        if(temp==NULL){
            return temp;
        }

        if (key < temp->key) {
        temp->left = remover(temp->left, key);
        } else if (key > temp->key) {
         temp->right = remover(temp->right, key);
        }
        else {
            if (temp->left == NULL) {
                node<t>* r = temp->right;
                delete temp;
                return r;
            } else if (temp->right == NULL) {
                node<t>* r = temp->left;
                delete temp;
                return r;
        }
        node<t>* successor = temp->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }

        temp->key = successor->key;
        temp->right = remover(temp->right, successor->key);
    }
    return temp; 
}

    void pre(ofstream& output){
        preorder(root,output);
    }
    void post(ofstream& output){
        postorder(root,output);
    }
    void in(ofstream& output){
        inorder(root,output);
    }
    void preorder(node<t>* temp,ofstream& output){
        if(temp==NULL)return;
        output<<temp->key<<" ";
        preorder(temp->left,output);
        preorder(temp->right,output);
    }

    void postorder(node<t>* temp,ofstream& output){
        if(temp==NULL)return;
        postorder(temp->left,output);
        postorder(temp->right,output);
        output<<temp->key<<" ";
    }

    void inorder(node<t>* temp,ofstream& output){
        if (temp == NULL)return;
        inorder(temp->left,output);
        output<<temp->key<<" ";
        inorder(temp->right,output);
    }
    
       void printlist(ofstream& output) {
        output <<"(";
        printer(root,output);
        output <<")"<< endl;
    }


void printer(node<t>* temp,ofstream& output) {
    if (temp == nullptr) {
        return;
    }

    //output <<"(" <<temp->key;
    output<<temp->key;
    if (temp->left || temp->right) {
        output << "(";
        printer(temp->left,output);
        output << ",";
        printer(temp->right,output);
        output << ")";
    }
    //output<<")";
}


    void destructor(node<t>* temp){
        if(temp==NULL)return;
        destructor(temp->left);
        destructor(temp->right);
        delete temp;
    }

    ~bst(){
        destructor(root);
    }
};
/*
template<typename T>
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
            break;
        case 'D':
            cin >> key;
            tree.remover(key);
            break;
        case 'F':
            cin >> key;
            if (tree.search(key)) {
                output << "found"<<endl;
            } else {
                output << "not found"<<endl;
            }
            break;
        case 'T':
            output << "Choose a traversal type (in, pre, post): ";
            cin >> tc;
            if (tc == "In") {
                tree.in();
                output << endl;
            } else if (tc == "Pre") {
                tree.pre();
                output << endl;
            } else if (tc == "Post") {
                tree.post();
                output << endl;
            } else {
                output << "Invalid choice.\n";
            }
            break;
        case 0:
            output << "Exiting...\n";
            return;
        default:
            output << "Invalid choice. Please try again.\n";
        }
    }
}
*/

int main() {
  ifstream input("in.txt");
    ofstream output("out.txt");

    if (!input || !output) {
        cerr << "Error opening files." << endl;
        return 1;
    }
    bst<int> Tree;
    char choice;
    int key;
    string tc;

    while (input >> choice) {
        switch (choice) {
        case 'I':
            input >> key;
            Tree.insert(key);
            Tree.printlist(output);
            break;
        case 'D':
            input >> key;
            Tree.remover(key);
            Tree.printlist(output);
            break;
        case 'F':
            input >> key;
            if (Tree.search(key)) {
                output << "found" << endl;
            } else {
                output << "not found" << endl;
            }
            break;
        case 'T':
            input >> tc;
            if (tc == "In") {
                Tree.in(output);
                output << endl;
            } else if (tc == "Pre") {
                Tree.pre(output);
                output << endl;
            } else if (tc == "Post") {
                Tree.post(output);
                output << endl;
            } else {
                output << "Invalid choice.\n";
            }
            break;
        case '0':
            output << "Exiting\n";
            input.close();
            output.close();
            return 0;
        default:
            output << "Invalid choice. Please try again.\n";
        }
    }

    input.close();
    output.close();
    return 0;
}