#include "HeadFile.h"

const int inf = 0x3f3f3f3f;
void merge(int *A,int *L,int *R,int p,int q,int r)
{
	int i, j, k;
	int n1,n2;
	n1=q-p+1;
	n2=r-q;
	for(i=1;i<=n1;i++)
		L[i]=A[p+i-1];
	for(j=1;j<=n2;j++)
		R[j]=A[q+j];
	L[n1+1]=inf;
	R[n2+1]=inf;
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i=i+1;
		}
		else
		{
			A[k]=R[j];
			j=j+1;
		} 
	}
}

void mergesort(int *A,int *L,int *R,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(A,L,R,p,q);
		mergesort(A,L,R,q+1,r);
		merge(A,L,R,p,q,r);
	}
}
