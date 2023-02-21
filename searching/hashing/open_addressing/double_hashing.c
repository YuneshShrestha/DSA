#include<stdio.h>
#include<stdlib.h>
#define SIZE 11
int hashT[SIZE];
void initializeWithZero(){
    for (int i = 0; i < SIZE; i++)
    {
        hashT[i]=0;
    }
    
}
void printTable(){
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index: %d, Element: %d\n",i,hashT[i]);
    }
}
void insertValue(){
    int hashKey1, hashKey2, tempHashKey, val, i;
    printf("Enter the value: ");
    scanf("%d",&val);
    // SIZE prime hunu paro ra double hashed hunu paro jaslae garda kunai khali  space rahadaina
    // NOTE: Choosing a proper hash function for double hashing requires selecting two hash functions 
    // that produce different output values and that are relatively prime 
    hashKey1=val%SIZE;
    hashKey2=8-(val%8);
    for (i = 0; i < SIZE; i++)
    { 
        tempHashKey=(hashKey1+i*hashKey2)%SIZE;
        if(hashT[tempHashKey]==0)
        {
            hashT[tempHashKey]=val;
            printf("Data has been inserted.\n");
            break;
        }
    }
    if(i==SIZE)
    {
        printf("\nElement can't be inserted.");
    }
}
void search()
{
    int hashKey1, hashKey2,i,val, tempHashKey;
    printf("Value you want to search?: ");
    scanf("%d",&val);
    hashKey1=val%SIZE;
    hashKey2=8-(val%8);
    for (i = 0; i < SIZE; i++)
    { 
        tempHashKey=(hashKey1+i*hashKey2)%SIZE;
        if(hashT[tempHashKey]==val)
        {
            printf("Availabe!\n");
            break;
        }
    }
    if(i==SIZE)
    {
        printf("Not Available!\n");
    }
}
int main()
{
   
    int flag=1, choice;
    initializeWithZero();
    while (flag)
    {
        system("cls");
        printf("1.Enter the value\n2.Print table\n3.Search Value:\n");
        printf("Please Make Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertValue();
            break;
        case 2:
            printTable();
            break;
        case 3:
            search();
            break;
        default:
            printf("DUM DUM DUM DUM DUM");
            break;
        }
        printf("Do you want to continue?: ");
        scanf("%d",&flag);
    }
    
    return 0;
}