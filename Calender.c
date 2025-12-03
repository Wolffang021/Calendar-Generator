#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ddate 1
#define dmonth 13
//#define RED \033[1;31m
//#define RESET \033[0m

void printcalendar(int dweekday,int leapyear) {
	int i,j,k,count;
	const char* month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	const char* weekday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	int monthlength[]={31,28,31,30,31,30,31,31,30,31,30,31};

	if(leapyear) {
		monthlength[1]=29;
	}
	for(i=0;i<12;i++) {
		printf("\n-------- %s --------\n\n",month[i]);
		for(j=0;j<7;j++) {
			printf(" %s",weekday[j]);
		}
		printf("\n");
		count=1;
		for(j=1;j<=monthlength[i];j++) {
			if(count>7) {
				printf("\n");
				count=1;
			}
			if(j==1) {
				while(dweekday) {
					printf("    ");
					count++;
					dweekday--;
				}
			}
			if(j<10) {
				printf(" ");
			}
			printf("  %d",j);
			count++;
			dweekday=(count-1)%7;
		}
		printf("\n\n");
	}
}

int checkleapyear(int year) {
	if(year%4==0||(year%400==0&&year%100!=0))
		return 1;
	else
		return 0;
}

int calculatejan1(int year) {
	int dweekday;
	year--;
	dweekday=(ddate+((13*(dmonth+1))/5)+(year%100)+((year%100)/4)+5-(year/100))%7;	//Zeller's Congruence
	return dweekday;
}

int main(void) {
	int year,dweekday,leapyear;
	printf("Enter year: ");
	scanf("%d",&year);
	dweekday=calculatejan1(year);
	leapyear=checkleapyear(year);
	printcalendar(dweekday,leapyear);
	system("pause");
	return 0;
}
