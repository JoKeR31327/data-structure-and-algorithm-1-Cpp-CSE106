#include <iostream>
#include "stack.h"
#include <string>
using namespace std;
int main(){
string sample;
getline(cin,sample);
int dep=0, curdep=0;
stack<char>one;
char c;
for(int i=0;i<sample.length();i++){
    c=sample[i];
    if(c=='('){
    one.push(c);
    dep++;
    if(curdep<dep)curdep=dep;
    }
    if(c==')'){
    one.pop();
    dep--;
    }
}
if(!one.isempty())cout<<"invalid";
else cout<<curdep;
return 0;
}
