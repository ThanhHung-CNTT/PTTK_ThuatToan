#include<iostream>

using namespace std;

int main(){
    int n;cin>>n;
    float S=1,a=1;
    for(int i=1;i<=n;i++){
        a=a*(2*i-1)/i;
        S = S+a;
    }
    cout<<S;
}