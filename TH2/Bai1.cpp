#include<stdio.h>
#include<conio.h>
using namespace std;
void nhapmang(int a[], int &n)
{ 
	printf("nhap so phan tu :" );
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{ 
		printf(" phan tu thu %d :",i);
    	scanf("%d",&a[i]);
  	}
}
int xuatmang(int a[],int n)
{
  	printf("mang da nhap \n");
  	for(int i=0;i<n;i++)
    {
		printf(" %4d ",a[i]);
    }
}
void daycontang(int a[],int n)
{
	printf("\n cac day con tang la: \n");
	int i,dem;
	for( i=0;i<n;i++)
	{
		dem=0;
		while(a[i]<a[i+1])
		{
 			if(a[i]<a[i+1]) printf("%d %d ",a[i],a[i+1]);
 			else printf("%d",a[i+1]);
 			dem++; 
			i++; 
		}
 		printf("\n");
 	}
}
int main()
{
 	int a[50],n;
 	nhapmang(a,n);
 	xuatmang(a,n);
 	daycontang(a,n);
 	return 0;
}
