
#include<iostream>
using namespace std;

struct llist
{
    int data;
    llist* next;
};

class list
{
    llist *dummy= new llist;
    llist *head = nullptr;
    llist *prev = nullptr;
    llist *tail = nullptr;
    int flag=1;
    int len=0;


public:
    void init(int k);
    void printlist();
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

void list::init(int a)
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

void list::insert(int ele)
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

void list::printlist()
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
void list::movetostart()
{
    prev=dummy;
    prev->next=dummy->next;
    flag=1;
    printlist();
}
void list::movetoend()
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
int list::length()
{

    return len;
}
int list::currpos()
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
void list::previous()
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
void list::next()
{
    prev=prev->next;
    printlist();
}
void list::movetopos(int here)
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
int list::remove()
{
    if (len == 0)
    {
        cout << "List is empty or invalid position" << endl;
        return -1; // Return a default or error value
    }
    else
    {
        llist *temp= prev->next;
        int val=temp->data;;
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
        len--;
        printlist();
        return val;
    }
}
int list::getvalue()
{
    return (prev->next)->data;
}
void  list::del()
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

