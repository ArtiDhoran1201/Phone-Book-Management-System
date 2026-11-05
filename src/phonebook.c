#include"phone_book.h"
CONTACT *createContact(CONTACT *head)
{
        printf("--------CREATE NEW Contact--------\n");
        CONTACT* newnode,*temp=NULL;
        newnode=calloc(1,sizeof(CONTACT));
        if(newnode==NULL)
        {
                printf("newnode is create\n");
                return head;
        }
        printf("enter the name:");
        scanf(" %s",newnode->name);
        printf("enter the phone number:");
        scanf("%s",newnode->phone[newnode->phoneCnt++]);
        newnode->phoneCnt=1;
        while(newnode->phoneCnt<MAX_EMAIL)
        {
                char ch;
                printf("enter the choice for new contact(Y/N):");
                __fpurge(stdin);
                scanf("%c",&ch);
                if(ch=='y'||ch=='Y')
                {
                        printf("enter the another phone no to the same contact:");
                        scanf("%s",newnode->phone[newnode->phoneCnt++]);
                }
                else if(ch=='N'||ch=='n')
                {
                        break;
                }
        }

        if(newnode->phoneCnt==5)
        {
                printf("5 number created for same contact\n");
        }
        printf("enter the email:");
        scanf("%s",newnode->email[newnode->emailCnt]);
        newnode->emailCnt=1;
        while(newnode->emailCnt<MAX_EMAIL)
        {
                char ch;
                printf("enter the choice for new email(Y/N):");
                __fpurge(stdin);
                scanf("%c",&ch);
                if(ch=='y'||ch=='Y')
                {
                        printf("enter the another email id to the same contact:");
                        scanf("%s",newnode->email[newnode->emailCnt++]);
                }
                else if(ch=='N'||ch=='n')
                {
                        break;
                }
        }
        if(newnode->emailCnt==5)
        {
                printf("5 email already created for same contact\n");
        }
        printf("enter the adress:");
        scanf("%s",newnode->address);
        if(head==NULL)
        {
                head=newnode;
        }
        else
        {
                temp=head;
                while(temp->link)
                {
                        temp=temp->link;
                }
                temp->link=newnode;
        }
        return head;
}
void print(CONTACT *head)
{
        printf("--------DISPLAY INFORMATION--------\n");
        if(head==NULL)
        {
                printf("list is empty...\n");
        }
        else
        {
                int i=1;
                while(head)
                {
                        printf("PERSON:%d:\n",i++);
                        printf("person name:%s\n",head->name);
                        printf("per_con_no:");
                        for(int i=0;i<head->phoneCnt;i++)
                        {
                                printf("%s  ",head->phone[i]);
                        }
                        printf("\n");
                        printf("email id:");
                        for(int i=0;i<head->emailCnt;i++)
                        {
                                printf("%s  ",head->email[i]);
                        }
                        printf("\n");
                        printf("address:%s\n",head->address);
                        head=head->link;
                }
        }
}
void search(CONTACT *head)
{
        printf("--------SEARCH CONATCT--------\n");
        char name[50];
        if(head==NULL)
        {
                printf("list is empty:");
        }
        else
        {
                printf("enter the name:");
                scanf("%s",name);
                while(head)
                {
                        if(!(strcmp(name,head->name)))
                        {
                                printf("%s      ",head->name);
                                for(int i=0;i<head->phoneCnt;i++)
                                {
                                        printf("%s  ",head->phone[i]);
                                }
                                for(int i=0;i<head->emailCnt;i++)
                                {
                                        printf("%s  ",head->email[i]);
                                }
                                printf("%s\n",head->address);
                        }

                        head=head->link;
                }
        }
}
