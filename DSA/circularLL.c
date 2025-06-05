#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*add;
};
struct node*start,*temp,*new1,*ptr,*prev,*next,*jkl;


void creation(){
int n;
char ch;
printf("\nENTER DATA\t");
scanf("%d",&n);

start=(struct node*)malloc(sizeof(struct node));
start->data=n;
start->add=start;

temp=start;


printf("\nWANT TO ENTER NEXT ELEMENT\n");
ch=getche();

while(ch=='y'){

    printf("\nENTER DATA\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=start;

    temp->add=new1;
    temp=new1;    
    printf("\nWANT AGAIN\t");
    ch=getche();
}
};

void display(){
    temp=start;
    printf("%d->",temp->data);
    while(temp->add!=start){
        temp=temp->add;
    printf("%d->",temp->data);
    }

};

void istFst(){
    int n;
    temp=start;
    ptr=start;

    while(ptr->add!=start){
        ptr=ptr->add;
    }

    printf("ENTER DATA FOR FIRSt\n");
    scanf("%d",&n);


    new1=(struct node*)malloc(sizeof(struct node*));
    new1->data=n;
    new1->add=temp;

    start=new1;
    ptr->add=start;
}

void istLst(){

    int n;
    temp=start;
    ptr=temp;

    printf("\nenter element to enter at last\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=start;

    while(temp->add!=start){
        temp=temp->add;
    }
    temp->add=new1;

}

void istMdl(){
    int pos,i,n;
    temp=start;
    // printf("TEMP KA DATA HAI %d",temp->data);

    printf("\nENTER ELEMENT FOR MIDDLE\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;

    printf("\nENTER POSITION\t");
    scanf("%d",&pos);



    for(i=1;i<pos;i++){
        temp=temp->add;
    }
    next=temp->add;
    // printf("\nTeMP KA DATA HAI %d",temp->data);
    // printf("\nnext KA DATA HAI %d",next->data);

    new1->add=next;
    temp->add=new1;
};

void dltFst(){
    temp=start;
    ptr=start;
    jkl=start;

    temp=temp->add;
    while(ptr->add!=start){
        ptr=ptr->add;
    }
    ptr->add=temp;
    start=temp;
    printf("\nVALUE DELEATING %d\n",jkl->data);
    free(jkl);
    
}

void dltLst(){
    ptr=start;
    temp=start;
    jkl=start;
    while(temp->add!=start){
        prev=temp;
        temp=temp->add;
    }
    prev->add=ptr;
    printf("\ndelete %d at last\n",temp->data);
    free(temp);
};

void dltMdl(){
    int i,pos;
    printf("\nENTER POSITION FOR DELETION\t");
    scanf("%d",&pos);
    
    temp=start;

    for(i=1;i<pos;i++){
        prev=temp;
        temp=temp->add;
    }
    next=temp->add;
    prev->add=next;
    printf("%d DELETED\n",temp->data);

    free(temp);

}


int main(){

    creation();
    display();
    dltMdl();
    display();
    printf("\nCODE SPRINTED\t");
}