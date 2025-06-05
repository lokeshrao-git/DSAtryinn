#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 3
int QUEUE[MAX_SIZE];
int front=-1;
int rear=-1;

void enqueue(int data){
    
    if(rear==MAX_SIZE-1){
        printf("\nQUEUE OVERFLOW\n");
        return;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=rear+1;
        QUEUE[rear]=data;
    }
    printf("ENQUEUED %d:)\n",data);
};

void dequeue(){
    int data;
    if(front==-1 && rear==-1){
        printf("\nQUEUE UNDERFLOW\n");
        return;
    }

    data=QUEUE[front];

    if (front==rear){
    front=-1;
    rear=-1;
    }

    else{
    front+=1;
    printf("\nelement deleated %d\n",data);
    return;
    }
};

void display(){
    printf(">");

    if(front==-1 && rear==-1){
    printf("QUEUE UNDERFLOW\n");
    }

    for(int i=front;i<=rear;i++){
    printf("%d>",QUEUE[i]);
    }
};



int main(){
    printf("SUCCESFULLY EXECUTED\n");

    enqueue(1);enqueue(2);enqueue(3);
    display();
    dequeue();
    display();
    enqueue(4);
    
    return 0;
}