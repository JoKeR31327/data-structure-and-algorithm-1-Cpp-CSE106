#include<bits/stdc++.h>
using namespace std;
int count(int notes[],int dp[],int n,int v){
    dp[0]=0;
    for(int i=1;i<=v;i++){
        dp[i]=1000;
        for(int j=0;j<n;j++){
            if(i>=notes[j] && dp[i-notes[j]]!=1000){
                dp[i]=min(dp[i],dp[i-notes[j]]+1);
            }
        }
    }
    return dp[v];
}
int main(){
    int n;
    cin>>n;
    int notes[n],dp[1000];
    for(int i=0;i<n-1;i++)cin>>notes[i];
    int v;
    cin>>v;
    cout<<count(notes,dp,n,v);
    return 0;
}