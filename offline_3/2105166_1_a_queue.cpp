#include <iostream>
#include "2105166_1_a_queue.h"

template <typename T>
void queue<T>::enqueue(T ele) {
    one.insert(ele);
}

template <typename T>
T queue<T>::dequeue() {
    one.movetostart();
    T rmvd = one.remove();
    return rmvd;
}

template <typename T>
int queue<T>::length() {
    return one.length();
}

template <typename T>
T queue<T>::front() {
    one.movetostart();
    return one.getvalue();
}

template <typename T>
T queue<T>::back() {
    one.movetoend();
    return one.getvalue();
}

template <typename T>
bool queue<T>::isempty() {
    return (one.length() == 0);
}

template <typename T>
void queue<T>::clear() {
    if (one.length() == 0)
        std::cout << "Empty queue" << std::endl;
    else {
        one.movetostart();
        while (one.length() != 0) {
            one.remove();
        }
    }
}

template <typename T>
queue<T>::~queue() {
    one.del();
}
