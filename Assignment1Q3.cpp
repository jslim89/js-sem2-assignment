#include <stdio.h>
#include <stdlib.h> // for 'exit(-1)' & 'system("CLS");
#include <time.h>	// use for generate random number
#include <ctype.h>
#include <conio.h>	// use for 'getch();'

// function declaration
int Multiplication();
int Division();
int Addition();
int Subtraction();
void output(int);
void Quit(int,int,int,int,int);
void random(int*,int*);

void main()	// main function
{
	int menu, result[100], total=0, count=0;
	char con;
	struct tm time;
		_getsystime(&time);
	int hr, min, sec;

	hr = time.tm_hour;
	min = time.tm_min;
	sec = time.tm_sec;

	int i=0;
	do
	{
		// Menu
		system("CLS");
		printf("_-_-_-_Menu_-_-_-_\n"
			   "[1] Multiplication\n"
			   "[2] Division\n"
			   "[3] Addition\n"
			   "[4] Subtraction\n"
			   "[5] Quit\n\n");

		printf("Choose a selection > ");
		scanf("%d",&menu);

		switch(menu)	// switch statement
		{
		case 1:
			{
				result[i] = Multiplication();	// function call Multiplication();
				output(result[i]);	// function call output();
				count++;	// the times of test
				break;
			}
		case 2:
			{
				result[i] = Division();	// function call Division();
				output(result[i]);	// function call output();
				count++;	// the times of test
				break;
			}
		case 3:
			{
				result[i] = Addition();	// function call Addition();
				output(result[i]);	// function call output();
				count++;	// the times of test
				break;
			}
		case 4:
			{
				result[i] = Subtraction();	// function call Subtraction();
				output(result[i]);	// function call output();
				count++;	// the times of test
				break;
			}
		case 5:
			{
				Quit(total,count,hr,min,sec);	// function call Quit();
				break;
			}
		default:
			{
				printf("Invalid Input! Please re-enter\n");
				main();	// re-run the main function
			}
			i++;
		}
		total = total + result[i];	// sum all the tests' marks
		// ask for user want to continue the test or not
		printf("Do you want to continue? (Y/N) ");
		fflush(stdin);
		scanf("%c",&con);
		toupper(con);
		while(con!='Y' && con!='N' && con!='y' && con!='n')
			{
				printf("Invalid Input! Please re-enter (Y/N)> ");
				fflush(stdin);
				scanf("%c",&con);
				toupper(con);
			}
	}while(con == 'Y' || con=='y');
	Quit(total,count,hr,min,sec);	// Print out the total result & Quit the program
}

int Multiplication()	// function definition
{
	system("CLS");	// clear the screen
	int ans, corr=0, multiple, ran1, ran2, i=0;

	srand(time(NULL));	// generate random number by follow the time
	for(i=0;i<10;i++)
	{
		ran1 = 100;	// initialize the range of random number
		ran2 = 10;	// initialize the range of random number
		random(&ran1,&ran2);	// bring down the range & point back the number
		multiple = ran1 * ran2;	// process

		printf("Question %d:\n",i+1);
		printf("%d x %d = ",ran1,ran2);
		scanf("%d",&ans);	// ask for user enter the number

		if(ans == multiple)
		{
			printf("Your answer is correct!\n\n");
			corr++;	// count the question of correct
		}
		else
			printf("Your answer is incorrect!\n\n");
	}
	printf("You have answer correct %d question(s)\n",corr);
	return(corr * 5);	// return the points to main function
}

int Division()	// function
{
	system("CLS");	// clear screen
	int ans, corr=0, divide, ran1, ran2, i=0;
	const int a=1000, b=10;

	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		ran1 = 1000;
		ran2 = 10;
		random(&ran1,&ran2);
		// make the number can be don't have ramaining
		divide = ran1 / ran2;
		ran1 = divide * ran2;

		printf("Question %d:\n",i+1);
		printf("%d / %d = ",ran1,ran2);
		scanf("%d",&ans);

		if(ans == divide)
		{
			printf("Your answer is correct!\n\n");
			corr++;
		}
		else
			printf("Your answer is incorrect!\n\n");
	}
	printf("You have answer correct %d question(s)\n",corr);
	return(corr * 5);
}

