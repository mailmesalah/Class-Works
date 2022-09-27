#include<stdio.h>

struct DoubleLinkList{
	struct DoubleLinkList * rightLink;
	struct DoubleLinkList *leftLink;
	int data;
}
void main(){

	do{
		int choice;
		clrscr();
		printf("Double Linnked List\n");
		printf("\n\Press 1 for Insert data in List\n");
		printf("Press 2 for Remove data from list\n");
		printf("Press 3 to Show the list\n");
		printf("Press 4 to Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			case 2:
			case 3:
			case 4:
			default :
		}

	}while(ch!=4);
}