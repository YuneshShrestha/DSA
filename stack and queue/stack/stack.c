#include<stdio.h>
#include<stdlib.h>

#define size 4
struct stack
{
    int top;
    int items[size];
};
void push(struct stack *s)
{
    int element;
    if (s->top==size-1)
    {
       printf("Stack is full.\n");
    }
    else{
        s->top+=1;
        scanf("%d",&element);
        s->items[s->top]=element;
        printf("Successfully Added\n");
    }
}

void pop(struct stack *s){
    if (s->top<0)
    {
       printf("Stack is empty.\n");
    }
    else{
        printf("%d was popped.\n",s->items[s->top]);
        s->top-=1;
    }
}
int showItems(struct stack s){
     if(s.top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Items are:");
        for(int i = s.top;i>=0;i--){
            printf("%d\t",s.items[i]);
        }
    }
}

int main(){
    struct stack s;
    s.top=-1;
    int n;
    int flag=1;
   
    while(flag){
     system("cls");
        printf("1)Push\n2)Pop\n3)Show\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            showItems(s);
            break;
        default:
            printf("Don't Act Fool!");
        }   
        printf("Press 1 to continue & 0 to exit:");
        scanf("%d",&flag);
    }
    
    return 0;
}