#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int a[n][n];
    int s1=0,s2=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        s1 += a[i][i];
        s2 += a[i][n-i+1];
    }
    cout<<s1<<" "<<s2<<endl;
}