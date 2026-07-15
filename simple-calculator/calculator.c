#include <stdio.h>

/*
 *
 *
 *
 */

int main() 
{
	int choice;
	
	
	do 
	{
	//Display calculator menu	
	printf("\nWelccome to the calculator app!\n");
	printf("1\) Add\n");
	printf("2\) Subtract\n");
	printf("3\) Multiply\n");
	printf("4\) Divide\n");
	printf("0\) Quit\n");

	if (choice == 0)
		{
		printf("Bye for now!\n")	
 		}

	} while(choice != 0);//keep looping until exit is selcted
		
	return(0)	
}		
