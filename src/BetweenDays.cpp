/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int month(int month, int year)
{
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0, i;
	for (i = 0; i<(month - 1); i++)
	{
		if (i == 1)
		{
			if (year % 4 == 0)
				sum += 29;
			else
				sum += 28;
		}
		else
			sum += months[i];
	}
	return(sum);
}
int days(int y1, int y2, int m1, int m2, int d1, int d2)
{
	int i = 0, number = 0;
	for (i = y1; i<y2; i++)
	{
		if (i % 4 == 0)
			number += 366;
		else
			number += 365;
	}
	number = number - month(m1, y1);
	number = number - d1;
	number = number + month(m2, y2);
	number = number + d2;
	if (number<0)  number = number*-1;
	return number;
}


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)	return -1;
	int day1 = 0, year1 = 0, month1 = 0, day2 = 0, month2 = 0, year2 = 0, i = 0, answer = 0, diff = 0;
	struct node *temp;
	temp = date1head;
	while (temp != NULL)
	{
		i++;
		if (i < 3)
		{
			day1 = day1 * 10 + temp->data;
			temp = temp->next;
		}
		if (i > 2 && i < 5)
		{
			month1 = month1 * 10 + temp->data;
			temp = temp->next;
		}
		if (i > 4)
		{
			year1 = year1 * 10 + temp->data;
			temp = temp->next;
		}
	}
	i = 0;
	temp = date2head;
	while (temp != NULL)
	{
		i++;
		if (i < 3)
		{
			day2 = day2 * 10 + temp->data;
			temp = temp->next;
		}
		if (i > 2 && i < 5)
		{
			month2 = month2 * 10 + temp->data;
			temp = temp->next;
		}
		if (i > 4)
		{
			year2 = year2 * 10 + temp->data;
			temp = temp->next;
		}
	}
	//printf("d1=%d,m1=%d,y1=%d,d2=%d,m2=%d,y2=%d", day1, month1, year1, day2, month2, year2);
	if (year2 >= year1)
		return (days(year1, year2, month1, month2, day1, day2)-1);
	else
		return (days(year2, year1, month2, month1, day2, day1)-1);
}