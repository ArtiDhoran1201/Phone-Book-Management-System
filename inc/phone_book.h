#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#define MAX_PHONE 5
#define MAX_EMAIL 5
typedef struct Contact
{
    char name[50];

    char phone[MAX_PHONE][11];
    int phoneCnt;

    char email[MAX_EMAIL][50];
    int emailCnt;
    char address[100];
    struct Contact *link;
} CONTACT;
CONTACT *createContact(CONTACT *);
void print(CONTACT *);
void search(CONTACT *);
CONTACT *delete(CONTACT *);
void saveAccounts(CONTACT*);
CONTACT * edit(CONTACT *);
CONTACT *syncfile(CONTACT*);
