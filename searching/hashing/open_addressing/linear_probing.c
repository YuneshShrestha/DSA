#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
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
    int hashKey, val, i;
    printf("Enter the value: ");
    scanf("%d",&val);
    hashKey=val%SIZE;
    for (i = 0; i < SIZE; i++)
    { 
        hashKey=(hashKey+i)%SIZE;
        if(hashT[hashKey]==0)
        {
            hashT[hashKey]=val;
            printf("Data has been inserted.\n");
            break;
        }
    }
    if(i==SIZE)
    {
        printf("Element can't be inserted.");
    }
}
void search()
{
    int hashKey,i,n;
    printf("Value you want to search?: ");
    scanf("%d",&n);
    hashKey=n%SIZE;
    for (i = 0; i < SIZE; i++)
    { 
        hashKey=(hashKey+i)%SIZE;
        if(hashT[hashKey]==n)
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