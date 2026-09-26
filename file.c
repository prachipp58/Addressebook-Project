#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
	FILE *fptr = fopen("contacts.txt", "w");
    if (fptr == NULL)
    {
        printf("Error: could not open data.txt for writing.\n");
        return;
    }

    fprintf(fptr, "#%d#\n", addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) {
	FILE *fptr = fopen("contacts.txt", "r");
    if (fptr == NULL)
    {
        printf("Error: could not open data.txt for reading.\n");
        addressBook->contactCount = 0;
        return;
    }

    if (fscanf(fptr, "#%d#\n", &addressBook->contactCount) != 1)
    {
        printf("Error: could not read contact count from file.\n");
        addressBook->contactCount = 0;
        fclose(fptr);
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (fscanf(fptr, "%29[^,],%14[^,],%49[^\n]\n",
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email) != 3)
        {
            printf("Error: file format invalid at contact %d.\n", i + 1);
            addressBook->contactCount = i;   // only keep what was successfully loaded
            break;
        }
    }

    fclose(fptr);
}
