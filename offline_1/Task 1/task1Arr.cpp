#include <iostream>
using namespace std;

class arraylist
{
    int *a, pos, value, size=0, msize;

public:
    void init(int c, int d)
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

    void printlist()
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
    void movetostart()
    {
        pos = 0;
        printlist();
    }
    void movetoend()
    {
        pos = size - 1;
        printlist();
    }
    void previous()
    {
        pos = pos - 1;
        if (pos < 0)
            pos = 0;
        printlist();
    }
    void next()
    {
        pos = pos + 1;
        if (pos > size)
            pos = size;
        printlist();
    }
    int length()
    {
        return size;
    }
    int currpos()
    {
        printlist();
        return pos;
    }
    void movetopos(int here)
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
    int getvalue()
    {
        return a[pos];
    }
    void insert(int item)
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

    int remove()
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

    void del()
    {
        delete[] a;
    }
};

int main()
{
    int show, s, Q, P, maxsize;
    arraylist one;
    cout << "Enter the initial length K and chunk size X= ";
    cin >> s >> maxsize;
    cout << "enter the list" << endl;
    one.init(s, maxsize);
    one.printlist();
    cout << "1 insert(item)" << endl;
    cout << "2 remove()" << endl;
    cout << "3 moveToStart()" << endl;
    cout << "4 moveToEnd() " << endl;
    cout << "5 prev()" << endl;
    cout << "6 next()" << endl;
    cout << "7 length()" << endl;
    cout << "8 currPos()" << endl;
    cout << "9 moveToPos(int pos)" << endl;
    cout << "10 getValue()" << endl;

    while (true)
    {
        cout << "Enter Q (Q is the task number): ";
        cin >> Q;

        if (Q == 0)
        {
            cout << "Exiting the program." << endl;
            break;
        }

        cout << "Enter P as parameter: ";
        cin >> P;
        switch (Q)
        {
        case 1:
            one.insert(P);
            break;
        case 2:
            show = one.remove();
            cout << "Removed value: " << show << endl;
            break;
        case 3:
            one.movetostart();
            break;
        case 4:
            one.movetoend();
            break;
        case 5:
            one.previous();
            break;
        case 6:
            one.next();
            break;
        case 7:
            cout << "Length: " << one.length() << endl;
            break;
        case 8:
            show = one.currpos();
            cout << "Current position: " << show << endl;
            break;
        case 9:
            one.movetopos(P);
            break;
        case 10:
            cout << "Value at current position: " << one.getvalue() << endl;
            break;
        default:
            cout << "Invalid Q value. Please try again." << endl;
        }
    }

    one.del();
    return 0;
}
