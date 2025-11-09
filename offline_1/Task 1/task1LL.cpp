#include<iostream>
using namespace std;

struct llist
{
    int data;
    llist* next;
};

class linkedlist
{
    llist *dummy=new llist;
    llist *head = nullptr;
    llist *prev = nullptr;
    llist *tail = nullptr;
    int flag=1;
    int len=0;


public:

    void init(int a)
    {
        int item;
        while(a)
        {
            cin >> item;
            insert(item);
            a--;
        }
        prev=dummy;
        flag=1;
    }

    void insert(int ele)
    {
        llist *pro = new llist;
        pro->data = ele;
        pro->next = nullptr;

        if(head == nullptr)
        {
            head = pro;
            tail = pro;
            dummy->next=head;
        }
        else if(prev==dummy)
        {
            pro->next=head;
            head=pro;
            prev->next=head;
            flag=1;
        }
        else
        {
            pro->next=prev->next;
            prev->next = pro;
            prev =prev->next;
            tail=tail->next;
        }

        len++;
        printlist();
    }

    void printlist()
    {
        llist *temp = head;
        cout<<"<";
        while(temp != nullptr)
        {
            if(flag)
            {
                cout<<"|"<< temp->data;
                flag--;
            }
            else if(temp==prev)cout << " "<< temp->data<<"|";
            else cout << " " << temp->data;
            temp = temp->next;
        }
        cout<<">";
        cout << endl;
    }
    void movetostart()
    {
        prev=dummy;
        prev->next=dummy->next;
        flag=1;
        printlist();
    }
    void movetoend()
    {
        int a;
        if(len==0)
        {
            a=0;
            printlist();
        }
        else if(len==1)movetostart();
        else
        {
            a=len-2;
            prev=head;
            while(a)
            {
                prev=prev->next;
                a--;
            }
            printlist();
        }
    }
    int length()
    {
        return len;
    }
    int currpos()
    {
        int h=0;
        if(prev==dummy)h=0;
        else
        {
            llist *temp= head;
            while(temp!=prev)
            {
                temp=temp->next;
                h++;
            }
            h=h+1;
        }
        return h;
    }
    void previous()
    {
        int g=currpos();
        int go=g-2;
        if(g==0)
        {
            cout<<"invalid position. Currently at 0"<<endl;
            flag=1;
            printlist();
        }
        else if (g==1)
        {
            movetostart();
            return;
        }
        else
        {
            prev=head;
            while(go)
            {
                prev=prev->next;
                go--;
            }
        }
        printlist();
    }
    void next()
    {
        prev=prev->next;
        printlist();

    }
    void movetopos(int here)
    {
        if(here<=0)
        {
            cout<<"going to start"<<endl;
            movetostart();
            flag=1;
        }
        else if(here>len)
        {
            cout<<"invalid position. moving to end"<<endl;
            movetoend();
        }

        else
        {
            prev=head;
            here=here-1;
            while(here)
            {
                prev=prev->next;
                here--;
            }
            printlist();
        }

    }
    int remove()
    {
        if (len == 0)
        {
            cout << "List is empty or invalid position" << endl;
            return -1;
        }
        else
        {
            llist *temp= prev->next;
            int val=temp->data;
            if(prev==dummy)
            {
                head=head->next;
                prev->next=head;
                flag=1;
            }

            else
            {
                prev->next=temp->next;
            }
            printlist();
            len--;
            return val;
        }
    }
    int getvalue()
    {
        return (prev->next)->data;
    }
    void del()
    {
        llist* curr = dummy;
        while(curr != nullptr)
        {
            llist* temp = curr;
            curr = curr->next;
            delete temp;
        }
        dummy= nullptr;
        head = nullptr;
        prev = nullptr;
    }
};

int main()
{
    int s,Q,P,show;
    linkedlist one;
    cout << "Enter the iniial lenght(k): ";
    cin >> s;
    cout<<"enter the list:";
    one.init(s);
    one.printlist();
    cout<<"1 insert(item)"<<endl;
    cout<<"2 remove()"<<endl;
    cout<<"3 moveToStart()"<<endl;
    cout<<"4 moveToEnd() "<<endl;
    cout<<"5 prev()"<<endl;
    cout<<"6 next()"<<endl;
    cout<<"7 length()"<<endl;
    cout<<"8 currPos()"<<endl;
    cout<<"9 moveToPos(int pos)"<<endl;
    cout<<"10 getValue()"<<endl;

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
            show=one.remove();
            cout << "Removed value: " << show<<endl;
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
            cout << "Length: " <<one.length() <<endl;
            break;
        case 8:
            show=one.currpos();
            cout << "Current position: " << show <<endl;
            break;
        case 9:
            one.movetopos(P);
            break;
        case 10:
            cout << "Value at current position: " << one.getvalue() <<endl;
            break;
        default:
            cout << "Invalid Q value. Please try again." <<endl;
        }

    }
    one.del();
    return 0;
}
