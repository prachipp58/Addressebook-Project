#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("List of contacts on your addressbook\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
	    printf("-----------------------------------------------------------\n");
	    printf("Name: %s\n",addressBook->contacts[i].name);
	    printf("Phone: %s\n",addressBook->contacts[i].phone);
	    printf("Email: %s\n",addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

int flag;
int validate_name(char name[]);
int validate_phone(char phone[],AddressBook *addressBook);
int validate_email(char email[],AddressBook *addressBook);
void createContact(AddressBook *addressBook)
{
	printf("Enter the name: ");
	do{
		flag=0;
		scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
		char *name = addressBook->contacts[addressBook->contactCount].name;
		flag=validate_name(name);
		if(flag==0)
		{
			printf("The entered name is not valid, Please enter the correct name: ");
		}
	}while(flag==0);

	printf("Enter Phone: ");
	do{
		flag=0;
		scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
		char* phone=addressBook->contacts[addressBook->contactCount].phone;
		flag=validate_phone(phone,addressBook);
		if(flag==1)
                {
                        printf("The entered phone number is not having 10 digits, Please enter the 10 digits number: ");
                }
		if(flag==2)
                {
                        printf("The entered number is containing non digit characters, Please enter the digits: ");
                }
		if(flag==3)
                {
                        printf("The entered number is already present, Please enter unique number: ");
                }
	}while(flag!=0);
       
        printf("Enter Email: ");
	do{
                flag=0;
                scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
                char *email = addressBook->contacts[addressBook->contactCount].email;
                flag=validate_email(email,addressBook);
                if(flag==1)
                {
                        printf("The email should contain '.' and '@', Please enter email with '.' and '@': ");
                }
		if(flag==2)
		{
			printf("The entered email contain '.' before '@', Please enter email with '.' after '@': ");
		}
		if(flag==3)
                {
                        printf("The entered email not contain any character in between'@' and '.', Please enter email with character in between'@' and '.': ");
                }
		if(flag==4)
		{
			printf("The entered email not contain any character after'.', Please enter email with character after '.': ");
		}
		if(flag==5)
		{
			printf("The entered email is already exits, Please enter unique email: ");
		}
        }while(flag!=0);
	(addressBook->contactCount)++;
	printf("Contact added successfully\n");
	printf("-----------------------------------------------------------\n");
}
int Search_name(const char *name, AddressBook *addressBook,int arr[],int*count);
int Search_phone(const char *phone, AddressBook *addressBook);
int Search_email(const char *email, AddressBook *addressBook);
void searchContact(AddressBook *addressBook) 
{
	printf("1. Name\n2. Phone no\n3. Email\n");
	printf("-----------------------------------------------------------\n");
	printf("Enter the option to search: ");
	int opt;
	scanf("%d",&opt);
	char str[30];
	int res;
	switch(opt)
	{
		case 1:
			printf("Enter the name: ");
			scanf(" %[^\n]",str);
			int arr[30],count;
			res=Search_name(str,addressBook,arr,&count);
			if(res==0)
			{
				printf("------------------------------------------------------\n");
				printf("Please enter the correct name\n");
				printf("------------------------------------------------------\n");
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					printf("------------------------------------------------------\n");
					printf("%d.\n", i + 1);
                                        printf("Name: %s\n", addressBook->contacts[arr[i]].name);
                                        printf("Phone: %s\n", addressBook->contacts[arr[i]].phone);
                                        printf("Email: %s\n", addressBook->contacts[arr[i]].email);
                                }
				printf("------------------------------------------------------\n");
				printf("The contact has been found successfully\n");
				printf("------------------------------------------------------\n");
			}
			break;
		case 2:
                        printf("Enter the phone no: ");
                        scanf(" %[^\n]",str);
                        res=Search_phone(str,addressBook);
                        if(res==-1)
                        {
				printf("------------------------------------------------------\n");
                                printf("Phone no. not found\n");
				printf("------------------------------------------------------\n");
                        }
                        else
                        {
				printf("------------------------------------------------------\n");
                                printf("Name: %s\n", addressBook->contacts[res].name);
                                printf("Phone: %s\n", addressBook->contacts[res].phone);
                                printf("Email: %s\n", addressBook->contacts[res].email);
				printf("------------------------------------------------------\n");
                                printf("The contact has been found successfully\n");
				printf("------------------------------------------------------\n");
                        }
                        break;
		case 3:
                        printf("Enter the email: ");
                        scanf(" %[^\n]",str);
                        res=Search_email(str,addressBook);
                        if(res==0)
                        {
				printf("------------------------------------------------------\n");
                                printf("Please enter the correct email\n");
				printf("------------------------------------------------------\n");
                        }
                        else
                        {
				printf("------------------------------------------------------\n");
				printf("Name: %s\n", addressBook->contacts[res].name);
                                printf("Phone: %s\n", addressBook->contacts[res].phone);
                                printf("Email: %s\n", addressBook->contacts[res].email);
				printf("------------------------------------------------------\n");
                                printf("The contact has been found successfully\n");
				printf("------------------------------------------------------\n");

                        }
                        break;
		default:
			printf("The entered option is wrong\n");
	}
}	
void editContact(AddressBook *addressBook)
{
	printf("1. Name\n2. Phone no\n3. Email\n");
	int opt;
	printf("-----------------------------------------------------------\n");
	printf("Select any one option to search for edit: ");
	scanf("%d",&opt);
	char str[30];
	int res=0;
	int idx=-1;
	switch(opt)
	{
		case 1:
			{
			printf("Enter the name: ");
                        scanf(" %[^\n]",str);
			int arr[30],count;
			res=Search_name(str,addressBook,arr,&count);
			if(!res)
			{
				printf("Contact not found\n");
				return;
			}
			if(count==1)
			{
				idx=arr[0];
			}
			else
			{
				printf("Multiple contacts are found with this name, enter phone number to confirm name: ");
				char phone_confirm[30];
				scanf(" %[^\n]",phone_confirm);
				for(int i=0;i<count;i++)
				{
					if(strcmp(phone_confirm,addressBook->contacts[arr[i]].phone)==0)
					{
						idx=arr[i];
						break;
					}
				}
				if(idx==-1)
				{
					printf("No contact matches that phone number\n");
				}
			}
			break;
	                }
		case 2:
			printf("Enter the phone no: ");
			scanf(" %[^\n]",str);
			idx=Search_phone(str,addressBook);
			//printf contact

			break;
		case 3:
			printf("Enter the email: ");
                        scanf(" %[^\n]",str);
                        idx=Search_email(str,addressBook);
                        break;
		default:
			printf("Option is not valid\n");

	}
	if(idx==-1)
	{
		printf("Contact not found\n");
		return;
	}
	
	printf("1. Name\n2. Phone no\n3. Email\n");
	int option;
	printf("-----------------------------------------------------------\n");
	printf("Please select the option which you want to edit: ");
	scanf("%d",&option);
	char new_val[30];
	int ret=0;
	switch(option)
	{
			case 1:
				printf("Enter the name to edit: ");
				scanf(" %[^\n]",new_val);
				ret=validate_name(new_val);
					if(ret)
						strcpy(addressBook->contacts[idx].name,new_val);
					else
						printf("Entered name is not valid");
					break;
			case 2:
				printf("Enter the phone no to edit: ");
                                scanf(" %[^\n]",new_val);
                                ret=validate_phone(new_val,addressBook);
                                        if(ret==0)
                                                strcpy(addressBook->contacts[idx].phone,new_val);
                                        else
                                                printf("Entered phone no is not valid");
                                        break;
			case 3:
				printf("Enter the email to edit: ");
                                scanf(" %[^\n]",new_val);
                                ret=validate_email(new_val,addressBook);
                                        if(ret==0)
                                                strcpy(addressBook->contacts[idx].email,new_val);
                                        else
                                                printf("Entered email is not valid");
                                        break;
			default:
				printf("Invalid option\n");
	}
}
void deleteContact(AddressBook *addressBook)
{
	int opt;
	printf("1. Name\n2. Phone\n3. Email\n");
	printf("-----------------------------------------------------------\n");
	printf("Enter the option to delete the contact: ");
	scanf("%d",&opt);
	char str[30];
	int New_size=0;
	int res=0;
	int idx=-1;
	switch(opt)
	{
		case 1:
			{
			printf("Enter the name: ");
			scanf(" %[^\n]",str);
			int arr[30],count;
			res=Search_name(str,addressBook,arr,&count);
                        if(res==0)
                        {
                                printf("Contact not found\n");
                                return;
                        }
                        if(count==1)
                        {
                                idx=arr[0];
				printf("------------------------------------------------------\n");
				printf("Name: %s\n", addressBook->contacts[idx].name);
                                printf("Phone: %s\n", addressBook->contacts[idx].phone);
                                printf("Email: %s\n", addressBook->contacts[idx].email);
				printf("------------------------------------------------------\n");
                                printf("Do you really wanted to delete this contact(y/n or Y/N): ");
                                char ch;
                                scanf(" %c",&ch);
                                if(ch=='y' || ch=='Y')
                                {
                                        for(int i=idx;i<addressBook->contactCount-1;i++)
                                        {
                                                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                                        }
                                        addressBook->contactCount--;
                                        printf("------------------------------------------------------\n");
                                        printf("Contact deleted successfully\n");
                                        printf("------------------------------------------------------\n");
                                }
                        }
                        else
                        {
                                printf("Multiple contacts are found with this name, enter phone number to confirm name: ");
                                char phone_confirm[30];
                                scanf(" %[^\n]",phone_confirm);

                                for(int i=0;i<count;i++)
                                {
                                        if(strcmp(phone_confirm,addressBook->contacts[arr[i]].phone)==0)
                                        {
                                                idx=arr[i];
                                                break;
                                        }
                                }
				printf("------------------------------------------------------\n");
                                printf("Name: %s\n", addressBook->contacts[idx].name);
                                printf("Phone: %s\n", addressBook->contacts[idx].phone);
                                printf("Email: %s\n", addressBook->contacts[idx].email);
                                printf("------------------------------------------------------\n");
                                printf("Do you really wanted to delete this contact(y/n or Y/N): ");
                                char ch;
                                scanf(" %c",&ch);
                                if(ch=='y' || ch=='Y')
                                {
                                        for(int i=idx;i<addressBook->contactCount-1;i++)
                                        {
                                                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                                        }
                                        addressBook->contactCount--;
                                        printf("------------------------------------------------------\n");
                                        printf("Contact deleted successfully\n");
                                        printf("------------------------------------------------------\n");
                                }
                                if(idx==-1)
                                {
                                        printf("No contact matches that phone number\n");
                                }
                        }
                        break;
                        }
		case 2:
			printf("Enter the phone no: ");
                        scanf(" %[^\n]",str);
                        res=Search_phone(str,addressBook);
			if(res!=-1)
			{
				printf("------------------------------------------------------\n");
                                printf("Name: %s\n", addressBook->contacts[res].name);
	               	   	printf("Phone: %s\n", addressBook->contacts[res].phone);
                                printf("Email: %s\n", addressBook->contacts[res].email);
                                printf("------------------------------------------------------\n");
				printf("Do you really wanted to delete this contact(y/n or Y/N): ");
				char ch;
				scanf(" %c",&ch);
				if(ch=='y' || ch=='Y')
				{
					for(int i=res;i<addressBook->contactCount-1;i++)
					{
							addressBook->contacts[i] = addressBook->contacts[i + 1];
					}
					addressBook->contactCount--;
					printf("------------------------------------------------------\n");
					printf("Contact deleted successfully\n");
					printf("------------------------------------------------------\n");
				}
			}
			else
			{
				printf("Contact not found\n");
			}
                        break;
                case 3:
                        printf("Enter the email: ");
                        scanf(" %[^\n]",str);
                        res=Search_email(str,addressBook);
			if(res!=-1)
                        {
                                printf("------------------------------------------------------\n");
                                printf("Name: %s\n", addressBook->contacts[res].name);
                                printf("Phone: %s\n", addressBook->contacts[res].phone);
                                printf("Email: %s\n", addressBook->contacts[res].email);
                                printf("------------------------------------------------------\n");
                                printf("Do you really wanted to delete this contact(y/n or Y/N): ");
                                char ch;
                                scanf(" %c",&ch);
                                if(ch=='y' || ch=='Y')
                                {
                                        for(int i=res;i<addressBook->contactCount-1;i++)
                                        {
                                                        addressBook->contacts[i] = addressBook->contacts[i + 1];
                                        }
                                        addressBook->contactCount--;
                                        printf("------------------------------------------------------\n");
                                        printf("Contact deleted successfully\n");
                                        printf("------------------------------------------------------\n");
                                }
                        }
                        else
                        {
                                printf("Contact not found\n");
                        }
                        break;
		default:
			printf("Invalid option\n");
	}
   
}
int validate_name(char name[])
{
	//check alpha or not
	for(int i=0;name[i]!='\0';i++)
	{
		if(!((name[i]>='A' && name[i]<='Z')|| (name[i]>='a' && name[i]<='z') ||(name[i]==' ')))
			return 0;
	}
	return 1;
}
int validate_phone(char phone[],AddressBook* addressBook)
{
	int count=0;
	for(int i=0;phone[i]!='\0';i++)
		count++;
	if(count!=10)
		return 1;
	for(int i=0;phone[i]!='\0';i++)
	{
		if(!(phone[i]>='0' && phone[i]<='9'))
			return 2;
	}
	for(int i=0;i<addressBook->contactCount;i++)
	{
		if(strcmp(phone,addressBook->contacts[i].phone)==0)
			return 3;
	}
	return 0;
}
int validate_email(char email[],AddressBook* addressBook)
{
	int f1=0,f2=0;   //check @ and . is present or not
	for(int i=0;email[i]!='\0';i++)
	{
		if(email[i]=='@')
			f1++;
		if(email[i]=='.')
			f2++;
	}
	if(f1!=1 || f2!=1)
	{
		return 1;
	}
	int ch=0; //check for any character in between @ and .
	for(int i=0;email[i]!='\0';i++)
        {
                if(email[i]=='@')
		{
			int j=i+1;
			while(email[j]!='.' && email[j]!='\0')
			{
				if((email[j]>='A' && email[j]<='Z') || (email[j]>='a' && email[j]<='z') || (email[j]>='0' && email[j]<='9'))
				ch++;
				j++;
			}
			if(email[j]=='\0')
				return 2;
		}
        }
	if(ch==0)
	{
		return 3;
	}
	int c=0; //check any character is present after . or not
	for(int i=0;email[i]!='\0';i++)
	{
		if(email[i]=='.')
		{
			if(email[i+1]!='\0')
			{
				c++;
			}
			break;
		}
	}
	if(c==0)
	{
		return 4;
	}
	for(int i=0;i<addressBook->contactCount;i++)
        {
                if(strcmp(email,addressBook->contacts[i].email)==0) //check email is unique or not
                        return 5;
        }
	return 0;	
}
int Search_name(const char *name, AddressBook *addressbook,int arr[],int* count)
{
    *count = 0;   
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(name, addressbook->contacts[i].name) == 0)
        {
            arr[*count] = i;
            (*count)++;
        }
    }
    return (*count>0)?1:0;
}
int Search_phone(const char *phone, AddressBook *addressbook)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(phone, addressbook->contacts[i].phone) == 0)
        {
            return i;
        }
    }
    return -1;
}

int Search_email(const char *email, AddressBook *addressbook)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(email, addressbook->contacts[i].email) == 0)
	{
            return i;
        }
    }
    return -1;
}
