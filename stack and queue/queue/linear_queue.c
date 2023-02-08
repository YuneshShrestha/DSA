#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 4

struct linearQueue{
    int front,rear;
    int items[size]; 
};

void enqueue(struct linearQueue *q){
    if(q->rear == size-1){
        printf("Queue is full\n");
    }
    else{
        int val;
        scanf("%d",&val);
        q->rear+=1;
        q->items[q->rear] = val;

        printf("Successfully Added\n");
    }
}
// Without shift dequeue
void withoutShiftDequeue(struct linearQueue *q){
    if(q->front > q->rear){
        printf("Queue is empty.\n");
    }
    else{
        printf("%d was deleted\n",q->items[q->front]);
        q->front++;
    }
}
// Without shift dequeue

void shiftDequeue(struct linearQueue *q){
   if (q->rear < q->front) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front + 1; i <= q->rear; i++) {
        q->items[i-1] =   q->items[i];
    }
    q->rear--;
}

void display(struct linearQueue q){
    if (q.rear < q.front)
        printf("Queue is empty\n");
    else
    {
        for (int i = q.front; i <= q.rear; i++){
            printf("%d\n", q.items[i]);
        }    
    }
}

int main(){
    struct linearQueue q;
    int flag =1;
    q.front = 0;
    q.rear = -1;
    int choice;
    while(flag){
        system("cls");
        printf("1.Enqueue\n");
        printf("2.without Shift Dequeue\n");
        printf("3.with shift Dequeue\n");

        printf("4.Display\n");
  

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            withoutShiftDequeue(&q);
            break;
        case 3:
            shiftDequeue(&q);
            break;
        case 4:
            display(q);
            break;
        
        default:
            printf("Don't act fool.\n");
            break;
        }
        printf("Press 1 to continue & 0 to exit:\n");
        scanf("%d",&flag);
    }
    return 0;
}