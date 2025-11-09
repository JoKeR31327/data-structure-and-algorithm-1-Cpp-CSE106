#include<iostream>
#include"list.h"
using namespace std;
list A;
list B;
int getsum(list &one){
    int z,sum=0,m;
    int l=one.length();
    m=l-1;
    one.movetostart();
    while(l){
        z=one.getvalue();
        for(int i=0; i<m;i++)z=z*10;
        sum=sum+z;
        one.next();
        m--;
        l--;
    }
    return sum;
}
int main(){
    int s1,s2;
    cout<<"enter lengths:";
    cin>>s1>>s2;
    A.init(s1);
    B.init(s2);
    int sum1=getsum(A);
    int sum2=getsum(B);
    int SUM=sum1+sum2;
    cout<<"the sum is:"<<SUM;
    A.del();
    B.del();
    return 0;
}