#include <stdio.h>

/*
 *
 *
 *
 */

int main(void) 
{
	int choice;
	double a, b;
	double result;

	do 
	{
		/*Display calculator menu*/	
		printf("\nWelcome to the calculator app!\n");
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
			while (getchar() != '\n')
				continue;
		}	

		/*next check the interger is within the option range 0-4*/
		if (choice < 0 || choice > 4)
		{	
			printf("invalid niput. Please enter a number from 0-4.\n");
			continue;
		}

		/*Addition program*/		
		if (choice == 1)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);

			result = a + b;
			printf("Result: %.2f\n", result);

		}

		/*Subtraction program*/		
		if (choice == 2)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);

			result = a - b;
			printf("Result: %.2f\n", result);

		}


		/*Multiplication program*/		
		if (choice == 3)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);

			result = a * b;
			printf("Result: %.2f\n", result);

		}



		if (choice == 0)
			{	
			printf("Bye for now!\n");	
 			}


} while(choice != 0);/*Keep looping until exit is selected*/
		
	return(0);	
}		
