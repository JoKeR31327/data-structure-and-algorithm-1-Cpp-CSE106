
#include<iostream>
using namespace std;
class arraylist
{
    int *a, pos, value, size=0, msize;

public:
    void init(int k, int l);
    void printlist();
    void takeinput();
    void insert(int item);
    int remove();
    void movetostart();
    void movetoend();
    void previous();
    void next();
    int length();
    int currpos();
    void movetopos(int here);
    int getvalue();
    void del();
};

void arraylist::init(int c, int d)
{
   int item;
        msize = d;
        a = new int[msize];
        int index=0;
        pos = 0;
        for(int i=0; i<c; i++)
        {
            cin>>item;
            a[i]=item;
            size++;
        }
        printlist();
}
void arraylist::takeinput()
{
    int item;
    cin>>item;
    insert(item);
}
void arraylist::printlist()
{
    cout << "<";
    for (int i = 0; i < size; i++)
    {
        if (pos == i)
            cout << "|" << a[i] << ",";

        else if (i == size - 1 || i == pos - 1)
            cout << a[i];

        else
            cout << a[i] << ",";
    }

    cout << ">" << endl;
}
void arraylist::movetostart()
{
    pos = 0;
    printlist();
}
void arraylist::movetoend()
{
    pos = size - 1;
    printlist();
}
void arraylist::previous()
{
    pos = pos - 1;
    if (pos < 0)
        pos = 0;
    printlist();
}
void arraylist::next()
{
    pos = pos + 1;
    if (pos > size)
        pos = size;
    printlist();
}
int arraylist::length()
{
    return size;
}
int arraylist::currpos()
{
    printlist();
    return pos;
}
void arraylist::movetopos(int here)
{
    pos = here;
    if (pos < 0)
    {
        cout << "invalid position redirecting to first element" << endl;
        pos = 0;
    }
    else if (pos >= size)
    {
        cout << "invalid position redirecting to last element" << endl;
        pos = size - 1;
    }
    printlist();
}
int arraylist::getvalue()
{
    return a[pos];
}
void arraylist::insert(int item)
{
    if (size < msize)
    {
        for (int i = size - 1; i >= pos; i--)
            a[i + 1] = a[i];
        a[pos] = item;
        size++;

    }
    else
    {
        cout << "no more spaces left.Creating default list with 2xMaxsize"
             << endl;

        msize = 2 * msize;
        int ta[msize];
        for(int i=0; i<size; i++)
        {
            ta[i]= a[i];
        }
        delete[] a;
        a = new int[msize];
        for(int i=0; i<size; i++)
        {
            a[i]= ta[i];
        }
    }

    printlist();
}

int arraylist::remove()
{
    if (size == 0 || pos < 0 || pos >= size)
    {
        cout << "List is empty or invalid position" << endl;
        return -1; // Return a default or error value
    }
    int val = a[pos];
    if(val=='0')cout<<"list empty or invalid position"<<endl;
    else
    {
        for (int i = pos; i < size - 1; i++)
            a[i] = a[i + 1];
        size--;
        printlist();
    }
    return val;
}

void arraylist::del()
{
    delete[] a;
}
