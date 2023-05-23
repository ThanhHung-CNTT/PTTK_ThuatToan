#include<iostream>

using namespace std;

int main(){
    int n;cin>>n;
    float S =0;
    float gt =1;
    for(int i=1;i<=n;i++){
        gt=gt*i;
        S =S +(2*i-1)/gt;
    }
    cout<<S;
}