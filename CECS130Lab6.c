/*
Name: Cameron Simcoe
CECS130: Lab 6
Section: 1
Date: 9/25/2020
Description: The code for a phone book using structures and dynamic memory
*/


#include <stdio.h>
#include <stdlib.h>

struct stPhoneBook
{
	char scFirstName[20];
	char scLastName[20];
	int iPhoneNum;
};

//Code for exiting function
void exiting()
{
	printf("\nExiting Phone Book. Goodbye!");	
}

int main() 
{
	int iPhoneOp;
	struct stPhoneBook contact;
	int x;
	
	do
	{
		//Code for phone menu
		printf("Phone Menu:\n1. Add Contact\n2. Delete Contact\n3. Show Phone Book\n4. Exit Phone Menu");
		printf("\nPlease choose an option: ");
		scanf("%d",&iPhoneOp);
		switch(iPhoneOp)
		{
			case 1:
				printf("First Name: ");
				scanf("%s",contact.scFirstName);
				printf("Last Name: ");
				scanf("%s",contact.scLastName);
				printf("Phone Number: ");
				scanf("%d",&contact.iPhoneNum);
				printf("Contact added to phone book\n\n");
				break;
				case 2:
					printf("Nothing here for now");
					break;
					case 3: 
						printf("Phone Book Entries:\n");
						break;
						case 4:
							exiting();
							break;
							default:
								printf("\nInvalid choice. Please try again\n\n");
				
		}
		
	}while (iPhoneOp != 4);//End of do/while loop
	
	return 0;
}//End of main function

