#include <iostream>
using namespace std;


template<typename t>
class stack
{
    t *a;
    int value, size=0, msize;

public:
    stack(int c, int d)
    {
        t item;
        msize = d;
        a = new t[msize];
        //for(int i=0; i<c; i++)
        while(c)
        {   
            cin>>item;
            push(item);
            c--;
        }
        printlist();
    }
    void clear()
    {
        for(int i=0; i<size; i++)pop();
        size=0;
        printlist();
    }
    void push(t item)
    {
        if (size < msize)
        {
            int pos=length();
            a[pos] = item;
            size++;

        }
        else
        {
            cout << "no more spaces left.Creating default list with 2xMaxsize"<< endl;

            msize = msize+1;
            t ta[msize];
            for(int i=0; i<size; i++)
            {
                ta[i]= a[i];
            }
            delete[] a;
            a = new t[msize];
            for(int i=0; i<size; i++)
            {
                a[i]= ta[i];
            }
        }

        printlist();
    }
    void pop()
    {
        if (length() == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        int pos=length()-1;
        {
            a[pos] ='\0';
            size--;
            printlist();
        }
    }
    int length()
    {
        return size;
    }
    t topvalue()
    {
        if(length()==0)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else return a[length()-1];
    }
    bool isempty()
    {
        if(length()==0)return true;
        else return false;
    }
    void printlist()
    {
        cout << "<";
        for (int i = 0; i < size; i++)
        {
            cout <<" "<< a[i] << " ";
        }
        cout << ">" << endl;
    }
    ~stack()
    {
        delete[] a;
    }
};

int main()
{
    int choice,show, s, Q, maxsize;
    cout<<"enter preferable choice\n1.char\n2.int\n3.double"<<endl;
    cin>>choice;
    cout << "Enter the initial length K and chunk size X= ";
    cin >> s >> maxsize;
    if(choice==1)
    {
        stack<char>one(s, maxsize);
              while (true)
        {
            char P;
            cout << "Enter Q (Q is the task number): ";
            cin >>Q>>P;

            if (Q == 0)
            {
                cout << "Exiting the program." << endl;
                break;
            }
            switch (Q)
            {
            case 1:
                one.clear();
                break;
            case 2:
                one.push(P);
                break;
            case 3:
                one.pop();
                break;
            case 4:
                cout << "Length: " << one.length() << endl;
                break;
            case 5:
                cout << one.topvalue() << endl;
                break;
            case 6:
                if(!one.isempty())cout<<"False"<<endl;
                else cout<<"True"<<endl;
                break;
            default:
                cout << "Invalid Q value. Please try again." << endl;
            }
        }
    }
    else if(choice==2)
    {
        stack<int>one(s, maxsize);
              while (true)
        {
            int P;
            cout << "Enter Q (Q is the task number): ";
            cin >>Q>>P;

            if (Q == 0)
            {
                cout << "Exiting the program." << endl;
                break;
            }
            switch (Q)
            {
            case 1:
                one.clear();
                break;
            case 2:
                one.push(P);
                break;
            case 3:
                one.pop();
                break;
            case 4:
                cout << "Length: " << one.length() << endl;
                break;
            case 5:
                cout << one.topvalue() << endl;
                break;
            case 6:
                if(!one.isempty())cout<<"False"<<endl;
                else cout<<"True"<<endl;
                break;
            default:
                cout << "Invalid Q value. Please try again." << endl;
            }
        }
    }
    else if(choice==3)
    {
        stack<double>one(s, maxsize);
              while (true)
        {
            double P;
            cout << "Enter Q (Q is the task number): ";
            cin >>Q>>P;

            if (Q == 0)
            {
                cout << "Exiting the program." << endl;
                break;
            }
            switch (Q)
            {
            case 1:
                one.clear();
                break;
            case 2:
                one.push(P);
                break;
            case 3:
                one.pop();
                break;
            case 4:
                cout << "Length: " << one.length() << endl;
                break;
            case 5:
                cout << one.topvalue() << endl;
                break;
            case 6:
                if(!one.isempty())cout<<"False"<<endl;
                else cout<<"True"<<endl;
                break;
            default:
                cout << "Invalid Q value. Please try again." << endl;
            }
        }
    }
    else cout<<"invalid choice"<<endl;
    return 0;
}
