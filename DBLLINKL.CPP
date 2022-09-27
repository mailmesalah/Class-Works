#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

struct DoubleLinkList{
    struct DoubleLinkList *rightLink;
    struct DoubleLinkList *leftLink;
    int data;
};
typedef struct DoubleLinkList DLinkList;

class List{

    DLinkList *first;

    public :
       List(){
	  first=NULL;
       }

       void insertByData(){
	  DLinkList *temp;
	  temp=first;
	  if(temp==NULL){
	     cout<<"\nThe List is Empty.Do you want to make the first Node?(Y/N):";
	     char choice;
	     cin>>choice;
	     if(choice=='Y'||choice=='y'){
	       cout<<"\nEnter the data to be inserted:";
	       int data;
	       cin>>data;
	       cout<<"\nSuccessfully inserted the data!";
	       DLinkList *newNode=new DLinkList;
	       newNode->data=data;
	       newNode->rightLink=NULL;
	       newNode->leftLink=NULL;
	       first=newNode;
	     }
	     return;
	  }
	  cout<<"\nEnter a data to search in the list";
	  int searchData;
	  cin>>searchData;
	  while(temp!=NULL){
	     if(temp->data==searchData){
	       cout<<"\nSelect Left or Right to insert in Current Node(L/R):";
	       char choice;
	       cin>>choice;
	       cout<<"\nEnter the data to be inserted:";
	       int data;
	       cin>>data;
	       DLinkList *t;
	       DLinkList *newNode=new DLinkList;
	       newNode->data=data;
	       cout<<"\nSuccessfully inserted the data!";

	       if(choice=='L'||choice=='l'){

		  if(temp->leftLink==NULL){//for the first node
		     newNode->leftLink=NULL;
		     newNode->rightLink=temp;
		     temp->leftLink=newNode;
		     first=newNode;
		  }else{
		     newNode->leftLink=temp->leftLink;
		     newNode->rightLink=temp;
		     newNode->leftLink->rightLink=newNode;
		     temp->leftLink=newNode;
		  }

	       }else if(choice=='R'||choice=='r'){
		  newNode->leftLink=temp;
		  newNode->rightLink=temp->rightLink;
		  temp->rightLink=newNode;
		  newNode->rightLink->leftLink=newNode;
	       }else{
		  cout<<"\nWrong Input!";
	       }
	       return;
	     }
	     temp=temp->rightLink;
	  }
	  cout<<"\nNo Elements of the search data found!";
       }
       void removeFromList(){
	  DLinkList *temp;
	  temp=first;
	  if(temp==NULL){
	     cout<<"\nThe List is Empty:";
	     return;
	  }
	  cout<<"\nEnter a data to search and remove in the list";
	  int searchData;
	  cin>>searchData;
	  while(temp!=NULL){
	     if(temp->data==searchData){
	       if((temp->leftLink==NULL)&&(temp->rightLink==NULL)){
		  first=NULL;
		  delete temp;
		  cout<<"\nSuccessfully deleted the data!";
	       }else if(temp->leftLink==NULL){//for the first node
		  temp->rightLink->leftLink=NULL;
		  first=temp->rightLink;
		  delete temp;
		  cout<<"\nSuccessfully deleted the data!";
	       }else if(temp->rightLink==NULL){
		  temp->leftLink->rightLink=NULL;
		  delete temp;
		  cout<<"\nSuccessfully deleted the data!";
	       }else{
		  temp->leftLink->rightLink=temp->rightLink;
		  temp->rightLink->leftLink=temp->leftLink;
		  delete temp;
		  cout<<"\nSuccessfully deleted the data!";
	       }
	       return;
	     }
	     temp=temp->rightLink;
	  }
	  cout<<"\nNo Elements of the search data found!";
       }

       void showList(){
	  DLinkList *temp;
	  temp=first;
	  cout<<"\nThe List Contains Elements:";
	  if(temp==NULL)cout<<"\n\tList is Empty";
	  while(temp!=NULL){
	     cout<<"\n\t"<<temp->data;
	     temp=temp->rightLink;
	  }
	  cout<<"\nEnd of List";

       }
};
void main(){
   int choice;
   List l;
   do{
      clrscr();
      cout<<"Double Linked List\n";
      cout<<"\nPress 1 for Insert data in List";
      cout<<"\nPress 2 for Remove data from list";
      cout<<"\nPress 3 to Show the list";
      cout<<"\nPress 4 to Exit";
      cout<<"\nEnter Your Choice:";
      cin>>choice;
      switch(choice){
	 case 1:
	    l.insertByData();
	    getch();
	    break;
	 case 2:
	    l.removeFromList();
	    getch();
	    break;
	 case 3:
	    l.showList();
	    getch();
	    break;
	 default :
	    cout<<"\nWrong Selection,Try again.";
      }

   }while(choice!=4);
}