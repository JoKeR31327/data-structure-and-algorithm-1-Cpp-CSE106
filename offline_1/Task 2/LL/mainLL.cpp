#include "list.h"
using namespace std;
list one;
void clear()
{
    int w=one.length();
    one.movetostart();
    while(w)
    {
        one.remove();
        w--;
    }
}

void append(int item)
{
    one.movetoend();
    one.next();
    one.insert(item);
    one.printlist();
    one.movetostart();
}

int search(int item)
{
    for (int i = 0; i < one.length(); i++)
    {
        one.movetopos(i);
        if (one.getvalue() == item)
        {
            return one.currpos();
        }

    }
    return -1;
}

int main()
{

    int s, maxsize, Q, P, show;
    cout << "Enter the initial length(k): ";
    cin >> s;
    cout<<"enter the list:";
    one.init(s);
    one.printlist();
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
            clear();
            break;
        case 2:
            append(P);
            break;
        case 3:
            show=search(P);
            if(show==-1)cout<<"returned "<<show<<endl;
            else cout<<"item here at "<<show<<"th position"<<endl;
            break;
        default:
            cout << "Invalid Q value. Please try again." << endl;
        }
    }

}

