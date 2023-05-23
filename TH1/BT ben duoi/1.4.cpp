#include<iostream>

using namespace std;

int main(){
    long long n;cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n/2;i++){
        swap(a[i],a[n-1-i]);
    }  
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
