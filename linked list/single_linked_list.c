#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head, *newNode, *temp;
void createLinkedList()
{
    int flag=1;
    head=NULL;
    while (flag)
    {
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

int main(){
    int flag=1,n;
   
    while(flag){
     system("cls");
        printf("1)Create New Linked List\n2)Traverse List\n3)Insert Data At First:\n4)Insert Data At Last:\n5)Insert Data At Anywhere:\nEnter Choice: ");
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
        default:
            printf("\nDon't Act Fool!\n");
        }   
        printf("\nPress 1 to continue & 0 to exit:\n");
        scanf("%d",&flag);
    }
 
    return 0;
}