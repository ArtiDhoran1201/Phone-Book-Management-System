#include"phone_book.h"
CONTACT *delete(CONTACT*head)
{
        printf("--------DELETE CONTACT--------\n");
        CONTACT *temp=head,*p=temp;
        char name[50];
        printf("enter the name:");
        scanf("%s",name);
        if(head==NULL)
        {
                printf("list is empty....\n");
        }
        else if(!(strcmp(name,head->name)))
        {
                temp=head;
                head=head->link;
                free(temp);
                printf("cantact deleted successfully...\n");
                return head;
        }
        else
        {
                temp=head;
                while(temp)
                {
                        if(!(strcmp(name,temp->name)))
                        {
                                p->link=temp->link;
                                free(temp);
                                printf("cantact deleted successfully...\n");
                                return head;
                        }
                        p=temp;
                        temp=temp->link;
                }
        }

}
void saveAccounts(CONTACT*head)
{
        printf("--------SAVE CONTACT--------\n");
        FILE *fp=NULL;
        fp=fopen("contact.txt","w");
        if(fp==NULL)
        {
                printf("invalid:");
                return;
        }
        else
        {
                int i=0;
                CONTACT*temp=NULL;
                temp=head;
                while(temp)
                {
                        fprintf(fp,"PERSON:%d:\n",i++);
                        fprintf(fp, "%s", temp->name);
                        for(int i=0;i<head->phoneCnt;i++)
                        {
                                fprintf(fp,"%s  ",temp->phone[i]);
                        }
                        for(int i=0;i<head->emailCnt;i++)
                        {
                                fprintf(fp,"%s  ",temp->email[i]);
                        }
                        fprintf(fp,"address:%s\n",temp->address);
                        temp=temp->link;
               }
        }
        fclose(fp);
        printf("store information successfully...\n");
}
CONTACT * edit(CONTACT* head)
{
        printf("--------EDIT CONTACT--------\n");
        CONTACT *temp=NULL;
        char name[20];
        printf("enter the name:");
        scanf("%s",name);
        if(head==NULL)
        {
                printf("list is empty....\n");
                return head;
        }
        else
        {
                temp=head;
                while(temp)
                {
                        if(!(strcmp(name,temp->name)))
                        {
                                printf("1 name 2.phone 3.add_another_no 4.email 5.add another email 6.edit_address\n");
                                int choice;
                                printf("enter the choice:");
                                scanf("%d",&choice);
                                switch(choice)
                                {
                                        case 1:{
                                                        char name[20];
                                                        printf("enter the name:");
                                                        scanf("%s",name);
                                                        strcpy(temp->name,name);
                                                        break;
                                                }
                                        case 2:{
                                                       int index;
                                                       printf("enter the index:");
                                                       scanf("%d",&index);
                                                       if(index>=0 &&index<temp->phoneCnt)
                                                       {
                                                                char phone[11];
                                                                printf("enter the phone no:");
                                                                scanf("%10s",phone);
                                                                strcpy(temp->phone[index],phone);
                                                       }
                                                       else
                                                       {
                                                               printf("invalid:\n");
                                                       }
                                                       break;
                                               }
                                        case 3:{
                                                       char phone[11];
                                                       if(temp->phoneCnt<MAX_PHONE)
                                                       {
                                                               printf("enter the phone no:");
                                                               scanf("%s",phone);
                                                               strcpy(temp->phone[temp->phoneCnt],phone);
                                                               temp->phoneCnt++;
                                                       }
                                                       else
                                                       {
                                                               printf("already 5 contact no acesss...\n");
                                                       }
                                                       break;
                                               }
                                        case 4:{
                                                       int index;
                                                       printf("enter the index:");
                                                       scanf("%d",&index);
                                                       if(index>=0 &&index<temp->emailCnt)
                                                       {
                                                                char email[50];
                                                                printf("enter the email:");
                                                                scanf("%s",email);
                                                                strcpy(temp->email[index],email);
                                                       }
                                                       else
                                                       {
                                                               printf("invalid:\n");
                                                       }
                                                       break;
                                               }
                                        case 5:{
                                                       char email[50];
                                                       if(temp->emailCnt<MAX_EMAIL)
                                                       {
                                                               printf("enter the email:");
                                                               scanf("%s",email);
                                                               strcpy(temp->email[temp->emailCnt],email);
                                                               temp->emailCnt++;
                                                       }
                                                       else
                                                       {
                                                               printf("already 5 email acesss...\n");
                                                       }
                                                       break;
                                               }
                                        case 6:{
                                                       char address[50];
                                                       printf("enter the addres:");
                                                       scanf("%[^\n]s",address);
                                                       strcpy(temp->address,address);
                                                       break;

                                               }
                                }
                        }
                        temp=temp->link;
                }
                return head;
        }
}
CONTACT *syncfile(CONTACT *head)
{
    FILE *fp;
    CONTACT *newnode, *temp;

    fp = fopen("contact.txt", "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return head;
    }

    while(1)
    {
        newnode = malloc(sizeof(CONTACT));

        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            break;
        }

        if(fscanf(fp, "%19s", newnode->name) != 1)
        {
            free(newnode);
            break;
        }

        fscanf(fp, "%d", &newnode->phoneCnt);

        if(newnode->phoneCnt < 0 || newnode->phoneCnt > MAX_PHONE)
        {
            free(newnode);
            break;
        }

        for(int i = 0; i < newnode->phoneCnt; i++)
        {
            fscanf(fp, "%10s", newnode->phone[i]);
        }

        fscanf(fp, "%d", &newnode->emailCnt);

        if(newnode->emailCnt < 0 || newnode->emailCnt > MAX_EMAIL)
        {
            free(newnode);
            break;
        }

        for(int i = 0; i < newnode->emailCnt; i++)
        {
            fscanf(fp, "%49s", newnode->email[i]);
        }

        fscanf(fp, " %[^\n]", newnode->address);

        newnode->link = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = newnode;
        }
    }

    fclose(fp);

    return head;
}
