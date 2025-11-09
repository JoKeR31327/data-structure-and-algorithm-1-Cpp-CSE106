#include <iostream>
#include "arr.h"
using namespace std;

template <typename T>
class queue {
    arraylist<T> one;

public:
    void enqueue(T ele);
    T dequeue();
    int length();
    T front();
    T back();
    bool isempty();
    void clear();
    ~queue();
};

