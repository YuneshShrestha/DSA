#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
// head to track the address of 1st node, newNode to create a new node and temp to move through each nodes while adding data 
struct node *head, *newNode, *temp, *anotherHead;
void createLinkedList()
{
    int flag=1;
    head=NULL;
    while (flag)
    {
        // malloc returns  the pointer to starting address of the memory block i.e void pointer
        // so you need to typecast is using (struct node *) and 
        // malloc takes an argument size in this case size of struct node
        newNode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newNode->info);
        newNode->next=NULL;
        if(head==NULL){
            head=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
        printf("Do you want to continue? (0/1): ");
        scanf("%d",&flag);
    }
};
void traverseLinkedList(){
    temp=head;
    if(head==NULL){
        printf("\nNo Data Available!\n");
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
        printf("\nNo Data Available!\n");
        return;
    }
    newNode= (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d",&newNode->info);
    newNode->next=head;
    head=newNode;
}
void insertionAtLast(){
    if(head==NULL){
        printf("\nNo Data Available!\n");
        return;
    }
    newNode= (struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Enter Data:");
    scanf("%d",&newNode->info);
    newNode->next=NULL;
    temp->next=newNode;
  
}
void insertAtAnyWhere(){
    if(head==NULL){
        printf("\nNo Data Available!\n");
        return;
    }
    int key;
    printf("After which data you want to store your new data?:");
    scanf("%d",&key);
    newNode=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL && temp->info!=key)
        temp=temp->next;
    if(temp==NULL)
    {
        printf("\nNode with the key doesn't exist.\n");
    }
    else{
      printf("Enter Data:");
      scanf("%d",&newNode->info);
      newNode->next=temp->next;
      temp->next=newNode;
    }
}
void deletionAtFirst()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nYour linked list is empty.\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("Element Deleted.");
    }
}
void deletionAtLast()
{
    struct node *temp, *prev_ptr;
    if(head==NULL)
    {
        printf("\nYour linked list is empty.\n");
    }
    else
    {
       temp=head;
       while (temp->next!=NULL)
       {
            prev_ptr=temp;
            temp=temp->next;
       }
       prev_ptr->next=NULL;
       free(temp);
       printf("Element Deleted.");
    }
}
void deleteAnywhere()
{
    struct node *temp, *prev_ptr;
   if(head==NULL){
        printf("\nNo Data Available!\n");
        return;
    }
    int key;
    printf("Which data you want to delete?:");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL && temp->info!=key)
    {
        prev_ptr=temp;
        temp=temp->next;
    }
        
    if(temp==NULL)
    {
        printf("\nNode with the key doesn't exist.\n");
    }
    else{
      prev_ptr->next= temp->next;
      free(temp);
      printf("Element Deleted.");
    }
}
void createAndMerge(){
    struct node *ptr;
    if(head==NULL){
        printf("Pick your choice as 1.");
    }
    else
    {

        // Creating
        anotherHead=NULL;
        int flag=1;
        while (flag)
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            printf("Enter Data: ");
            scanf("%d", &newNode->info);
            newNode->next=NULL;
            if(anotherHead==NULL){
                anotherHead=temp=newNode;
            }
            else{
                temp->next=newNode;
                temp=newNode;
            }
            printf("Do you want to continue? (0/1): ");
            scanf("%d",&flag);
        }
        // Merging
        ptr= head;
        while (ptr->next!=NULL)
        {
         ptr=ptr->next;
        }
        ptr->next=anotherHead;
    }
    
}
void reverseLinkedList(){

    struct node *prevnode, *currentnode, *nextnode;
    if(head==NULL){
        printf("Fill some data first.");
        return;
    }
    prevnode=NULL;
    currentnode=nextnode=head;
    while (nextnode!=NULL)
    {
     nextnode=currentnode->next;
     if(prevnode==NULL){
        currentnode->next=NULL;
        
     }   
     else
     {
        currentnode->next=prevnode;
     }
     prevnode=currentnode;
     currentnode=nextnode;
    }
    head=prevnode;
   
    printf("Linked List is reversed.");
}
int main(){
    int flag=1,n;
   
    while(flag){
     system("cls");
        printf("1)Create New Linked List\n2)Traverse List\n3)Insert Data At First:\n4)Insert Data At Last:\n5)Insert Data At Anywhere:\n6)Delete Element At First:\n7)Delete Element At Last:\n8)Delete Data At Anywhere:\n9)Create and merge new linked list:\n10)Reverse Linked List:\nEnter Choice: ");
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
        printf("\nPress 1 to continue & 0 to exit:\n");
        scanf("%d",&flag);
    }
 
    return 0;
}