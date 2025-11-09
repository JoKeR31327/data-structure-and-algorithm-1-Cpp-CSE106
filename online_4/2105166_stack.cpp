#include<iostream>
#include"2105166_stack.h"

template <typename T>
void Stack<T>::push(T item) {
    if (two.length() == 0)
        one.enqueue(item);
    else if (one.length() == 0)
        two.enqueue(item);
}

template <typename T>
T Stack<T>::pop() {
    T top;
    if (one.isempty() && two.isempty()) {
        std::cout << "Stack is empty." << std::endl;
        return 0;
    }
    else if (two.length() == 0) {
        while (one.length() > 1) {
            two.enqueue(one.front());
            one.dequeue();
        }
        top = one.back();
        one.dequeue();
    }
    else if (one.length() == 0) {
        while (two.length() > 1) {
            one.enqueue(two.front());
            two.dequeue();
        }
        top = two.back();
        two.dequeue();
    }

    return top;
}

template <typename T>
T Stack<T>::top() {
    T top;
    if (one.isempty() && two.isempty()) {
        std::cout << "Stack is empty." << std::endl;
        return 0;
    }
    else if (two.length() == 0) {
        top = one.back();
    }
    else if (one.length() == 0) {
        top = two.back();
    }

    return top;
}

template <typename T>
void Stack<T>::clear() {
    if (one.isempty() && two.isempty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    else if (two.isempty()) {
        while (one.length() != 0)
            one.dequeue();
    }
    else if (one.isempty()) {
        while (two.length() != 0)
            two.dequeue();
    }
}

template <typename T>
int Stack<T>::length() {
    if (one.length() == 0)
        return two.length();
    else if (two.length() == 0)
        return one.length();
    return 0;
}

template <typename T>
bool Stack<T>::empty() {
    return (one.length() == 0 && two.length() == 0);
}
