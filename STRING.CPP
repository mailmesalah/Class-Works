#include<iostream.h>
#include<conio.h>
#include<string.h>
class string
{
char name[23];
public:
string()
{
name[23]='\0';
}
string(char s[])
{
strcpy(name,s);
}
string (string &s)
{
strcpy(name,s.name);
}
friend string operator+(string s1,string s2);
friend ostream & operator<<(ostream &,string&);
};
string operator+(string s1,string s2)
{
string temp(s1);
strcat(temp.name,s2.name);
return(temp);
}
ostream & operator<<(ostream& out,string& s)
{
out<<"\n\t"<<s.name<<endl;
return(out);
}
void main()
{
clrscr();
string s1("vtu");
string s2("belgaum");
string s3 =s1+s2;
cout<<s1<<s2<<s3;
getch();
}

