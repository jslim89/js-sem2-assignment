#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	// use for getch();

void main()
{
	int A_Array[5][5], B_Array[5][5], r, c, even=0, odd=0;
	int	Total_Array[5][5]={0}, Total_Array_row[5]={0}, Total_Array_col[5]={0};

	for(r=0;r<5;r++)
	{
		for(c=0;c<5;c++)
		{
			printf("Enter A_Array[%d][%d] > ",r,c);
			scanf("%d",&A_Array[r][c]);
		}
	}
	printf("Press any key to continue B_Array~~");
	getch();
	system("CLS");

	for(r=0;r<5;r++)
	{
		for(c=0;c<5;c++)
		{
			printf("Enter B_Array[%d][%d] > ",r,c);
			scanf("%d",&B_Array[r][c]);
		}
	}
	printf("Press any key to show all the array~~");
	getch();
	system("CLS");

	printf("\t\tA_Array\n");

	for(c=0;c<5;c++)
		printf("\t%d",c);
	printf("\n");

	for(r=0;r<5;r++)
	{
		printf("%d |",r);

		for(c=0;c<5;c++)
			printf("\t%d",A_Array[r][c]);
		printf("\n");
	}

	printf("\n\t\tB_Array\n");

	for(c=0;c<5;c++)
		printf("\t%d",c);
	printf("\n");

	for(r=0;r<5;r++)
	{
		printf("%d |",r);

		for(c=0;c<5;c++)
			printf("\t%d",B_Array[r][c]);
		printf("\n");
	}

	printf("\n\t\tTotal_Array\n");

	for(c=0;c<5;c++)
		printf("\t%d",c);
	printf("\n");

	for(r=0;r<5;r++)
	{
		printf("%d",r);

		for(c=0;c<5;c++)
		{
			Total_Array[r][c] = A_Array[r][c] + B_Array[r][c];
			printf("\t%d",Total_Array[r][c]);
		}
		printf("\n");
	}
	for(r=0;r<5;r++)
		for(c=0;c<5;c++)
			if(Total_Array[r][c] % 2 == 0)
				even++;
			else
				odd++;

	printf("\nEven Values:\n");
	if(even == 0)
		printf("None\n\n");
	else
	{
		for(r=0;r<5;r++)
			for(c=0;c<5;c++)
				if(Total_Array[r][c] % 2 == 0)
					printf("%d, ",Total_Array[r][c]);
		printf("\b\b  \nThere have %d even value(s)",even);
	}

	printf("\n\nOdd Values:\n");
	if(odd == 0)
		printf("None\n\n");
	else
	{
		for(r=0;r<5;r++)
			for(c=0;c<5;c++)
				if(Total_Array[r][c] % 2 == 1)
					printf("%d, ",Total_Array[r][c]);
		printf("\b\b  \nThere have %d odd value(s)\n\n",odd);
	}

	for(r=0;r<5;r++)
	{
		for(c=0;c<5;c++)
		{
			Total_Array_row[r] = Total_Array_row[r] + Total_Array[r][c];
			Total_Array_col[c] = Total_Array_col[c] + Total_Array[r][c];
		}
	}

	for(r=0;r<5;r++)
		printf("Total_Array row %d is %d\n",r,Total_Array_row[r]);
	printf("\n");
	for(c=0;c<5;c++)
		printf("Total_Array column %d is %d\n",c,Total_Array_col[c]);
	printf("\n");
}