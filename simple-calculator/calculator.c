#include <stdio.h>

/*
 *
 *
 *
 */

int main(void) 
{
	int choice;
	
	
	do 
	{
		/*Display calculator menu*/	
		printf("\nWelccome to the calculator app!\n");
		printf("1. Add\n");
		printf("2. Subtract\n");
		printf("3. Multiply\n");
		printf("4. Divide\n");
		printf("0. Quit\n");

		/*Input from user, Ensure input used is an interger*/
		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input. Please enter a number.\n");
			/*Clear invalid input*/
			while (getchar() != '\n')/*clear input*/
 			continue;
		}	

		/*next check the interger is within the option range 0-4*/
		if (choice < 0 || choice > 4)
		{
			printf("invalid niput. Please enter a number from 0-4.\n");
			continue;
		}


		if (choice == 0)
		{
			printf("Bye for now!\n");	
 		}


	} while(choice != 0);/*Keep looping until exit is selected*/
		
	return(0);	
}		
