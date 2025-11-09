#include <iostream>
using namespace std;

template<typename T>
struct llist
{
    T data;
    llist* next;
};

template<typename T>
class list
{
    llist<T>* dummy = new llist<T>;
    llist<T>* head = nullptr;
    llist<T>* prev = nullptr;
    llist<T>* tail = nullptr;
    int len = 0;

public:
    void init(T item);
    void printlist();
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
    void del();
};

template<typename T>
void list<T>::init(T item)
{
    cin >> item;
    insert(item);
    prev = dummy;
}

template<typename T>
void list<T>::insert(T ele)
{   
    movetostart();
    llist<T>* pro = new llist<T>;
    pro->data = ele;
    pro->next = nullptr;

    if (head == nullptr)
    {
        head = pro;
        prev = pro;
        tail = pro;
        dummy->next = head;
    }
    else
    {   
        prev=tail;
        pro->next = prev->next;
        prev->next = pro;
        prev = prev->next;
        if (prev->next == nullptr)tail = prev;
    }

    len++;
    printlist();
}

template<typename T>
void list<T>::printlist()
{
    llist<T>* temp = head;
    cout << "<";
    while (temp != nullptr)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << ">";
    cout << endl;
}

template<typename T>
void list<T>::movetostart()
{
    prev = dummy;
    prev->next = dummy->next;
    printlist();
}

template<typename T>
void list<T>::movetoend()
{
    if (prev == tail)
    {
        movetostart();
        while (prev->next != tail)
            prev = prev->next;
    }
    else
    {
        while (prev->next != tail)
            prev = prev->next;
        printlist();
    }
}

template<typename T>
int list<T>::length()
{
    return len;
}

template<typename T>
int list<T>::currpos()
{
    int h = 0;
    if (prev == dummy)
        h = 0;
    else
    {
        llist<T>* temp = head;
        while (temp != prev)
        {
            temp = temp->next;
            h++;
        }
        h = h + 1;
    }
    return h;
}

template<typename T>
void list<T>::previous()
{
    int g = currpos();
    int go = g - 2;
    if (g == 0)
    {
        cout << "invalid position. Currently at 0" << endl;
        printlist();
    }
    else if (g == 1)
    {
        movetostart();
        return;
    }
    else
    {
        prev = head;
        while (go)
        {
            prev = prev->next;
            go--;
        }
    }
    printlist();
}

template<typename T>
void list<T>::next()
{
    prev = prev->next;
    printlist();
}

template<typename T>
void list<T>::movetopos(int here)
{
    if (here <= 0)
    {
        cout << "going to start" << endl;
        movetostart();
    }
    else if (here > len)
    {
        cout << "invalid position. moving to end" << endl;
        movetoend();
    }
    else
    {
        prev = head;
        here = here - 1;
        while (here)
        {
            prev = prev->next;
            here--;
        }
        printlist();
    }
}

template<typename T>
T list<T>::remove()
{
    if (len == 0)
    {
        cout << "List is empty or invalid position" << endl;
        return 0;
    }
    else
    {
        llist<T>* temp = prev->next;
        T val = temp->data;
        if (prev == dummy)
        {
            head = head->next;
            prev->next = head;
        }
        else if (temp == tail)
        {
            tail = prev;
            prev->next = nullptr;
            movetoend();
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        len--;
        printlist();
        return val;
    }
}

template<typename T>
T list<T>::getvalue()
{
    return (prev->next)->data;
}

template<typename T>
void list<T>::del()
{
    llist<T>* curr = dummy;
    while (curr != nullptr)
    {
        llist<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }
    dummy = nullptr;
    head = nullptr;
    prev = nullptr;
}
