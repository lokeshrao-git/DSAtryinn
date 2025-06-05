#include<stdio.h>

/*
stack
push,pop,top
*/

int n;
scanf("%d",&n);


#define MAX_SIZE n
int stack[MAX_SIZE];
int top = -1;



//INSERTION
void push(int data){
    if(top==MAX_SIZE-1){
        printf("STACK OVERFLOW\n");
    }
    else{
        top=top+1;
        stack[top]=data;
        printf("\n%d INSERTED NEWLY\n",data);
    }
};

//DELETION
void pop(){
    int data;
    if(top == -1){
        printf("STACK UNDERFLOW\n");
    }
    else{
        data=stack[top];
        top=top-1;
        printf("\n%d DELEATED\n",data);
    }
};


//TRAVERSING AND DISPLAYING
void display(){
    if(top==-1){
        printf("STACK IS EMPTY<NOTHING TO PRINT\n");
    }
    else{
        printf("FINAL LIST IS:");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
    
};


int main(){

    push(90);
    display();
    push(97);
    display();
    pop();
    display();

    printf("\nEXITING FROM THE CODE");
    
    return 0;
}
