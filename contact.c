#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook/*, int sortCriteria*/) 
{
    for(int i=0;i<addressBook->contactCount;i++){
        printf("%-20s %-15s %-25s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
    
}   



void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
   loadContactsFromFile(addressBook);
   }
 

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{   
    #include <ctype.h>
    char name[100],phone[11],email[100];
	printf("Enter the name: ");
    getchar();
    scanf("%[^\n]",name);
    
    check: int valid=1;
    for(int i=0;i<strlen(name);i++){
     if (isdigit(name[i])){
        
        valid=0;
        break;}
    }
    while (valid==0)
    {
        printf("Enter a valid name: ");
        getchar();
        scanf("%[^\n]",name);
        goto check;
    }
    printf("Enter the phone number: ");
    getchar();
    scanf("%[^\n]",phone);
    
    checknum:
    valid=1;
    if(strlen(phone)!=10)
        valid=0;

    {for(int i=0;i<strlen(phone);i++){
     if (!isdigit(phone[i])){
        
        valid=0;
        break;}
    }}
    
    
    if (valid==1)
    {
     for(int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcmp(addressBook->contacts[i].phone,phone) == NULL) {
                printf("Duplicate phone ! Enter a unique Phone number\n ");
                valid=0; 
                break;
            }
            
        }}
    
    
    while (valid==0)
    {
        printf("Enter a valid phone number: ");
        getchar();
        scanf("%[^\n]",phone);
        goto checknum;
    }
    
    printf("Enter the email: ");
    getchar();
    scanf("%[^\n]",email);
    
    
    checkmail:
    valid=1;
    if (strchr(email,'@')==NULL||strstr(email,".com")==NULL)
        valid=0;
    
    if (valid==1)
    {
     for(int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcmp(addressBook->contacts[i].email,email) == NULL) {
                printf("Duplicate mail ! Enter a unique email\n ");
                valid=0; 
                break;
            }
            
        }}
    
    while (valid==0)
    {
        printf("Enter a valid email: ");
        getchar();
        scanf("%[^\n]",email);
        goto checkmail;
    }
    int i = addressBook->contactCount;
    strcpy(addressBook->contacts[i].name, name);
    strcpy(addressBook->contacts[i].phone, phone);
    strcpy(addressBook->contacts[i].email, email);
    addressBook->contactCount++;
    
    
    
}

void searchContact(AddressBook *addressBook) 
{
    int choice;
    int flag=0;
    printf("Search contact\n");
    printf("1.Search by Name\n");
    printf("2.Search by Phone\n");
    printf("3.Search by email\n");
    scanf("%d",&choice);
    getchar();
    switch (choice)
    {
    case 1:
        char name[50];
        printf("Enter the name of the contact\n");
        scanf(" %[^\n]",name);
        
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcasestr(addressBook->contacts[i].name,name) != NULL) {
                flag=1;
                printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            
        }
        
        if (flag==0)
        printf("Match not found");
        
        break;
    case 2:
        char phone[20];
        printf("Enter the phone number of the contact\n");
        scanf("%s",phone);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            
            if (strcmp(addressBook->contacts[i].phone,phone)==0)
            {   flag=1;
                printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            
        }
        if (flag==0)
        printf("Match not found");
        


        break;
    case 3:
        char email[50];
        printf("Enter the email of the contact\n");
        scanf("%s",email);
        getchar();
        
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            
            if (strcmp(email,addressBook->contacts[i].email)==0)
            {   flag=1;
                printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            
        }
        if (flag==0)
        printf("Match not found");
        
        break;   
    
    default:
        break;
    }
}

void editContact(AddressBook *addressBook)
{
    char name[50];
    printf("Enter the name of the contact\n");
    scanf(" %[^\n]",name);
    int found[100],foundCount=0,idx=1;
    for (int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcasestr(addressBook->contacts[i].name,name) != NULL) {
                printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                found[foundCount++]=i;
            }
            
        }
        if (!foundCount)
        {
            printf("No match found");
        }
    if (foundCount>1)
    {
        printf("Choose index of contact to edit:\n");
        scanf("%d",&idx);


    }

    int i=found[idx-1];
        
        
    int choice;
    printf("\nEditing contact: %s\n", addressBook->contacts[i].name);
    printf("1. Edit Name\n");
    printf("2. Edit Phone\n");
    printf("3. Edit Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        char name[50];
        printf("Enter new name: ");
        scanf(" %[^\n]", name);
        check: int valid=1;
        for(int i=0;i<strlen(name);i++){
        if (isdigit(name[i])){
        
        valid=0;
        break;}
        }
        while (valid==0)
        {
        printf("Enter a valid name: ");
        getchar();
        scanf("%[^\n]",name);
        goto check;
        }
        strcpy(addressBook->contacts[i].name, name);
        break;
    case 2:
        char phone[20];
        printf("Enter new phone: ");
        scanf("%s",phone);
    
    checknum:
    valid=1;
    if(strlen(phone)!=10)
        valid=0;

    {for(int i=0;i<strlen(phone);i++){
     if (!isdigit(phone[i])){
        
        valid=0;
        break;}
    }}
    
    
    if (valid==1)
    {
     for(int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcmp(addressBook->contacts[i].phone,phone) == NULL) {
                printf("Duplicate phone ! Enter a unique Phone number\n ");
                valid=0; 
                break;
            }
            
        }}
    
    
    while (valid==0)
    {
        printf("Enter a valid phone number: ");
        getchar();
        scanf("%[^\n]",phone);
        goto checknum;
    }
        strcpy(addressBook->contacts[i].phone, phone);

        break;
    case 3:
        char email[50];
        printf("Enter new email: ");
        scanf("%s",email);
        checkmail:
        valid=1;
        if (strchr(email,'@')==NULL||strstr(email,".com")==NULL)
        valid=0;
    
        if (valid==1)
        {
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcmp(addressBook->contacts[i].email,email) == NULL) {
                printf("Duplicate mail ! Enter a unique email\n ");
                valid=0; 
                break;
            }
            
        }}
    
        while (valid==0)
        {
        printf("Enter a valid email: ");
        getchar();
        scanf("%[^\n]",email);
        goto checkmail;
        }
        strcpy(addressBook->contacts[i].email, email);
        break;
        default:
        printf("Invalid option.\n");
        return;
    }

    printf("\nContact updated\n");
    printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
}

    


void deleteContact(AddressBook *addressBook)
{
	
    char name[50];
    printf("Enter the name of the contact\n");
    scanf(" %[^\n]",name);
    int found[100],foundCount=0,idx=1;
    for (int i = 0; i < addressBook->contactCount; i++)
        {
            
           if (strcasestr(addressBook->contacts[i].name,name) != NULL) {
                printf("%s\t\t%s\t\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                found[foundCount++]=i;
            }
            
        }
        if (!foundCount)
        {
            printf("No match found");
        }
        else {if (foundCount>1)
        {
        printf("Choose index of contact to delete:\n");
        scanf("%d",&idx);


        }

        int i=found[idx-1];
        for (i; i < addressBook->contactCount; i++)
        {
        strcpy(addressBook->contacts[i].name, addressBook->contacts[i+1].name);
        strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
        strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);}
    addressBook->contactCount--;
        }
}
