#include <iostream>
//#include "2105166_1_a_queue.cpp"
#include "2105166_1_ll_queue.cpp"
using namespace std;

template <typename T>
class Stack {
    queue<T> one, two;

public:
    void push(T item);
    T pop();
    T top();
    void clear();
    int length();
    bool empty();
};
