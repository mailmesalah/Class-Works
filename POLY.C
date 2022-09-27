#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct link{
	int pow;
	int coef;
	struct link *next;
};
void create(struct link* node){
	char choice;
	printf("\n\tCreating a Polynomial");
	do{
		printf("\n\tEnter The Coeff:");
		scanf("%d",&node->coef);
		printf("\n\tEnter The Pow:");
		scanf("%d",&node->pow);
		node->next=(struct link*)malloc(sizeof(struct link));
		node=node->next;
		node->next=NULL;
		printf("\n\tDo you want to insert more nodes:");
		choice=getch();
	}while(choice=='y'||choice=='Y');
}
void show(struct link*poly){

	printf("\n\t");
	while(poly->next!=NULL){
		printf("%d^%d",poly->coef,poly->pow);
		poly=poly->next;
		if(poly->next!=NULL)printf("+");
	}
}
void addpoly(struct link* poly,struct link* poly1,struct link* poly2){
	while(poly1->next!=NULL&&poly2->next!=NULL){
		if(poly1->pow>poly2->pow){
			poly->coef=poly1->coef;
			poly->pow=poly1->pow;
			poly1=poly1->next;

		}else if(poly1->pow<poly2->pow){
			poly->coef=poly2->coef;
			poly->pow=poly2->pow;
			poly2=poly2->next;
		}else if(poly1->pow==poly2->pow){
			poly->coef=poly1->coef+poly2->coef;
			poly->pow=poly1->pow;
			poly1=poly1->next;
			poly2=poly2->next;
		}
		poly->next=(struct link*)malloc(sizeof(struct link));
		poly=poly->next;
		poly->next=NULL;
	}
	while(poly1->next!=NULL||poly2->next!=NULL){
		if(poly1->next!=NULL){
			poly->coef=poly1->coef;
			poly->pow=poly1->pow;
			poly1=poly1->next;

		}else if(poly2->pow!=NULL){
			poly->coef=poly2->coef;
			poly->pow=poly2->pow;
			poly2=poly2->next;
		}
		poly->next=(struct link*)malloc(sizeof(struct link));
		poly=poly->next;
		poly->next=NULL;
	}
}


void main(){
	struct link *poly1=(struct link*)malloc(sizeof(struct link));
	struct link *poly2=(struct link*)malloc(sizeof(struct link));
	struct link *poly=(struct link*)malloc(sizeof(struct link));
	clrscr();
	create(poly1);
	create(poly2);
	addpoly(poly,poly1,poly2);
	show(poly);
	getch();
}