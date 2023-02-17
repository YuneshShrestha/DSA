#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *nodeptr, *newptr, *last, *newNode, *temp, *anotherNodeptr;
struct node *getNode(){
   newNode=(struct node *)malloc(sizeof(struct node));
   printf("Enter Data: ");
   scanf("%d",&newNode->info);
   newNode->next=NULL;
   return newNode;
}
void createLinkedList()
{
    int flag=1;
    nodeptr=NULL;
    while (flag)
    {
        newptr=getNode();
        if(nodeptr==NULL)
        {
            nodeptr=newptr;
        }
        else
        {
            last->next=newptr;
        }
        last=newptr;
        last->next=nodeptr;
        printf("Do you want to continue? (0/1): ");
        scanf("%d",&flag);
    }
}
void traverseLinkedList(){
    temp=nodeptr;
    if(temp==NULL){
        printf("\nNo Data Available!\n");
        return;
    }
    printf("Data Availabe: ");
    do
    {
        printf("%d ",temp->info);
        temp=temp->next;
    } while (temp!=nodeptr);
    
}

void insertAtAnyWhere(){
   int key;
   if(nodeptr==NULL)
   {
    printf("No data available!");
    return;
   }
   temp=newNode;
   traverseLinkedList();
   printf("\n");
   printf("After which data you want to insert your new data?: ");
   scanf("%d",&key);
   while (temp!=NULL && key!=temp->info)
   {
    temp=temp->next;
   }
   if(temp==NULL)
   {
    printf("Data not found.");
    return;
   }
   newNode=getNode();
   newNode->next=temp->next;
   temp->next=newNode;   
   if(temp==last){
    last=temp->next;
   }
   printf("Data has been inserted.");
}
void deleteAnywhere()
{
   struct node *prevptr=NULL;
   int n;
   if(nodeptr==NULL){
    printf("Please enter some data first.");
    return;
   }
   traverseLinkedList();
   printf("\n");
   printf("Which data you want to delete?: ");
   scanf("%d",&n);
   temp=nodeptr;
   while (temp->info!=n && temp!=NULL)
   {
    prevptr=temp;
    temp=temp->next;
   }
   if(temp==NULL){
    printf("Data not found.");
    return;
   }
//    if 1st value is deleted
   if(temp==nodeptr)
   {
    // Checking of LL has single data
     if(nodeptr->next!=nodeptr)
     {
      nodeptr=nodeptr->next;
      last->next=nodeptr;
     }
     else{
        nodeptr=NULL;
        last=NULL;
     }
   }
   else
   {
     prevptr->next=temp->next;
   }
   free(temp);
}
void createAndMerge(){
    int flag=1;
    anotherNodeptr=NULL;
    // Creating
    while (flag)
    {
        newptr=getNode();
        if(anotherNodeptr==NULL)
        {
            anotherNodeptr=newptr;
        }
        else
        {
            last->next=newptr;
        }
        last=newptr;
        last->next=anotherNodeptr;
        printf("Do you want to continue? (0/1): ");
        scanf("%d",&flag);
    }
    // merging
    temp=anotherNodeptr->next;
    anotherNodeptr->next=nodeptr->next;
    nodeptr->next=temp;

}

int main(){
    int flag=1,n;
   
    while(flag){
     system("cls");
        printf("1)Create New Linked List\n2)Traverse List\n3)Insert Data At Anywhere:\n4)Delete Data At Anywhere:\n5)Create and Merge new:\nEnter Choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            createLinkedList();
            break;
        case 2:
            traverseLinkedList();
            break;
        case 3:
            insertAtAnyWhere();
            break;
        case 4:
            deleteAnywhere();
            break;
        case 5:
            createAndMerge();
            break;
        default:
            printf("\nDon't Act Fool!\n");
        }   
        printf("\nPress 1 to continue & 0 to exit:\n");
        scanf("%d",&flag);
    }
 
    return 0;
}