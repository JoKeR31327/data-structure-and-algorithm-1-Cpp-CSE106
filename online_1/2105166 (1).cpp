#include<iostream>
using namespace std;
int findnum(int size, int nums){
    int a=1;
    int b[size],c[size];
    for (int i=0; i<size; i++)b[i]=nums;

    for (int i=0; i<=2*size; i++){
        if(i%2!=0){
           c[size]=i;
            }  
        }
        for(int i=0;i<=size;i++)if(b[i]!=c[i])a=c[i];
        return a;
}

int main()
{   
    int b,k,q;
    cout<<"enter k"<<endl;
    cin>>k;
    for(int j=0;j<k;j++){
        cin>>q;
       b=findnum(k,q);
    }
    cout<<"the number "<<b;

    return 0;
}