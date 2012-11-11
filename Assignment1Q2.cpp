#include <stdio.h>
#include <string.h>	// use string function
#include <stdlib.h>
#include <time.h>
// define constant
#define MOUNTAIN 269.95
#define STREET 149.50
// type define structure
typedef struct {
	char cusName[50];
	char cusAdd[50];
	int order;
	char type;
	char ctworth;
	float dollar;
}customer;	// structure name
// function declaration
int input(int,int);
int output(int , int);
void dosOutput(int);
int scanOld();
void DateTime();
// global variable
customer cus[100];

void main()	// main function
{
	int n, num, i=0;

	// function call
	n = scanOld();
	n++;
	num = input(n,i);
	dosOutput(num);
	printf("\n");
}
// function definition
int input(int n, int i)
{	// prompt all the input from user
	int j, num=0;
	char choice, save;

	do
	{
		printf("Customer Name > ");
		fflush(stdin);
		scanf("%[^\n]", cus[i].cusName);
	
		printf("Customer Address > ");
		fflush(stdin);
		scanf("%[^\n]", cus[i].cusAdd);

		printf("Amount to order (DIGIT ONLY)> ");
		fflush(stdin);
		scanf("%d",&cus[i].order);

		for(j=0;cus[i].type != 'M' && cus[i].type != 'm' && cus[i].type != 'S' && cus[i].type != 's' ; j++)
		{
			printf("Type of Bicycle (M/S) > ");
			fflush(stdin);
			scanf("%c",&cus[i].type);

			if(cus[i].type != 'M' && cus[i].type != 'm' && cus[i].type != 'S' && cus[i].type != 's')
				printf("\aInvalid input! Please re-enter\n");
		}

		if(cus[i].type == 'M' || cus[i].type =='m')
			cus[i].dollar = (float)MOUNTAIN * cus[i].order;

		else if(cus[i].type == 'S' || cus[i].type =='s')
			cus[i].dollar = (float)STREET * cus[i].order;


		for(j=0;cus[i].ctworth != 'Y' && cus[i].ctworth != 'y' && cus[i].ctworth != 'N' && cus[i].ctworth != 'n' ; j++)
		{
			printf("Creditworthiness (Y/N) > ");
			fflush(stdin);
			scanf("%c",&cus[i].ctworth);

			if(cus[i].ctworth != 'Y' && cus[i].ctworth != 'y' && cus[i].ctworth != 'N' && cus[i].ctworth != 'n')
				printf("\aInvalid input! Please re-enter\n");
		}

		printf("\n\nDo you want keep this customer record into shipping.txt? (Y/N) > ");
		fflush(stdin);
		scanf("%c",&save);
		while(save != 'Y' && save != 'y' && save != 'N' && save != 'n')
		{
			printf("\aInvalid Input! Please re-enter (Y/N) > ");
			fflush(stdin);
			scanf("%c",&save);
		}
		if(save == 'Y' || save == 'y')
		{
			n = output(n,i);
		}
		printf("\nEnter another customer details? (Y/N) > ");
		fflush(stdin);
		scanf("%c",&choice);
		while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			printf("\aInvalid Input! Please re-enter (Y/N) > ");
			fflush(stdin);
			scanf("%c",&choice);
		}
	i++;
	num++;
	system("CLS");
	}while(choice == 'Y' || choice == 'y');
	return num;
}

void dosOutput(int num)
{	// print out all the output on screen
	int i;
	DateTime();
	printf("\nCustomer:\n\n");
	for(i=0;i<num;i++)
	{
		printf("Name\t\t\t: %s\n",cus[i].cusName);
		printf("Address\t\t\t: %s\n",cus[i].cusAdd);
		printf("Bicycle ordered\t\t: %d\n",cus[i].order);
			if(cus[i].type == 'M' || cus[i].type == 'm')
				printf("Bicycle type\t\t: %s\n","Mountain");
			else if(cus[i].type == 'S' || cus[i].type == 's')
				printf("Bicycle type\t\t: %s\n","Street");
			
			if(cus[i].ctworth == 'Y' || cus[i].ctworth == 'y')
			{
				printf("Creditworthiness\t: Good\n");
				printf("Dollar value of order\t: RM %.2f\n\n",cus[i].dollar);
				printf("The bill can be paid separately\n\n");
			}
			if(cus[i].ctworth == 'N' || cus[i].ctworth == 'n')
			{
				printf("Creditworthiness\t: Bad\n");
				printf("Dollar value of order\t: RM %.2f\n\n",cus[i].dollar);
				printf("Customer require cash payment on delivery.\n\n");
			}
	}
}

