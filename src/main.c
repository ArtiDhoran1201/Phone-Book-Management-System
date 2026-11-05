#include"phone_book.h"
int main()
{
        CONTACT *head=NULL;
        char choice;
        while(1)
        {
                printf("c .createContact p.print f.search  d.delete  s.save e.edit  r.exit\n");
                printf("enter the choice:");
                scanf(" %c",&choice);
                switch(choice)
                {
                        case'c':head=createContact(head);
                                break;
                        case'p':print(head);
                                break;
                        case'f':search(head);
                                break;
                        case'd':head=delete(head);
                                break;
                        case's':saveAccounts(head);
                                break;
                        case'e':head=edit(head);
                                break;
                        case'l':head=syncfile(head);
                                break;
                        case'E':exit(0);
                }
        }
}
