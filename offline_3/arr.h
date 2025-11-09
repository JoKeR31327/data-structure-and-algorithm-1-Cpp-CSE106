#include <iostream>
using namespace std;

template <typename T>
class arraylist {
    T *a;
    int pos, size=0, msize, rear,front;

public:
    arraylist(){
        msize = 5;
        a = new T[msize];
        size = 0;
        front = 0;
        rear = -1;
    }
    void init(int k, int l);
    void printlist();
    void takeinput();
    void insert(T item);
    T remove();
    void movetostart();
    void movetoend();
    void previous();
    void next();
    int length();
    int currpos();
    void movetopos(int here);
    T getvalue();
    void replace(int here,T item);
    void del();
};

template <typename T>
void arraylist<T>::insert(T item) {
    if (size == msize) {
            cout << "Queue is full. resizing." << endl;
            msize=msize*2;
             msize = 2 * msize;
            T ta[msize];
            for(int i=0; i<size; i++)
            {
                ta[i]= a[i];
            }
            delete[] a;
            a = new T[msize];
            for(int i=0; i<size; i++)
            {
                a[i]= ta[i];
            }
            return;
        }

    rear = (rear + 1) % msize;
    a[rear] = item;
    size++;
    printlist();
}

template <typename T>
T arraylist<T>::remove() {
   if (size == 0) {
            cout << "Queue is empty." << endl;
        }

        T val = a[front];
        front = (front + 1) % msize;
        size--;
        printlist();
        return val;
}

template <typename T>
void arraylist<T>::init(int c, int d) {
    a = new T[msize];
    printlist();
}

template <typename T>
void arraylist<T>::printlist() {
 cout << "<";
    if (size > 0) {
        int current = front;
        for (int i = 0; i < size; i++) {
            cout << a[current];
            if (i != size - 1) {
                cout << ",";
            }
            current = (current + 1) % msize;
        }
    }
    cout << ">" << endl;
}

template <typename T>
void arraylist<T>::movetostart() {
    pos = front;
    printlist();
}

template <typename T>
void arraylist<T>::movetoend() {
    pos = rear;
    printlist();
}

template <typename T>
void arraylist<T>::previous() {
    pos = pos - 1;
    if (pos < 0)
        pos = 0;
    printlist();
}

template <typename T>
void arraylist<T>::next() {
    pos = pos + 1;
    if (pos > size)
        pos = size;
    printlist();
}

template <typename T>
int arraylist<T>::length() {
    return size;
}

template <typename T>
int arraylist<T>::currpos() {
    printlist();
    return pos;
}

template <typename T>
void arraylist<T>::movetopos(int here) {
    pos = here;
    if (pos < 0) {
        cout << "Invalid position. Redirecting to the first element." << endl;
        pos = 0;
    } else if (pos >= size) {
        cout << "Invalid position. Redirecting to the last element." << endl;
        pos = size - 1;
    }
    printlist();
}

template <typename T>
T arraylist<T>::getvalue() {
    return a[pos];
}

template <typename T>
void arraylist<T>::del() {
    delete[] a;
}
