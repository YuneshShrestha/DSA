#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *lcptr;
    struct node *rcptr;
    int height;
};
struct node *newnode, *newptr, *root=NULL, *parent, *ptr;
struct node *getptr(int data)
{
    newnode = (struct node *)malloc(sizeof(struct node));  
    newnode->info=data; 
    newnode->lcptr=NULL;
    newnode->rcptr=NULL;
    // For leaf node height is 1
    newnode->height=1; 
    return newnode;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(struct node *node) {
    if (node == NULL)
        return 0;
    return height(node->lcptr) - height(node->rcptr);
}

struct node *rightRotation(struct node *p){
    struct node *a=p->lcptr;
    struct node *ar=a->rcptr;
    a->rcptr=p;
    p->lcptr=ar;
    a->height=max(height(a->lcptr), height(a->rcptr))+1;
    p->height=max(height(p->lcptr), height(p->rcptr))+1;

    return a;
}
struct node *leftRotation(struct node *p){
    struct node *b=p->rcptr;
    struct node *bl=b->lcptr;
    p->rcptr=bl;
    b->lcptr=p;
     b->height=max(((b->lcptr != NULL) ? height(b->lcptr) : 0), ((b->rcptr != NULL) ? height(b->rcptr) : 0))+1;
    p->height=max(((p->lcptr != NULL) ? height(p->lcptr) : 0), ((p->rcptr != NULL) ? height(p->rcptr) : 0))+1;
    return b;
}
struct node *insert(struct node *n, int info){
    if(n==NULL)
        return getptr(info);
    if(info<n->info)
        n->lcptr=insert(n->lcptr, info);
    else if(info>n->info)
        n->rcptr=insert(n->rcptr, info);
    // This code will run from leaf node
    n->height = 1 + max(height(n->lcptr), height(n->rcptr));
    int bf = balanceFactor(n);
    // Left Left
    if(bf>1 && info < n->lcptr->info)
    {
        printf("Here");
        return rightRotation(n);
    }
    // Right Right
    if(bf<-1 && info > n->rcptr->info)
    {
        return leftRotation(n);
    }
    // Left Right
     if(bf>1 && info > n->lcptr->info)
    {
        n->lcptr=leftRotation(n->lcptr);
        return rightRotation(n);
    }
    // Right Left
     if(bf<-1 && info < n->rcptr->info)
    {
        n->rcptr=rightRotation(n->rcptr);
        return leftRotation(n);
    }
    return n;

}
void printTree(struct node *froot, int level) 
{
    if (froot == NULL) 
    {
        return;
    }
    printTree(froot->rcptr, level + 1);
    
    for (int i = 0; i < level; i++) 
    {
        printf("    ");
    }
    
    printf("%d\n", froot->info);
    
    printTree(froot->lcptr, level + 1);
}

int main()
{
    //  int flag=1, choice, val;
    // while (flag)
    // {
    //     system("cls");
    //     printf("1.Insert Data on AVL Tree\n2.Print AVL Tree");
    //     printf("Please Make Choice:\n");
    //     scanf("%d",&choice);
    //     switch (choice)
    //     {
    //     case 1:   
    //         creation();
    //         break;
    //     case 2:
    //         printf("AVL Tree: \n");
    //         printTree(root, 0);
    //         break;
    //     default:
    //         printf("DUMP DUMP DUMP DUMP DUMP");
    //         break;
    //     }
    //     printf("Do you want to continue program?(0/1): ");
    //     scanf("%d",&flag);
    // }
    root = insert(root,1);
    root = insert(root,2);

    root = insert(root,3);

    root = insert(root,4);
    printf("AVL Tree: \n");
    printTree(root,0);


    return 0;
}