#include<stdio.h>
#include<stdlib.h>

#define MAX 3
int a[MAX];

int front=-1;
int rear=-1;


// int b=30;
// printf(if%d,b);

void eq(int data){
    if(rear==MAX-1){
        printf("QUEUE FULL\n");
        return;
    }
    else
    if(front==-1){
        front=0;
    }
    rear=rear+1;
    a[rear]=data;
    printf("data enqueued is %d\n",data);

}

void dq(){
    int data;
    if(front==-1 && rear==-1){
        printf("QUEUE EMPTY");
    }
    else{
        data=a[front];
        front=front+1;
        if(front==rear){
            front=-1;
            rear=-1;
        }
    printf("\n%d DELEATED\n",data);
    }
}

void display(){
    printf("ELEMENTS CURRENTLY ARE ");
    for(int i=front;i<=rear;i++){
        printf(">%d",a[i]);
    }

}


int main(){
    printf("EXECUTION STARTED FROM HERE\n");
    eq(1);
    eq(2);
    eq(3);
    display();
    dq();
    eq(5);
    display();
    return 0;
}