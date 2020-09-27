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
	long long int lliPhoneNum;
	char scFirstNameD[20];
	char scLastNameD[20];
};

//Code for exiting function
void exiting()
{
	printf("\nExiting Phone Book. Goodbye!");	
}//End of exiting function code

int main() 
{
	int iPhoneOp;
	struct stPhoneBook *aPhoneContact = (struct stPhoneBook *)malloc(sizeof(struct stPhoneBook));
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
				scanf("%s",aPhoneContact->scFirstName);
				printf("Last Name: ");
				scanf("%s",aPhoneContact->scLastName);
				printf("Phone Number: ");
				scanf("%lli",&(aPhoneContact->lliPhoneNum));
				printf("\nContact added to phone book\n\n");
				break;
				case 2:
					printf("Nothing here for now");
					break;
					case 3: 
						printf("Phone Book Entries:\n");
						printf("%s %s %lli\n\n",aPhoneContact->scFirstName,aPhoneContact->scLastName,aPhoneContact->lliPhoneNum);
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

