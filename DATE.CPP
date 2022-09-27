#include<iostream.h>
#include<conio.h>

class Date{
	int day,month,year;
	int refYear;
	int monthDays[11];//{31,28,31,30,31,30,31,31,30,31,30,31};

	int isValidDate(Date d){
	    if(d.year<refYear)return 0;
	    else if((d.month>12)||(d.month<1))return 0;
	    else if((d.day<1)||(d.day>monthDays[d.month-1]))return 0;
	    else return 1;
	}
	int isValidDate(int day,int month,int year){
	    if(year<refYear)return 0;
	    else if((month>12)||(month<1))return 0;
	    else if((day<1)||(day>monthDays[month-1]))return 0;
	    else return 1;
	}
	int getDateValue(){
	    int dateValue=0;
	    int yearDif=year-refYear;
	    dateValue=(yearDif*365)+((yearDif-1)/4);
	    for(int i=0;i<(month-1);i++)
		dateValue=dateValue+monthDays[i];
	    dateValue=dateValue+day+((((yearDif%4)==0)&&(month>4))?1:0);
	    return dateValue;
	}
	Date getDate(int dValue){
	    int dateValue=0,yearCount=0;
	    int i=1;
	    for(i=1;dateValue<dValue;i++){
		dateValue=(dateValue+365)+(((i%4)==0)?1:0);
		yearCount++;
		if(dateValue>=dValue)
		    yearCount--;
	    }
	    dateValue=(dateValue-365)-((((i-1)%4)==0)?1:0);
	    yearCount=yearCount+refYear;

	    dateValue=dValue-dateValue;
	    int monthValue=0;
	    int monthCount=0;
	    int dayCount=0;
	    for(i=0;i<12;i++){
		monthValue=monthValue+monthDays[i];
		if(monthValue>=dateValue){
		    monthCount=i+1;
		    monthValue=monthValue-monthDays[i];
		    dayCount=dateValue-monthValue;
		    break;
		}
	    }
	    Date d(dayCount,monthCount,yearCount);
	    return d;
	}

	public:

	Date(){
		monthDays[0]=31;monthDays[1]=28;monthDays[2]=31;monthDays[3]=30;
		monthDays[4]=31;monthDays[5]=30;monthDays[6]=31;monthDays[7]=31;
		monthDays[8]=30;monthDays[9]=31;monthDays[10]=30;monthDays[11]=31;
		day=0;month=0;year=0;
		refYear=1952;
	}
	Date(int pDay,int pMonth,int pYear){
		monthDays[0]=31;monthDays[1]=28;monthDays[2]=31;monthDays[3]=30;
		monthDays[4]=31;monthDays[5]=30;monthDays[6]=31;monthDays[7]=31;
		monthDays[8]=30;monthDays[9]=31;monthDays[10]=30;monthDays[11]=31;
		day=pDay;month=pMonth;year=pYear;
		refYear=1952;
	}
	int operator-(Date d){
	    return(this->getDateValue()-d.getDateValue());
	}
	Date operator+(int duration){
	    return (this->getDate(this->getDateValue()+duration));
	}
	friend ostream& operator<<(ostream& print,Date &d){
	    print<<"\n   "<<d.day<<"/"<<d.month<<"/"<<d.year;
	    return print;
	}
	void setDate(int pDay,int pMonth,int pYear){
	    if(isValidDate(pDay,pMonth,pYear)){
		day=pDay;
		month=pMonth;
		year=pYear;
	    }
	}
};

void main(){
	int day=0,month=0,year=0;
	clrscr();
	cout<<"\n   Enter First Date in dd/mm/yyyy format:\n   ";
	cin>>day;cout<<"   ";cin>>month;cout<<"   ";cin>>year;
	Date d1;d1.setDate(day,month,year);
	int duration;
	cout<<"\n   Enter the Duration for adding to the first Date:\n   ";
	cin>>duration;
	cout<<"\n   The Date after addition :"<<(d1+duration);
	cout<<"\n   Enter Second Date in dd/mm/yyyy format:\n   ";
	cin>>day;cout<<"   ";cin>>month;cout<<"   ";cin>>year;
	Date d2;d2.setDate(day,month,year);
	cout<<"\n   The First date minus Second date"<<(d1-d2);
	getch();
}