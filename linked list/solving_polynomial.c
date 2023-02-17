#include<stdio.h>
#include<stdlib.h>
struct function{
    int degree;
    int coefficient;
    struct function *next;
    
};
struct function *f1, *f2, *head1, *head2, *temp1, *temp2;
void enterFirstFunction()
{
    int flag=1;
    head1=NULL;
    printf("Enter the first function: \n");
    while(flag){
        f1=(struct function *)malloc(sizeof(struct function));
        printf("Enter Coefficient: ");
        scanf("%d",&f1->coefficient);
        printf("Enter Degree: ");
        scanf("%d",&f1->degree);
        f1->next=NULL;

        if(head1==NULL)
        {
            head1=temp1=f1;
        }
        else
        {
            temp1->next=f1;
            temp1=f1;
        }
        printf("Want to continue?(0 or 1): ");
        scanf("%d",&flag);
        
    }
}
void enterSecondFunction()
{
    int flag=1;
    head2=NULL;
    printf("Enter the second function: \n");
    while(flag){
        f2=(struct function *)malloc(sizeof(struct function));
        printf("Enter Coefficient: ");
        scanf("%d",&f2->coefficient);
        printf("Enter Degree: ");
        scanf("%d",&f2->degree);
        f2->next=NULL;
        if(head2==NULL)
        {
            head2=temp2=f2;
        }
        else
        {
            temp2->next=f2;
            temp2=f2;
        }
        printf("Want to continue?(0 or 1): ");
        scanf("%d",&flag);
    }
}
void printFunction(struct function *head){
    temp1=head;
    while(temp1!=NULL){
        printf("%dx^%d",temp1->coefficient, temp1->degree);
        temp1=temp1->next;
        if(temp1!=NULL){
            printf(" + ");
        }
    }
}
void addFunctions(){
    temp1=head1;
    temp2=head2;
    do
    {
        if(temp1->degree > temp2->degree){
           
            printf("%dx^%d",temp1->coefficient, temp1->degree);
            temp1=temp1->next;
        }

        else if(temp2->degree > temp1->degree){
            printf("%dx^%d",temp2->coefficient, temp2->degree);
            temp2=temp2->next;
        }
        else{
            printf("%dx^%d",temp1->coefficient+temp2->coefficient, temp2->degree);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1!=NULL && temp2!=NULL){
            printf(" + ");
        }
    }while(temp1!=NULL && temp2!=NULL);
    if(temp1!=NULL){
        do
        {
            if(temp1!=NULL){
                printf(" + ");
            }
            printf("%dx^%d",temp1->coefficient, temp1->degree);
            temp1=temp1->next;
            
        }while(temp1!=NULL);
    }
    if(temp2!=NULL){
        do
        {
            if(temp2!=NULL){
                printf(" + ");
            }
            printf("%dx^%d",temp2->coefficient, temp2->degree);
            temp2=temp2->next;
            
        }while(temp2!=NULL);
    }
}

int main(){
    enterFirstFunction();
    enterSecondFunction();
    // addFunctions();
    printf("First Function: ");
    printFunction(head1);
    printf("\n");
    printf("Second Function: ");
    printFunction(head2);
    printf("\n");

    printf("After addition: ");
    addFunctions();
    return 0;
}