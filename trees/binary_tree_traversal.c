#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lcptr;
    struct node *rcptr;
};

struct node *createBinaryTree(){
    int x;
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter a data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
        return 0;
    newNode->data=x;
    printf("Enter the left child of %d: ", x);
    newNode->lcptr=createBinaryTree();
    printf("Enter the right child of %d: ", x);
    newNode->rcptr=createBinaryTree();
    return newNode;
}    
int main()
{
    int flag=1, choice;
    struct node *root;
    root=0;
    while (flag)
    {
        system("cls");
        printf("1.Create Tree.\n");
        printf("Please Make Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:   
            root=createBinaryTree();
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