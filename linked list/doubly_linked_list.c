#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head, *newNode, *temp, *ptr;
struct node *getNode(){
   newNode=(struct node *)malloc(sizeof(struct node));
   printf("Enter Data: ");
   scanf("%d",&newNode->info);
   newNode->prev=NULL;
   newNode->next=NULL;
   return newNode;
}
void createLinkedList()
{
    int flag=1;
    head=NULL;
    while (flag)
    {
        ptr=getNode();
        if(head==NULL){
            head=temp=ptr;
        }
        else{
            temp->next=ptr;
            ptr->prev=temp;
            temp=ptr;
        }
        printf("Do you want to continue? (0/1): ");
        scanf("%d",&flag);
    }
};
void traverseLinkedList(){
    temp=head;
    if(head==NULL){
        printf("No Data Available!");
        return;
    }
    while (temp!=NULL)
    {
       printf("%d ",temp->info);
       temp=temp->next;
    }
}
void insertionAtFirst(){
    if(head==NULL){
        printf("No Data Available!");
        return;
    }
   ptr=getNode();
   ptr->next=head;
   head->prev=ptr;
   head=ptr;
   printf("Data has been inserted at first.");
}
void insertionAtLast(){
   if(head==NULL){
        printf("No Data Available!");
        return;
   }
   ptr=getNode();
   temp=head;
   while (temp->next!=NULL)
   {
        temp=temp->next;
   }
   temp->next=ptr;
   ptr->prev=temp;
   printf("Data has been inserted at last.");
}
void insertAtAnyWhere(){
  int key;
  temp=head;
  printf("After which data you want to insert?: ");
  scanf("%d",&key);
  while (temp->info!=key && temp!=NULL)
  {
    temp=temp->next;
  }
  if(temp==NULL){
    printf("Node doesn't exist.");
  }
  else{
    if(temp->next==NULL){
        insertionAtLast();
    }
    else{
        ptr=getNode();
        ptr->next= temp->next;
        temp->next=ptr;
        ptr->prev=temp;  
        (ptr->next)->prev=ptr;
        printf("Data has been inserted.");
    }
    
  }
 
}
void deletionAtFirst()
{
    
}
void deletionAtLast()
{
    
}
void deleteAnywhere()
{
}
void createAndMerge(){
    
}
void reverseLinkedList(){
}
int main(){
    int flag=1,n;
   
    while(flag){
     system("cls");
        printf("\n1)Create New Linked List\n2)Traverse List\n3)Insert Data At First:\n4)Insert Data At Last:\n5)Insert Data At Anywhere:\n6)Delete Element At First:\n7)Delete Element At Last:\n8)Delete Data At Anywhere:\n9)Create and merge new linked list:\n10)Reverse Linked List:\nEnter Choice: ");
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
            insertionAtFirst();
            break;
        case 4:
            insertionAtLast();
            break;
        case 5:
            insertAtAnyWhere();
            break;
        case 6:
            deletionAtFirst();
            break;
        case 7:
            deletionAtLast();
            break;
        case 8:
            deleteAnywhere();
            break;
        case 9:
            createAndMerge();
            break;
        case 10:
            reverseLinkedList();
            break;
        default:
            printf("\nDon't Act Fool!\n");
        }   
        printf("\nPress 1 to continue & 0 to exit: ");
        scanf("%d",&flag);
    }
 
    return 0;
}