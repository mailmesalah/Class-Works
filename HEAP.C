#include<stdio.h>
#include<conio.h>

void rest(int,int *,int);
void makeheap(int *a,int n){
	int i;
	for(i=n/2;i>=1;i--){
		rest(i,a,n);
	}
}

void rest(int p,int *a,int n){
	int i,v;
	v=a[p];

	while(p<=n/2){
		i=2*p;
		if((i<n)&&(a[i]<a[i+1]))
			i++;
		if(v>=a[i])
			break;
		a[p]=a[i];
		p=i;

	}
	a[p]=v;
}

void main(){
	int a[20];
	int i,n,ch;
	clrscr();
	printf("\nEnter the toal nodes");
	scanf("%d",&n);
	printf("\nEnter numbers");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	makeheap(a,n);
	printf("\nHeap is :");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
	getch();
}