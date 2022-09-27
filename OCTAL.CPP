#include<iostream.h>
#include<conio.h>
#include<math.h>

class octal
{
int oct[15],a[15],count;
public:
octal(int x);
int operator+(int k);
friend ostream & operator<<(ostream &,octal&);
};
octal::octal(int x)
{
int rem,j=0,i=0;
while(x!=0)
{
 rem=x%8;
 x=x/8;
 a[i++]=rem;
 }
 count=i-1;
 for(i=count;i>=0;i--)
{
oct[j]=a[i];
j++;
}
/*cout<<"\t";
//for(i=0;i<=count;i++)
//{
cout<<oct[i];
}*/
}
int octal::operator +(int k)
{
int x=0,i,j=count;
for(i=0;i<=count;i++)
{
x=x+oct[j]*pow(8,i);
 j--;
 }
 return(x+k);
  }
ostream& operator<<(ostream&out,octal&o)
  {
  int i;
  for(i=0;i<=o.count;i++)
  {
  out<<o.oct[i];
  }
  return(out);
  }
void main()
{
int x,k;
clrscr();
cout<<"enter the number";

cin>>x;
cout<<"enter the number to be added";
cin>>k;
octal h =octal(x);
cout<<"the octal value is"<<h<<endl;
cout<<(x+k);
getch();
}

