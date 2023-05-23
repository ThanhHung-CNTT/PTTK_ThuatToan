#include<iostream>

using namespace std;

int Tonguoc(int n){
    int S=0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
        S = S + i;
        }
    } 
    return S;   
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k=Tonguoc(i);
        if(Tonguoc(k)==i) cout<<i<<" "<<k;
    }  
}