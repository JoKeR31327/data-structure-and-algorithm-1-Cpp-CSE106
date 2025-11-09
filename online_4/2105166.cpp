#include <iostream>
#include "2105166_1_ll_queue.cpp"
#include "2105166_stack.cpp"
using namespace std;


int main(){
 queue<int>A;
 Stack<int>B;
 queue<int>C;
 int num,temp;
 char c,d;
cin>>c>>num;
if(c=='A')A.enqueue(num);
else if(c=='B')B.push(num);
 else if(c=='C'){
        cin>>d;
        if(d=='A'){
            if(A.length()==0)cout<<"A has no cards";
            else
             temp=A.dequeue();
             C.enqueue(temp);
        }
        else if(d=='B'){
            if(B.length()==0)cout<<"B has no cards";
            else 
            temp=B.pop();
            C.enqueue(temp);
        }
        else if(d=='E'){
            while(C.length()!=0){
            temp=C.dequeue();
            cout<<"C returns card:"<<temp<<endl;
            }
        }
 }

    return 0;
}