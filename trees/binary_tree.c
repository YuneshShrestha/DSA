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
void preorder(struct node *root)
{
    // Root Left Right
    if(root!=0)
    {
        printf("%d ",root->data);
        preorder(root->lcptr);
        preorder(root->rcptr);
    }
    
}
void inorder(struct node *root)
{
    // Left Root Right
    if(root!=0)
    {
        inorder(root->lcptr);
        printf("%d ",root->data);
        inorder(root->rcptr);
    }
    
}
void postorder(struct node *root)
{
    // Left Right Root
    if(root!=0)
    {
        postorder(root->lcptr);
        postorder(root->rcptr);
        printf("%d ",root->data);
    }
}
void printTree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }
    
    printTree(root->rcptr, level + 1);
    
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    
    printf("%d\n", root->data);
    
    printTree(root->lcptr, level + 1);
}
int main()
{
    int flag=1, choice;
    struct node *root;
    root=0;
    while (flag)
    {
        system("cls");
        printf("1.Create Binary Tree.\n2.Pre-Order Traversal.\n3.In-Order Traversal.\n4.Post-Order Traversal.\n 5. Print tree.\n");
        printf("Please Make Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:   
            root=createBinaryTree();
            break;
        case 2:   
            printf("Pre-Order: ");
            preorder(root);
            break;
        case 3:   
            printf("In-Order: ");
            inorder(root);
            break;
        case 4:   
            printf("Post-Order: ");
            postorder(root);
            break;
        case 5:
            printf("Biinary Tree: \n");
            printTree(root, 0);
        default:
            printf("DUM DUM DUM DUM DUM");
            break;
        }
        printf("Do you want to continue?: ");
        scanf("%d",&flag);
    }
    return 0;
}