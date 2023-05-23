#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define size 100
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

typedef struct{
    int CN, CV, TG;
}PhanCong;
typedef struct{
    int TG,STT;
}Data;

void read_data(Data a[][size], int &n){
    FILE *f;
    f=fopen(".src\\practice 3\\phanconglaodong.txt","r");
    if(f==NULL){
        cout<<"error";
        return;
    }
    int i,j;
    fscanf(f,"̀%d",n);
    FOR(i,1,n){
        FOR(j,1,n) {
            fscanf(f,"%d",&a[i][j].TG);
            a[i][j].STT=0;
        }
    }
    fclose(f);
}

void PrintData(Data a[size][size], int n){
    FOR(i,1,n){
        FOR(j,1,n){
            cout<<" "<<a[i][j].TG;    
        }
        EL;
    }
}

void updateWork(Data a[][size], int n,int j){
    FOR(i,1,n) a[i][j].STT=1;
}

int Min_of_Row(Data a[][size], int n , int i, int &j){
    int TGMin =32767;
    FOR(k,1,n){
        if(a[i][k].STT==0 && a[i][k].TG<TGMin){
            TGMin = a[i][k].TG;
            j=k;
        }
    }
    return TGMin;
}
void Greedy(Data a[][size], int n,PhanCong PA[]){
    int j;
    FOR(i,1,n){
        PA[i].CN=i+1;
        PA[i].TG=Min_of_Row(a,n,i,j);
        PA[i].CV=j+1;
        updateWork(a,n,j);
    }
}

void printPA(PhanCong PA[], int n){
    int sum=0;
    cout<<"Cong nhan  Cong viec ThoiGian"<<endl;
    FOR(i,1,n){
        printf("̀%4d     %4d%15d\n",PA[i].CN,PA[i].CV,PA[i].TG);
        sum+=PA[i].TG;
    }
    cout<<"Tong thoi gian thuc hien la: "<<sum<<endl;
}
int main(){
    faster
    Data a[size][size];
    int n;
    read_data(a,n);
    PhanCong PA[n];
    PrintData(a,n);
    Greedy(a,n,PA);
    printPA(PA,n);
    return 0;
}