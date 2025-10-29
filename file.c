#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {         //File I/O Program to save the contacts into contacts.txt
    FILE *fp=fopen("contacts.txt","w");
        fprintf(fp,"%d\n",addressBook->contactCount);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        fclose(fp);
    printf("Contacts saved successfully.\n");
  
}

void loadContactsFromFile(AddressBook *addressBook){        //File I/O Program to load the contacts into program from contacts.txt
        FILE *fp=fopen("contacts.txt","r");
        fscanf(fp,"%d\n",&addressBook->contactCount);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        fclose(fp);
        
    }