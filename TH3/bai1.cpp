/*Bài 1: Bài toán đường đi của người giao hàng Có một người giao hàng cần đi giao hàng tại  n thành phố. Xuất phát từ một thành phố nào đó,  đi qua các thành phố khác để giao hàng và trở về  thành phố ban đầu. Mỗi thành phố chỉ đến một  lần, khoảng cách từ một thành phố đến các thành  phố khác là xác định được. Khoảng cách giữa hai  thành phố có thể là khoảng cách địa lý, có thể là  cước phí di chuyển hoặc thời gian di chuyển. Ta  gọi chung là độ dài. Hãy tìm một chu trình (một  đường đi khép kín thỏa mãn điều kiện trên) sao  cho tổng độ dài các cạnh là nhỏ nhất. Hay còn nói là tìm một phương án có giá nhỏ nhất. Bài toán  này cũng được gọi là bài toán người du lịch */

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

int a[10][10],visited[10],n,cost=0; 
int least (int); 
void get(){ 
    int i,j; 
    cout<<"Enter number of Cities: "; 
    cin>>n; 
    cout<<"\nEnter Cost Matrix\n"; 
    FOR(i,1,n){ 
        cout<<"\nEnter Elements of Row # : "<<i<<endl; 
        FOR(j,1,n) cin>>a[i][j]; 
        visited[i]=0; 
    } 
    cout<<"\n\nThe cost list is:\n\n"; 
    FOR(i,1,n) { 
        EL; 
        FOR(j,1,n) cout<<a[i][j]<<" "; 
    } 
} 
void mincost(int city) { 
    int i,ncity; 
    visited[city]=1; 
    cout<<" -->"<<city+1; 
    ncity=least(city); 
    if(ncity==999) { 
        ncity=0;
        cout<<ncity+1; 
        cost+=a[city][ncity]; 
        return; 
    } 
    mincost(ncity); 
} 
int least(int c) { 
    int i,nc=999; 
    int min=999,kmin; 
    FOR(i,1,n) { 
        if((a[c][i]!=0)&&(visited[i]==0)) 
        if(a[c][i] < min) { 
            min=a[i][0]+a[c][i]; 
            kmin=a[c][i]; 
            nc=i; 
        } 
    } 
    if(min!=999) cost+=kmin; 
    return nc; 
} 
void put() { 
    cout<<"\nMinimum cost: "<<cost; 
} 
int main() { 
    get(); 
    cout<<"\n\nThe Path is:\n\n"; 
    mincost(0); 
    put(); 
    return 0; 
} 