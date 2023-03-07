#include<stdio.h>
#include<stdlib.h>
int bf=0, isLeft=0;
struct node
{
    int info;
    struct node *lcptr;
    struct node *rcptr;
    int height;
};
struct node *newnode, *newptr, *root=NULL, *parent, *ptr, *temp=NULL, *tempParent=NULL;
struct node *getptr()
{
    newnode = (struct node *)malloc(sizeof(struct node));  
    printf("Enter Data: ");
    scanf("%d",&newnode->info); 
    newnode->lcptr=NULL;
    newnode->rcptr=NULL;
    return newnode;
};
int height(struct node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int balanceFactor(struct node *node) {
    if (node == NULL)
        return 0;
    return height(node->lcptr) - height(node->rcptr);
}
void findTheUnbalancedNode(struct node *froot)
{
    if(froot!=0)
    {
        findTheUnbalancedNode(froot->lcptr);
        findTheUnbalancedNode(froot->rcptr);
        if((balanceFactor(froot)>1 || balanceFactor(froot)<-1) && temp==NULL)
        {
            // printf("%d\n",froot->info);
            bf=balanceFactor(froot);
            temp=froot;
        }
        if(temp!=NULL)
        {
            if(froot->lcptr!=NULL && froot->lcptr->info==temp->info)
            {
                isLeft=1;
                tempParent=froot;
                
            }
            else if(froot->rcptr!=NULL && froot->rcptr->info==temp->info)
            {
                isLeft=0;
                tempParent=froot;
                
            }
        }
    }
}

void postorderHeightCalculation(struct node *froot)
{
    // Left Right root
    if(froot!=0)
    {
        postorderHeightCalculation(froot->lcptr);
        postorderHeightCalculation(froot->rcptr);
        if(froot->lcptr==NULL && froot->rcptr==NULL)
        {
            froot->height=1;
        }
        else if(froot->lcptr!=NULL && froot->rcptr==NULL)
        {
            froot->height=froot->lcptr->height+1;
        }
        else if(froot->rcptr!=NULL && froot->lcptr==NULL)
        {
            froot->height=froot->rcptr->height+1;
        }
        else
        {
            if (froot->rcptr->height>froot->lcptr->height)
            {
                froot->height=froot->rcptr->height+1;
            }
            else
            {
                froot->height=froot->lcptr->height+1;
            }
        }
    }
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
struct node *leftRotation(struct node *p)
{
    struct node *b=p->rcptr;
    struct node *bl=b->lcptr;
    p->rcptr=bl;
    b->lcptr=p;
    b->height=max(((b->lcptr != NULL) ? height(b->lcptr) : 0), ((b->rcptr != NULL) ? height(b->rcptr) : 0))+1;
    p->height=max(((p->lcptr != NULL) ? height(p->lcptr) : 0), ((p->rcptr != NULL) ? height(p->rcptr) : 0))+1;
    return b;
}

void creation(){
    int flag=1, isRoot=0;
  
    while(flag)
    {  
        newptr=getptr();
        ptr=root;
        if(root==NULL)
        {
            root=ptr=newptr;
           
        }
        else
        {
            while(ptr!=NULL)
            {
                parent=ptr;
                if(newptr->info<ptr->info)
                {
                    ptr=ptr->lcptr;
                }
                else if (newptr->info==ptr->info)
                {
                printf("No Duplicate Entry Allowed.\n");
                break;
                }
                else
                {
                    ptr=ptr->rcptr;
                }
            }
           if(ptr==NULL)
            {
                if(newptr->info<parent->info)
                {
                    parent->lcptr=newptr;
                }
                else
                {
                    parent->rcptr=newptr;
                }
                postorderHeightCalculation(root);
                findTheUnbalancedNode(root);
                if(temp!=NULL && (bf>1 || bf<-1))
                {
                    if(temp->info==root->info)
                        isRoot=1;
                    // Left Left
                    if(bf>1 && newptr->info < temp->lcptr->info)
                    {
                        temp=rightRotation(temp);
                    }
                    // Right Right
                    if(bf<-1 && newptr->info > temp->rcptr->info)
                    {
                        temp =leftRotation(temp);
                    }
                    // Left Right
                    if(bf>1 && newptr->info > temp->lcptr->info)
                    {
                        temp->lcptr=leftRotation(temp->lcptr);
                        temp =rightRotation(temp);
                    }
                    // Right Left
                    if(bf<-1 && newptr->info < temp->rcptr->info)
                    {
                        temp->rcptr=rightRotation(temp->rcptr);
                        temp =leftRotation(temp);
                    }
                    if(isRoot==1)
                    {
                        root=temp;
                        isRoot=0;
                    }
                    else
                    {
                        if(isLeft==1)
                        {
                            tempParent->lcptr=temp;
                            isLeft=0;
                        }
                        else
                        {
                            tempParent->rcptr=temp;
                            isLeft=0;
                        }
                        tempParent=NULL;
                    }
                    temp=NULL;
                }                  
            }
        }
        printf("Do you want to continue entering data? (0/1): ");
        scanf("%d", &flag);
    }
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
    printf("%d\n", froot->info, froot->height);    
    printTree(froot->lcptr, level + 1);
}


int main()
{
     int flag=1, choice, val;
    while (flag)
    {
        system("cls");
        printf("1.Create AVL\n2.Print AVL\n");
        printf("Please Make Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:   
            creation();
            break;
        case 2:
            printf("AVL Tree: \n");
            printTree(root, 0);
            break;
        default:
            printf("DUMP DUMP DUMP DUMP DUMP");
            break;
        }
        printf("Do you want to continue program?(0/1): ");
        scanf("%d",&flag);
    }

    return 0;
}