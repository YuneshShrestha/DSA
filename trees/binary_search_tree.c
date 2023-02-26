#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *lcptr;
    struct node *rcptr;
};
struct node *newnode, *newptr, *root=NULL, *parent, *ptr;
struct node *getptr()
{
    newnode = (struct node *)malloc(sizeof(struct node));  
    printf("Enter Data: ");
    scanf("%d",&newnode->info); 
    newnode->lcptr=NULL;
    newnode->rcptr=NULL;
    return newnode;
};

void creation(){
    int flag=1;
  
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
                
            }
        }
        printf("Do you want to continue entering data? (0/1): ");
        scanf("%d", &flag);
    }
}
void insertData()
{
    newptr=getptr();
    ptr=root;
    if(root==NULL)
    {
        printf("Create BST first.");
        return;
    }
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
        
    }
    printf("Data has been inserted.\n");
        
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
void search()
{
    int data;
    printf("Enter the data you want to search:");
    scanf("%d",&data);
    ptr=root;
    while (ptr!=NULL && ptr->info!=data)
    {
       if(ptr->info<data)
       {
        ptr=ptr->rcptr;
       }
       else
       {
        ptr=ptr->lcptr;
       }
    }
    if(ptr!=NULL)
    {
        printf("%d data available at address %d.\n",ptr->info,ptr);
    }
    else
    {
        printf("Data not available.\n");
    }
}
int main()
{
     int flag=1, choice;
    while (flag)
    {
        system("cls");
        printf("1.Create BST\n2.Print BST\n3.Insert Data in BST\n4.Search Data\n");
        printf("Please Make Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:   
            creation();
            break;
        case 2:
            printf("BST: \n");
            printTree(root, 0);
            break;
        case 3:
            insertData();
            break;
        case 4:
            search();
            break;
        default:
            printf("DUM DUM DUM DUM DUM");
            break;
        }
        printf("Do you want to continue program?(0/1): ");
        scanf("%d",&flag);
    }

    return 0;
}