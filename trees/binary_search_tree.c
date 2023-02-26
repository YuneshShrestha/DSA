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
// inorder succesor means smallest value from right branch 
int inorderSuccesor(struct node *r)
{
    int data;
    while (r!=NULL)
    {
       data=r->info;
       r=r->lcptr;
    }
    return data;
}
void delete(struct node *ptr, int key)
{
    while (ptr!=NULL && ptr->info!=key)
    {
        parent=ptr;
        if(key>ptr->info)
        {
            ptr=ptr->rcptr;
        }
        else
        {
            ptr=ptr->lcptr;
        }
    }
    if(ptr==NULL)
    {
        printf("Data not available.\n");
    }
    else
    {
        // Has no child
        if(ptr->lcptr==NULL && ptr->rcptr==NULL)
        {
            if(parent->info <key)
            {
                parent->rcptr=NULL;
            }
            else
            {
                parent->lcptr=NULL;
            }
            printf("Data has been deleted.\n");

        }
        // Has one child
        else if(ptr->lcptr==NULL || ptr->rcptr==NULL)
        {
            if(parent->info<key)
            {
                if(ptr->rcptr==NULL)
                {
                    parent->rcptr=ptr->lcptr;
                }
                else
                {
                    parent->rcptr=ptr->rcptr;
                }
            }
            else
            {
                if(ptr->rcptr==NULL)
                {
                    parent->lcptr=ptr->lcptr;
                }
                else
                {
                    parent->lcptr=ptr->rcptr;
                }
            }
            printf("Data has been deleted.\n");

        }
        // Has two child
        else
        {
            int del_data = inorderSuccesor(ptr->rcptr);
            // delete the inorderSuccesor element from the tree
            delete(root, del_data);
            // after deleting change the value of element to be deleted by inorderSuccesor element 
            ptr->info=del_data;
            printf("Data has been deleted.\n");
        }
    }
}

int main()
{
     int flag=1, choice, val;
    while (flag)
    {
        system("cls");
        printf("1.Create BST\n2.Print BST\n3.Insert Data in BST\n4.Search Data\n5.Delete Data\n");
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
        case 5:
            printf("Which value do you want to delete?:");
            scanf("%d",&val);
            delete(root,val);
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