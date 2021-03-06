/*
Name: Cameron Simcoe
CECS130: Lab 6
Section: 1
Date: 9/25/2020
Description: The code for a phone book using structures and dynamic memory
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
        char scFirstName[20];
        char scLastName[20];
        long long int lliPhoneNum;
} stPhoneBook;

//Code for add contact function
void addcontact(stPhoneBook  *contact)
{
         printf("First Name: ");
         scanf("%s",contact->scFirstName);
         printf("Last Name: ");
         scanf("%s",contact->scLastName);
         printf("Phone Number: ");
         scanf("%lli",&(contact->lliPhoneNum));
         printf("\nContact added to phone book\n\n");
}//End of add contact function

//Code for delete contact function
stPhoneBook* deletecontact(stPhoneBook* a, int size, char sDelLname[20])
{
        int x = 0;
        while (x < size && strcmp(a[x].scLastName, sDelLname) != 0) x++;
        stPhoneBook *temp = (stPhoneBook *)malloc((size - 1) * sizeof(stPhoneBook));
        if (x != 0)
        {
                memcpy(temp, a, x * sizeof(stPhoneBook));
        }
        if (x != (size - 1))
        {
                memcpy(temp+x, a+x+1, (size-x-1) * sizeof(stPhoneBook));
        }
        free(a);
        return temp;
}


//Code for exiting function
void exiting()
{
        printf("\nExiting Phone Book. Goodbye!");
}//End of exiting function code

int main()
{
        char LastNameD[20];
        int iPhoneOp;
        int inumContacts = 0;
        stPhoneBook * aContacts  = (stPhoneBook *)malloc(inumContacts * sizeof(stPhoneBook));
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
                                inumContacts ++;
                                stPhoneBook *temp;
                                temp = (stPhoneBook *)realloc(aContacts, inumContacts * sizeof(stPhoneBook));
                                if (temp == NULL)
                                        printf("\n\n Reallocation failed. Out of memory!\n");
                                else
                                {
                                        aContacts = temp;
                                }
                                stPhoneBook contact1 = {"", "", 0};
                                stPhoneBook *ptrContact;
                                ptrContact = &contact1;
                                addcontact(ptrContact);
                                aContacts[inumContacts - 1] = contact1;
                                break;
                                case 2:
                                        printf("Enter last name of contact you would like to delete: \n");
                                        scanf("%s",LastNameD);
                                        aContacts = deletecontact(aContacts, inumContacts, LastNameD);
                                        inumContacts--;
                                        break;
                                        case 3:
                                                printf("Phone Book Entries:\n");
                                                for (x = 0; x < inumContacts; x++) {
                                                        stPhoneBook obj = aContacts[x];
                                                        printf("\n Name: %s %s\n", obj.scFirstName, obj.scLastName);
                                                        printf("Phone Number: %lli\n\n", obj.lliPhoneNum);
                                                }
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
