#include<iostream>

using namespace std;

int main(){
    int n,x;
    float s=1,p=1;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        p=p*x/i;
        s = s+p;
    }
    cout<<s;
}