int output(int no, int i)
{	
	FILE *p;	// declare the pointer file
	struct tm dt;
		_getsystime(&dt);	// get the time from system
	p = fopen("shipping.txt","a+");	// open the file

	// print out all the output on shipping.txt

	fprintf(p,"Customer\t%02d\n",no);
	fprintf(p,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fprintf(p,"Purchased on\n");
	// Print out the time of customer purchases
	fprintf(p,"Date: %d/%d/%d\t",dt.tm_mday ,dt.tm_mon,dt.tm_year +1900);
	if(dt.tm_hour >= 12)
		if(dt.tm_hour == 12)
			fprintf(p,"Time: %02d:%02d:%02d pm\n",dt.tm_hour,dt.tm_min,dt.tm_sec);
		else
			fprintf(p,"Time: %02d:%02d:%02d pm\n",dt.tm_hour-12,dt.tm_min,dt.tm_sec);
	else
		fprintf(p,"Time: %02d:%02d:%02d am\n",dt.tm_hour,dt.tm_min,dt.tm_sec);
	fprintf(p,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fprintf(p,"Name\t\t\t: %s\n",cus[i].cusName);
	fprintf(p,"Address\t\t\t: %s\n",cus[i].cusAdd);
	fprintf(p,"Bicycle ordered\t\t: %d\n",cus[i].order);
		if(cus[i].type == 'M' || cus[i].type == 'm')
			fprintf(p,"Bicycle type\t\t: %s\n","Mountain");
		else if(cus[i].type == 'S' || cus[i].type == 's')
			fprintf(p,"Bicycle type\t\t: %s\n","Street");
			
		if(cus[i].ctworth == 'Y' || cus[i].ctworth == 'y')
		{
			fprintf(p,"Creditworthiness\t: Good\n");
			fprintf(p,"Dollar value of order\t: RM %.2f\n\n",cus[i].dollar);
			fprintf(p,"The bill can be paid separately\n\n");
		}
		else if(cus[i].ctworth == 'N' || cus[i].ctworth == 'n')
		{
			fprintf(p,"Creditworthiness\t: Bad\n");
			fprintf(p,"Dollar value of order\t: RM %.2f\n\n",cus[i].dollar);
			fprintf(p,"Customer require cash payment on delivery.\n\n");
		}

	fclose(p);	// close the file
	no++;
	return no;	// return the no. of customer
}

int scanOld()
{	
	int no;
	char nothing[100];
	FILE * old;
	old = fopen("shipping.txt","r");	// open the file
	if(old==NULL){	
		no=0;
	}
	else{
		while(fscanf(old,"%[^\t]",&nothing) != EOF)
		{	// scan old value from shipping.txt
			fscanf(old,"%d",&no);
			fscanf(old,"%[^\n]",&nothing);	
		}
		fclose(old);	// close the file
	}
	return no;
}

void DateTime()	// Get the time from system
{
	struct tm dt;
		_getsystime(&dt);
	// print out the time
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Purchased on %d/%d/%d ",dt.tm_mday ,dt.tm_mon,dt.tm_year +1900);
	if(dt.tm_hour >= 12)
		if(dt.tm_hour == 12)
			printf("Time: %02d:%02d pm\n",dt.tm_hour,dt.tm_min);
		else
			printf("Time: %02d:%02d pm\n",dt.tm_hour-12,dt.tm_min);
	else
		printf("at %02d:%02d am\n\n",dt.tm_hour ,dt.tm_min);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}