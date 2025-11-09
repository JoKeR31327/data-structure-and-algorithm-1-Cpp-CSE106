#include <iostream>
#include "list.h"
using namespace std;

template <typename T>
class queue {
    list<T>one;

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

