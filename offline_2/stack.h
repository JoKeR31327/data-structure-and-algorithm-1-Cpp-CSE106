#include <iostream>
using namespace std;


template<typename t>
class stack
{
    t *a;
    int value, size=0, msize;

public: 
    stack(){
        msize=100;
        a = new t[msize];
    }
    /*stack(){
        msize=100;
        t item;
        a = new t[msize];
        //for(int i=0; i<c; i++)
        while(cin.peek()!='\n')
        {   
            //cin>>item;
            push(item);
        }
        printlist();
    }*/
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

       // printlist();
    }
    t pop()
    {
       /* if (length() == 0)
        {
            cout << "List is empty" << endl;
            return 0;
        }*/

        int pos=length()-1;
        t val=a[pos];
        {
            a[pos] ='\0';
            size--;
           // printlist();
        }
        return val;
    }
    int length()
    {
        return size;
    }
    t topvalue()
    {
        if(length()==0)
        {
            cout<<"error empty"<<endl;
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
        //cout << "<";
        for (int i = 0; i < size; i++)
        {
            cout <<" "<< a[i] << " ";
        }
        //cout << ">" << endl;
        cout<<endl;
    }
    ~stack()
    {
        delete[] a;
    }
};