int Addition()
{
	system("CLS");
	int ans, corr=0, add, ran1, ran2, i=0;

	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		ran1 = ran2 = 100;
		random(&ran1,&ran2);

		add = ran1 + ran2;

		printf("Question %d:\n",i+1);
		printf("%d + %d = ",ran1,ran2);
		scanf("%d",&ans);

		if(ans == add)
		{
			printf("Your answer is correct!\n\n");
			corr++;
		}
		else
			printf("Your answer is incorrect!\n\n");
	}
	printf("You have answer correct %d question(s)\n",corr);
	return(corr * 5);
}

int Subtraction()
{
	system("CLS");
	int ans, corr=0, sub,biggest,smallest, ran1, ran2, i=0;
	
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		ran1 = ran2 = 100;
		random(&ran1,&ran2);
		// make the subtraction of numbers do not come out negative answer
		if(ran1>ran2)
		{
			biggest = ran1;
			smallest = ran2;
		}
		else{
			biggest = ran2;
			smallest =ran1;
		}
		sub = biggest - smallest;

		printf("Question %d:\n",i+1);
		printf("%d - %d = ",biggest,smallest);
		scanf("%d",&ans);

		if(ans == sub)
		{
			printf("Your answer is correct!\n\n");
			corr++;
		}
		else
			printf("Your answer is incorrect!\n\n");
	}
	printf("You have answer correct %d question(s)\n",corr);
	return(corr * 5);
}

void Quit(int total, int count, int hr, int min, int sec)
{
	char name[30];
	double avr;
	struct tm dt;
		_getsystime(&dt);
	int used_hr, used_min, used_sec;

	printf("Enter your name: ");
	fflush(stdin);
	gets(name);
	system("CLS");

	avr = total / count;	// calculate the average point between all the test
	// print out all the result of user
	printf("Your result printed on %02d/%02d/%d ",dt.tm_mday,dt.tm_mon,dt.tm_year +1900);
	if(dt.tm_hour>=12)
		if(dt.tm_hour == 12)
			printf("at %02d:%02d:%02d pm\n",dt.tm_hour,dt.tm_min,dt.tm_sec);
		else
			printf("at %02d:%02d:%02d pm\n",dt.tm_hour-12,dt.tm_min,dt.tm_sec);
	else
		printf("at %02d:%02d:%02d am\n",dt.tm_hour,dt.tm_min,dt.tm_sec);
	if(dt.tm_hour < hr)
		used_hr = (24-hr) + dt.tm_hour;
	else
		used_hr = dt.tm_hour - hr;
	if(dt.tm_min < min)
		used_min = min - dt.tm_min;
	else
		used_min = dt.tm_min - min;
	if(dt.tm_sec < sec)
		used_sec = sec - dt.tm_sec;
	else
		used_sec = dt.tm_sec - sec;
	printf("Name            : %s\n",name);
	printf("You have entered %d test.\n",count);
	printf("Total points    = %d\n",total);
	printf("Average points  = %.2lf\n\n",avr);
	printf("You have used %02d hour(s) %02d minute(s) %02d second(s) to enter %d test(s)\n\n",
		used_hr,used_min,used_sec,count);
	printf("~~Thanks for using this program~~\n\n");
	exit(-1);
}

void output(int point)
{	// print out the result every test
	printf("Your result: %d points\n\n",point);
	printf("Press any key to continue\n");
	getch();
	system("CLS");
}

void random(int *num1,int *num2)
{	// generate 2 random number & pass it to every test
	*num1 = rand()%*num1+1;
	*num2 = rand()%*num2+1;
}
