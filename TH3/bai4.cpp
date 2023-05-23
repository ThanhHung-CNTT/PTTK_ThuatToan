#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int ary[10][10],completed[10],n,cost=0;

void takeInput(){
    int i,j;
    cout<<"Enter the number of villages: ";
    cin>>n;
    cout<<"\nEnter the Cost Matrix\n";
    FOR(i,1,n){
    cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
        FOR(j,1,n) cin>>ary[i][j];
    completed[i]=0;
}

cout<<"\n\nThe cost list is:";
    FOR(i,1,n){
        cout<<"\n";
        FOR(j,1,n) cout<<"\t"<<ary[i][j];
    }
}
int least(int c)
{
    int i,nc=999;
    int min=999,kmin;
    FOR(i,1,n){
        if((ary[c][i]!=0)&&(completed[i]==0))
        if(ary[c][i]+ary[i][c] < min){
            min=ary[i][0]+ary[c][i];
            kmin=ary[c][i];
            nc=i;
        }
    }
    if(min!=999) cost+=kmin;
    return nc;
}
void mincost(int city){
    int i,ncity;
    completed[city]=1;
    cout<<city+1<<"--->";
    ncity=least(city);
    if(ncity==999){
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];
        return;
    }
    mincost(ncity);
}

int main(){
    faster
    takeInput();
    cout<<"\n\nThe Path is:\n";
    mincost(0); 
    cout<<"\n\nMinimum cost is "<<cost;
    return 0;
}