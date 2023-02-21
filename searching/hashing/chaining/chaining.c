#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int hashT[SIZE];
struct node
{
    int data;
    struct node* next;
};
struct node *newNode, *head[SIZE]={NULL}, *temp;
// void initializeWithZero(){
//     for (int i = 0; i < SIZE; i++)
//     {
//         hashT[i]=0;
//     }
    
// }
void printTable(){
    for (int i = 0; i < SIZE; i++)
    {
        if(head[i]==NULL)
        {
            printf("Index: %d, Element: N/A",i);   
           
        }
        else
        {
            printf("Index: %d, Element: ",i);
            temp = head[i];
            if(temp!=NULL)
            {
                while (temp!=NULL)
                {
                    printf(" %d ",temp->data);
                    temp=temp->next;
                    if(temp!=NULL){
                        printf(" -> ");
                    }
                }
            }
        }
        printf("\n");
    }
}
void insertValue(){
    int hashKey, tempHashKey, val, i;
    printf("Enter the value: ");
    scanf("%d",&val);
    hashKey=val%SIZE;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    if(head[hashKey]==NULL)
    {
        head[hashKey]=newNode;
    }
    else
    {
        temp=head[hashKey];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Data Inserted.\n");
}
void search()
{
    int hashKey, tempHashKey, val, i;
    printf("Which value do you want to search?: ");
    scanf("%d",&val);
    hashKey=val%SIZE;
    if(head[hashKey]==NULL)
    {
        printf("Data not available!\n");
        return;
    }
    else
    {
        temp=head[hashKey];
        while(temp!=NULL && temp->data!=val)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Data not available!\n");
            return;       
        } 
        else
        {
            printf("Data available!\n");
        }
        
    }
}
int main()
{
   
    int flag=1, choice;
  //  initializeWithZero();
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
            printf("DUM DUM DUM DUM DUM\n");
            break;
        }
        printf("Do you want to continue?: ");
        scanf("%d",&flag);
    }
    
    return 0;
}