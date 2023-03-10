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
    // First calculate heght of p because a depends on height of p (i.e. a->rcptr=p)
    p->height=max(height(p->lcptr), height(p->rcptr))+1;
    // Then a
    a->height=max(height(a->lcptr), height(a->rcptr))+1;
    return a;
}
struct node *leftRotation(struct node *p){
    struct node *b=p->rcptr;
    struct node *bl=b->lcptr;
    b->lcptr=p;
    p->rcptr=bl;
    // First calculate heght of p because b depends on height of p (i.e. b->lcptr=p;)
    p->height=max(height(p->lcptr),height(p->rcptr))+1;
    // Then b
    b->height=max(height(b->lcptr), height(b->rcptr))+1;
    return b;
}
struct node *insert(struct node *n, int info){
    // if root then direct return with creation of new node
    if(n==NULL)
        return getptr(info);
    // Check recursively where the info data fits in a tree and return(i.e insert) only when the node has no adjacent vertices
    if(info<n->info)
        n->lcptr=insert(n->lcptr, info);
    else if(info>n->info)
        n->rcptr=insert(n->rcptr, info);
    else    
        return n;
    // This code will run from root node
    n->height = 1 + max(height(n->lcptr), height(n->rcptr));
    // printf("Height of %d: %d\n", n->info,n->height);
    int bf = balanceFactor(n);
    // Left Left
    if(bf>1 && info < n->lcptr->info)
    {
        // Make the head part
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
// inorder succesor means smallest value from right branch 
int inOrderSuccessor(struct node *r)
{
    int data;
    while (r!=NULL)
    {
       data=r->info;
       r=r->lcptr;
    }
    return data;
}

struct node *delete(struct node *n, int info){
    if(n==NULL)
    {
        return n;
    }
    if(n->info>info)
    {
        n->lcptr = delete(n->lcptr, info);
    }
    else if(n->info<info)
    {
        n->rcptr = delete(n->rcptr, info);
    }
    else
    {
         // If the node with matched value has either left child node or right child node or no child node
        if(n->rcptr==NULL || n->lcptr==NULL){
            // store the child in temp if no child store NULL
            struct node *temp = n->lcptr?n->lcptr:n->rcptr;
            // if child (i.e temp) is NULL you can directly delete the node
            if(temp==NULL)
            {
                // store the root in temp so that we can relase or free it from the memory later on
                temp=n;
                n=NULL;
            }
            // else replace the child with the parent (i.e the data to be deleted node)
            else    
                *n=*temp;
            free(temp);
        }
        // If the node with matched value has both child node
        else
        {
         int data=inOrderSuccessor(n->rcptr);
         n->info = data;
         n->rcptr=delete(n->rcptr, data);  
        }
    }
    // This hanldes when leaf nodes are deleted.
    if (n == NULL)
        return n;

    // This code will run from root node
    n->height = 1 + max(height(n->lcptr), height(n->rcptr));
    int bf = balanceFactor(n);
    // Left Left
    if(bf>1 && info < n->lcptr->info)
    {
        // Make the head part
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
void addData(){
    int flag=1, val;
    while (flag)
    {
        printf("Enter Data: ");
        scanf("%d",&val);
        // root =(because the data traverses from leaf node to root node so if the data changes after rotation at root node it[i.e. root=] deals with it)
        root = insert(root,val);
        printf("Do you want to continue adding data?(0/1): ");
        scanf("%d",&flag);
    }
}
void removeData(){
    int flag=1, val;
    while (flag)
    {
        system("cls");
        printf("AVL Tree: \n");
        printTree(root, 0);
        printf("\nEnter data you want to delete: ");
        scanf("%d",&val);
        // root =(because the data traverses from leaf node to root node so if the data changes after rotation at root node it[i.e. root=] deals with it)
        root = delete(root,val);
        printf("Do you want to continue deleting data?(0/1): ");
        scanf("%d",&flag);
    }
}
int main()
{
     int flag=1, choice, val;
    while (flag)
    {
        system("cls");
        printf("1.Insert New Node(AVL Tree)\n2.Print AVL Tree\n3.Delete Data\n");
        printf("Please Make Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:   
            addData();
            break;
        case 2:
            printf("AVL Tree: \n");
            printTree(root, 0);
            break;
        case 3:
            removeData();
            break;
        default:
            printf("DUMP DUMP DUMP DUMP DUMP");
            break;
        }
        printf("Do you want to continue program?(0/1): ");
        scanf("%d",&flag);
    }

    return 0;

    return 0;
}