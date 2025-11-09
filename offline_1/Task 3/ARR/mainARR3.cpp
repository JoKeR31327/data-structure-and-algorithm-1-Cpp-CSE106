#include<iostream>
#include<cstring>
#include "arr3.h"
using namespace std;

void reqcar(list &garage)
{
    int minVal;

    minVal = 1000;

    garage.movetostart();
    while (garage.currpos() < garage.length())
    {
        int val = garage.getvalue();
        if (val < minVal)
        {
            minVal = val;
        }
        garage.next();
    }
    garage.movetostart();
    while (minVal != garage.getvalue())
    {
        garage.next();
    }

    garage.remove();
}
void park(list &garage, int a)
{   
    if(garage.length()==0){
        garage.movetostart();
        garage.insert(a);
        garage.printlist();

    }
    else {
    int maxv;

    maxv = 1;

    garage.movetostart();
    while (garage.currpos() < garage.length())
    {
        int val = garage.getvalue();
        if (val > maxv)
        {
            maxv = val;
        }
        garage.next();
    }
    garage.movetostart();
    while (maxv != garage.getvalue())
    {
        garage.next();
    }
    garage.next();
    garage.insert(a);
}

}


int main()
{
    int no, car, gar, max, d, here = 1,get;
    char input[4], mes[4];
    strcpy(mes, "req");
    cout << "enter the number of cars X: ";
    cin >> car;
    cout << "enter the number of garages Y: ";
    cin >> gar;
    cout << "enter the maximum number of parking spots in a garage: ";
    cin >> max;
    int there = gar;
    list* garages = new list[gar+1];
    for (int i = 0; i < gar; i++)
    {
        cout << "give the garage no. and list of cars containing at garage" << endl;
        cin >> no;
        if (cin.peek() == '\n')
        {
            garages[no].init(0,max);
        }
        else
        {
            garages[no].init(max,max);
        }
    }

    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> input[i];
            if (cin.peek() == '\n')break;
        }
        input[3] = '\0';

        if (strcmp(input, "end") == 0)
        {
            cout << "Exiting the program." << endl;
            break;
        }

        d = strcmp(mes, input);
        if (d == 0)
        {
            while (here < gar+1)
            {
                if (garages[here].length() < 1)
                {
                    here++;
                }
                else
                {
                    reqcar(garages[here]);
                    break;
                }
            }
            if(here>=gar+1)cout<<"ALL GARAGES ARE EMPTY"<<endl;
        }
        else if(d!=0){
            cin>>get;
             while (there>0)
            {
                if (garages[there].length()==max)
                {
                    there--;
                }
                else
                {
                    park(garages[there],get);
                    break;
                }
            }
            if(there<=0)cout<<"ALL GARAGE MAXED OUT"<<endl;
        }
        for(int i=0; i<gar;i++){
            garages[i+1].printlist();
        }

    }
    delete[] garages;
    return 0;
}
