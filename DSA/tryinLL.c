#include<stdio.h>
#include<stdlib.h>
// #include<LLwork>

struct node{
    int data;
    struct node*add;
};
struct node *start,*temp,*new1,*prev,*next;

void create(){
int n;
printf("ENTER ELEMENT TO ENTER\n");
scanf("%d",&n);

start=(struct node*)malloc(sizeof(struct node));
start->data=n;
start->add=NULL;

temp=start;

char ch;
printf("WANNA ENTER NEXT ELEMENT?\n");
ch=getche();
while(ch=='y'){
    printf("\nENTER ELEMENT TO ENTER\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;

    temp->add=new1;
    temp=temp->add;
    printf("\nWANNA ENTER NEXT ELEMENT AGAIN?\t");
    ch=getche();
}
};

void display(){
    if(start==NULL){
        printf("EMPTY LIST\n");
    }
    else{
        temp=start;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->add;
        }
    }
};

void istFst(){
    int n;
    printf("\nENTER DATA TO INSERT AT FIRST\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    
    new1->add=start;

    start=new1;
};

void istLst(){
    int n;
    printf("enter element to insert in last\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;

    temp=start;
    while(temp->add!=NULL){
        temp=temp->add;
    }
    temp->add=new1;
};

void istMdl(){
    int n,pos,i;
    temp=start;



    printf("ENTER ELEMENT TO ENTER AT MIDDLE\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;

    printf("enter position\n");
    scanf("%d",&pos);

    for(i=1;i<=pos;i++){
        prev=temp;
        temp=temp->add;
    }
    prev->add=new1;
    new1->add=temp;

};

void dltFst(){

    temp=start;
    start=start->add;

    printf("\n%d deleated\n",temp->data);
    free(temp);
    
};

void dltLst(){
    temp=start;
    while(temp->add!=NULL){
        prev=temp;
        temp=temp->add;
    }
    printf("\n%d DELEATED\t",temp->data);
    free(temp);
    prev->add=NULL;
};

void dltMdl(){
    int i,pos;
    temp=start;

    printf("\nENTER POSITION:");
    scanf("%d",&pos);

    for(i=1;i<pos;i++){
        prev=temp;
        temp=temp->add;
    }
    next=temp->add;
    prev->add=next;
    printf("\n%d DELEATED\n",temp->data);
    free(temp);
}


int main(){
    create();
    // printf("NO ERROR\n");
    display();
    // istMdl();
    dltMdl();
    display();
return 0;
}