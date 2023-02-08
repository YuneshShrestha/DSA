#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 4
// circular queue stores only size -1 elements that is 3 for this case. We will not show data of front.

struct circularQueue{
    int front,rear;
    int items[size]; 
};

void enqueue(struct circularQueue *q){
    if((q->rear + 1)%size == q->front){
        printf("Queue is full\n");
    }
    else{
        if(q->front==-1)
            q->front=0;
        int val;
        scanf("%d",&val);
        q->rear = (q->rear+1)%size;
        q->items[q->rear]=val;
        printf("Successfully Added\n");
    }
}

void dequeue(struct circularQueue *q){
   if (q->rear == q->front) {
        printf("Queue is empty\n");
        
    }
    else{
        q->front = (q->front + 1)%size;
    }
}

void display(struct circularQueue q){
    if (q.front == q.rear)
        printf("Queue is empty\n");
    else
    {
        printf("Items: ");
        for (int i = q.front + 1; i <= q.rear; i++){
            printf("%d\t", q.items[i]);
        }    
    }
}

int main(){
    struct circularQueue q;
    int flag =1;
    q.front = 0;
    q.rear = 0;
    int choice;
    while(flag){
        system("cls");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
  

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        
        default:
            printf("Don't act fool.\n");
            break;
        }
        printf("\nPress 1 to continue & 0 to exit:\n");
        scanf("%d",&flag);
    }
    return 0;
}